#include <stdbool.h>

#define IS_VALID_MICROPHONE_NOTIFICATION(ntf)             (ntf < NUM_OF_MICROPHONE_TASK_FUNCTION)

typedef enum{
    NTF_SEND_MICROPHONE_DATA,
    NUM_OF_MICROPHONE_TASK_FUNCTION,
}NotificationIDMicrophone;

typedef struct{
    NotificationIDMicrophone id;
    void* data;
}NotificationMicrophoneTask_t;

typedef bool (*NotificationHandlerMicrophoneTask)(NotificationMicrophoneTask_t*);

bool init_microphone_task_notification(void);
bool microphone_task_notify(NotificationMicrophoneTask_t* ntf);
bool wait_microphone_task_notification(NotificationMicrophoneTask_t* ntf);
