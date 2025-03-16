/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "speaker-task/speaker_task.h"
#include "signal-processing-task/signal_processing.h"
#include "microphone-task/microphone_task.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for microphoneTask */
osThreadId_t microphoneTaskHandle;
const osThreadAttr_t microphoneTask_attributes = {
  .name = "microphoneTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for signalProcess */
osThreadId_t signalProcessHandle;
const osThreadAttr_t signalProcess_attributes = {
  .name = "signalProcess",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for speakerTask */
osThreadId_t speakerTaskHandle;
const osThreadAttr_t speakerTask_attributes = {
  .name = "speakerTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void _microphone_task(void *argument);
void _signal_processing_task(void *argument);
void _speaker_task(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of microphoneTask */
  microphoneTaskHandle = osThreadNew(_microphone_task, NULL, &microphoneTask_attributes);

  /* creation of signalProcess */
  signalProcessHandle = osThreadNew(_signal_processing_task, NULL, &signalProcess_attributes);

  /* creation of speakerTask */
  speakerTaskHandle = osThreadNew(_speaker_task, NULL, &speakerTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
//////  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header__microphone_task */
/**
  * @brief  Function implementing the microphoneTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header__microphone_task */
void _microphone_task(void *argument)
{
  /* USER CODE BEGIN _microphone_task */
  /* Infinite loop */
  microphone_task(argument);
  /* USER CODE END _microphone_task */
}

/* USER CODE BEGIN Header__signal_processing_task */
/**
* @brief Function implementing the signalProcess thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header__signal_processing_task */
void _signal_processing_task(void *argument)
{
  /* USER CODE BEGIN _signal_processing_task */
  /* Infinite loop */
  signal_processing_task(argument);
  /* USER CODE END _signal_processing_task */
}

/* USER CODE BEGIN Header__speaker_task */
/**
* @brief Function implementing the speakerTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header__speaker_task */
void _speaker_task(void *argument)
{
  /* USER CODE BEGIN _speaker_task */
  /* Infinite loop */
  speaker_task(argument);
  /* USER CODE END _speaker_task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

