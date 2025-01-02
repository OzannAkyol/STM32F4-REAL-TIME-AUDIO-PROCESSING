#include "signal-processing-task-notification.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "signal_processing.h"

#define IS_VALID_SIGNAL_TASK_NOTIFICATION(ntf) (ntf < NUM_OF_SIGNAL_PROCESSING_TASK_FUNCTION)

#define SIGNAL_PROCESSING_TASK_QUEUE_LEN          (128)
QueueHandle_t signal_processing_queue;

bool init_signal_processing_task_notification(void){
    signal_processing_queue = xQueueCreate(SIGNAL_PROCESSING_TASK_QUEUE_LEN, sizeof(NotificationSignalProcessingTask_t));
    if(signal_processing_queue == NULL){
        return false;
    }
    return true;
}

bool signal_processing_task_notify(NotificationSignalProcessingTask_t* ntf){
    if(ntf == NULL || signal_processing_queue == NULL){
        return false;
    }

    if(xQueueSend(signal_processing_queue, (void*)ntf, 0) == pdPASS){
        return true;
    }

    return false;

}

bool wait_signal_processing_task_notification(NotificationSignalProcessingTask_t* ntf){
    
    if(ntf == NULL || signal_processing_queue == NULL){
        return false;
    }

    if(xQueueReceive(signal_processing_queue, (void*)ntf, portMAX_DELAY) == pdPASS){
        if(IS_VALID_SIGNAL_TASK_NOTIFICATION(ntf->id)){
            return true;
        }
        else{
            return false;
        }
    }
    
    return true;
}
