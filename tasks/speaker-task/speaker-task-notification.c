#include "speaker-task-notification.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "speaker_task.h"

#define SPEAKER_TASK_QUEUE_LEN          (16)

QueueHandle_t speaker_queue;

bool init_speaker_task_notification(void){
    speaker_queue = xQueueCreate(SPEAKER_TASK_QUEUE_LEN, sizeof(NotificationSpeakerTask_t));
    if(speaker_queue == NULL){
        return false;
    }
    return true;
}

bool speaker_task_notify(NotificationSpeakerTask_t* ntf){
    if(ntf == NULL || speaker_queue == NULL){
        return false;
    }

    if(xQueueSend(speaker_queue, (void*)ntf, 0) == pdPASS){
        return true;
    }

    return false;

}

bool wait_speaker_task_notification(NotificationSpeakerTask_t* ntf){
    
    if(ntf == NULL || speaker_queue == NULL){
        return false;
    }

    if(xQueueReceive(speaker_queue, (void*)ntf, portMAX_DELAY) == pdPASS){
        if(IS_VALID_SPEAKER_TASK_NOTIFICATION(ntf->id)){
            return true;
        }
        else{
            return false;
        }
    }
    
    return true;
}
