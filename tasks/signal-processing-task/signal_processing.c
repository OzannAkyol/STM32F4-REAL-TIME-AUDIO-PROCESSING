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
float32_t filter_state[FIR_FILTER_NUM_TAPS + BLOCK_SIZE - 1];
const float32_t filter_coeff[FIR_FILTER_NUM_TAPS] = {
		  -0.0018225230f, -0.0015879294f, +0.0000000000f, +0.0036977508f, +0.0080754303f, +0.0085302217f, -0.0000000000f, -0.0173976984f,
		  -0.0341458607f, -0.0333591565f, +0.0000000000f, +0.0676308395f, +0.1522061835f, +0.2229246956f, +0.2504960933f, +0.2229246956f,
		  +0.1522061835f, +0.0676308395f, +0.0000000000f, -0.0333591565f, -0.0341458607f, -0.0173976984f, -0.0000000000f, +0.0085302217f,
		  +0.0080754303f, +0.0036977508f, +0.0000000000f, -0.0015879294f, -0.0018225230f
		};

static float32_t fir_filter_input[BLOCK_SIZE] = {0};
static float32_t fir_filter_output[BLOCK_SIZE] = {0};

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

  memcpy(fir_filter_input, ntf->data, BLOCK_SIZE * sizeof(float32_t));

  arm_fir_f32(&fir_filter, fir_filter_input, fir_filter_output, BLOCK_SIZE);

  NotificationSpeakerTask_t s_ntf = {.id = NTF_SEND_SPEAKER_DATA, .data = fir_filter_output};
  
  return (speaker_task_notify(&s_ntf) == true);
}

