#include "signal-processing-task-notification.h"
#include "FreeRTOS.h"
#include "stream_buffer.h"
#include "signal_processing.h"

<<<<<<< HEAD
#define SIGNAL_PROCESSING_TASK_QUEUE_LEN          (128)

QueueHandle_t signal_processing_queue;

bool init_signal_processing_task_notification(void){
    signal_processing_queue = xQueueCreate(SIGNAL_PROCESSING_TASK_QUEUE_LEN, sizeof(NotificationSignalProcessing_t));
    if(signal_processing_queue == NULL){
=======
StreamBufferHandle_t signal_processing_stream_buffer;

bool init_signal_processing_task_notification(void){
    signal_processing_stream_buffer = xStreamBufferCreate(sizeof(NotificationSignalProcessing_t), 1);
    if(signal_processing_stream_buffer == NULL){
>>>>>>> cf3cf2d (feat: change notification structure by replacing xQueue and xStreamBuffer)
        return false;
    }
    return true;
}

bool signal_processing_task_notify(NotificationSignalProcessing_t* ntf){
<<<<<<< HEAD
    if(ntf == NULL || signal_processing_queue == NULL){
=======
    if(ntf == NULL || signal_processing_stream_buffer == NULL){
>>>>>>> cf3cf2d (feat: change notification structure by replacing xQueue and xStreamBuffer)
        return false;
    }

    if(xStreamBufferSend(signal_processing_stream_buffer, (void*)ntf, sizeof(NotificationSignalProcessing_t), 0) == pdPASS){
        return true;
    }

    return false;

}

bool wait_signal_processing_task_notification(NotificationSignalProcessing_t* ntf){
    
    if(ntf == NULL || signal_processing_stream_buffer == NULL){
        return false;
    }

    if(xStreamBufferReceive(signal_processing_stream_buffer, (void*)ntf, sizeof(NotificationSignalProcessing_t), portMAX_DELAY) == pdPASS){
        if(IS_VALID_SIGNAL_TASK_NOTIFICATION(ntf->id)){
            return true;
        }
        else{
            return false;
        }
    }
    
    return true;
}
