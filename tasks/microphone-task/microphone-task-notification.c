#include "microphone-task-notification.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "microphone_task.h"

#define MICROPHONE_TASK_QUEUE_LEN          (16)

QueueHandle_t microphone_queue;

bool init_microphone_task_notification(void){
    microphone_queue = xQueueCreate(MICROPHONE_TASK_QUEUE_LEN, sizeof(NotificationMicrophoneTask_t));
    if(microphone_queue == NULL){
        return false;
    }
    return true;
}

bool microphone_task_notify(NotificationMicrophoneTask_t* ntf){
    if(ntf == NULL || microphone_queue == NULL){
        return false;
    }

    if(xQueueSend(microphone_queue, (void*)ntf, 0) == pdPASS){
        return true;
    }

    return false;

}

bool wait_microphone_task_notification(NotificationMicrophoneTask_t* ntf){
    
    if(ntf == NULL || microphone_queue == NULL){
        return false;
    }

    if(xQueueReceive(microphone_queue, mic_buffer, portMAX_DELAY) == pdPASS){
        if(IS_VALID_MICROPHONE_NOTIFICATION(ntf->id)){
            return true;
        }
        else{
            return false;
        }
    }
    
    return true;
}
