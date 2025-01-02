#ifndef MICROPHONE_TASK_INTERFACE_H
#define MICROPHONE_TASK_INTERFACE_H

#include <stdbool.h>

typedef enum{
    NTF_SEND_MICROPHONE_DATA,
    NUM_OF_MICROPHONE_TASK_FUNCTION,
}NotificationIDMicrophone;

typedef struct{
    NotificationIDMicrophone id;
    void* data;
}NotificationMicrophoneTask_t;

bool microphone_task_notify(NotificationMicrophoneTask_t* ntf);

#endif
