#ifndef _SIGNAL_PROCESSING_TASK_INTERFACE_H_
#define _SIGNAL_PROCESSING_TASK_INTERFACE_H_

#include <stdbool.h>

typedef enum{
    NTF_COMPUTE_FIR_FILTER,
    NUM_OF_SIGNAL_PROCESSING_TASK_FUNCTION,
}NotificationIDSignalProcessing;

typedef struct{
    NotificationIDSignalProcessing id;
    void* data;
}NotificationSignalProcessingTask_t;

bool signal_processing_task_notify(NotificationSignalProcessingTask_t* ntf);

#endif