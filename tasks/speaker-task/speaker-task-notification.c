#include "speaker-task-notification.h"
#include "FreeRTOS.h"
#include "stream_buffer.h"
#include "speaker_task.h"

<<<<<<< HEAD
#define SPEAKER_TASK_QUEUE_LEN          (16)

QueueHandle_t speaker_queue;
=======
StreamBufferHandle_t speaker_task_stream_buffer;
>>>>>>> cf3cf2d (feat: change notification structure by replacing xQueue and xStreamBuffer)

bool init_speaker_task_notification(void){
    speaker_task_stream_buffer = xStreamBufferCreate(sizeof(NotificationSpeakerTask_t), 1);
    if(speaker_task_stream_buffer == NULL){
        return false;
    }
    return true;
}

bool speaker_task_notify(NotificationSpeakerTask_t* ntf){
    if(ntf == NULL || speaker_task_stream_buffer == NULL){
        return false;
    }

    if(xStreamBufferSend(speaker_task_stream_buffer, (void*)ntf, sizeof(NotificationSpeakerTask_t), 0) == pdPASS){
        return true;
    }

    return false;

}

bool wait_speaker_task_notification(NotificationSpeakerTask_t* ntf){
    
    if(ntf == NULL || speaker_task_stream_buffer == NULL){
        return false;
    }

    if(xStreamBufferReceive(speaker_task_stream_buffer, (void*)ntf, sizeof(NotificationSpeakerTask_t), portMAX_DELAY) == pdPASS){
        if(IS_VALID_SPEAKER_TASK_NOTIFICATION(ntf->id)){
            return true;
        }
        else{
            return false;
        }
    }
    
    return true;
}