#include <signal-processing-task/signal_processing.h>
#include "gpio.h"
#include "FreeRTOS.h"
#include "cmsis_os2.h"
#include "signal-processing-task-notification.h"
#include "speaker-task/speaker-task-notification.h"
#include <string.h>

/* Arm DSP Library includes */
#define ARM_MATH_CM4
#include "arm_math.h"

/* Arm DSP Library definitions */
arm_fir_instance_f32 fir_filter;
float32_t filter_state[FIR_FILTER_NUM_TAPS + BLOCK_SIZE + 1];
const float32_t filter_coeff[FIR_FILTER_NUM_TAPS] = {
	    -5434004720114.127f, 12065738670392.541f, -9461788000282.734f, -51024160050.35226f,
	    9033162239319.658f, -10804883483809.857f, 4440219822069.845f, 4729386326906.01f,
	    -9649417334845.072f, 7176856349671.372f, 198767825378.1905f, -6939204557391.346f,
	    8127831822003.124f, -2554926454615.1753f, -5663785040842.298f, 9574141392421.361f,
	    -5663785040842.298f, -2554926454615.1753f, 8127831822003.124f, -6939204557391.346f,
	    198767825378.1905f, 7176856349671.372f, -9649417334845.072f, 4729386326906.01f,
	    4440219822069.845f, -10804883483809.857f, 9033162239319.658f, -51024160050.35226f,
	    -9461788000282.734f, 12065738670392.541f, -5434004720114.127f
		};

float32_t fir_filter_input[BLOCK_SIZE] = {0};
float32_t fir_filter_output[BLOCK_SIZE] = {0};

static inline void task_led_toggle(GPIO_TypeDef* gpio, uint16_t pin);
static inline void init_FIR_filter();
static inline bool task_compute_FIR(NotificationSignalProcessing_t* ntf);

const static NotificationHandlerSignalProcessing ntf_handler[NUM_OF_SIGNAL_PROCESSING_TASK_FUNCTION] = {
  [NTF_COMPUTE_FIR_FILTER] = task_compute_FIR,
};

void signal_processing_task(void *argument){
  init_FIR_filter();

  for(;;)
  {
    NotificationSignalProcessing_t ntf;
    if(wait_signal_processing_task_notification(&ntf)){
      ntf_handler[ntf.id](&ntf);
    }
  }

}

static inline void task_led_toggle(GPIO_TypeDef* gpio, uint16_t pin){
    HAL_GPIO_TogglePin(gpio, pin);
}

static inline void init_FIR_filter(){
	arm_fir_init_f32(&fir_filter, FIR_FILTER_NUM_TAPS, filter_coeff, filter_state, BLOCK_SIZE);
}

static bool task_compute_FIR(NotificationSignalProcessing_t* ntf){
  if(ntf == NULL){
    return false;
  }  

  uint32_t* uint32_data = (uint32_t*)ntf->data;
  uint32_t tx_data[BLOCK_SIZE];

  for(size_t i = 0; i < BLOCK_SIZE; ++i){
	  fir_filter_input[i] = (float32_t)(int32_t)((uint32_data[i] >> 8));
  }

  arm_fir_f32(&fir_filter, fir_filter_input, fir_filter_output, BLOCK_SIZE);

  for(size_t i = 0; i < BLOCK_SIZE; ++i){
	  tx_data[i] = (uint32_t)((int32_t)(fir_filter_output[i] ) << 8);
  }

  NotificationSpeakerTask_t s_ntf = {.id = NTF_SEND_SPEAKER_DATA, .data = tx_data};
  
  return (speaker_task_notify(&s_ntf) == true);
}

