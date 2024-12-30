#include "speaker_task.h"
#include "gpio.h"
#include "cs43l22.h"

#include "FreeRTOS.h"
#include "queue.h"

#include "cmsis_os2.h"
#include "i2s.h"

#include "speaker-task-notification.h"

#include <string.h>

uint32_t speaker_buffer[SPEAKER_BUFFER_SIZE];

static inline void led_toggle_speaker_task(GPIO_TypeDef* gpio, uint16_t pin);
static bool play_audio(NotificationSpeakerTask_t* ntf);
static inline bool speaker_error_handler(void* arg);

const static NotificationSpeakerTaskHandler ntf_handler[NUM_OF_SPEAKER_TASK_FUNCTION] = {
    [NTF_SEND_SPEAKER_DATA] = play_audio,
};

void speaker_task(void* argument){
    if(!cs43l22_config()){
      speaker_error_handler(NULL); 
    }

    for(;;){
        NotificationSpeakerTask_t ntf;
        if(wait_speaker_task_notification(&ntf)){
            ntf_handler[ntf.id](&ntf);
        }
    }
}

static inline void led_toggle_speaker_task(GPIO_TypeDef* gpio, uint16_t pin){
    HAL_GPIO_TogglePin(gpio, pin);
}

static bool play_audio(NotificationSpeakerTask_t* ntf){
    if(ntf == NULL){
        return false;
    }

    if(HAL_I2S_Transmit_DMA(&hi2s3, (uint16_t*)ntf->data, SPEAKER_BUFFER_SIZE / 2) == HAL_OK){
        return true;
    }
    return false;
}

static inline bool speaker_error_handler(void* arg){
    (void)arg;
    return false;
}
