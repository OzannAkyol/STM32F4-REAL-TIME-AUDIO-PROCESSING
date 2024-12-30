#include <microphone-task/microphone_task.h>
#include <stdbool.h>
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os2.h"

#include "gpio.h"
#include "i2s.h"

#include "microphone-task-notification.h"
#include "signal-processing-task/signal-processing-task-notification.h"


uint32_t mic_buffer[MIC_BUFFER_SIZE] = {0};

static bool receive_raw_data(uint32_t* data, uint16_t size);
static inline void task_led_toggle(GPIO_TypeDef* gpio, uint16_t pin);
static inline void microphone_error_handler(void* arg);

const static NotificationHandlerMicrophoneTask ntf_handler[NUM_OF_MICROPHONE_TASK_FUNCTION];

void microphone_task(void *argument){

	if(!receive_raw_data(mic_buffer, MIC_BUFFER_SIZE)){
		microphone_error_handler(NULL);
	}

  for(;;)
  {
	  if(ulTaskNotifyTake(pdFALSE, portMAX_DELAY) != 0){
		  NotificationSignalProcessing_t ntf = {.id = NTF_COMPUTE_FIR_FILTER, .data = mic_buffer};
		  if(!signal_processing_task_notify(&ntf)){
		    microphone_error_handler(NULL);
		  }
	 }
  }
  
}

static inline void task_led_toggle(GPIO_TypeDef* gpio, uint16_t pin){
  HAL_GPIO_TogglePin(gpio, pin);
}

static bool receive_raw_data(uint32_t* data, uint16_t size){
  if(HAL_I2S_Receive_DMA(&hi2s2, (uint16_t*)data, size / 2) != HAL_OK){
    return false;
  }

  return true;
}

void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s){

	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	vTaskNotifyGiveFromISR(microphoneTaskHandle, &xHigherPriorityTaskWoken);

	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

}

static inline void microphone_error_handler(void* arg){
  (void)arg;
}