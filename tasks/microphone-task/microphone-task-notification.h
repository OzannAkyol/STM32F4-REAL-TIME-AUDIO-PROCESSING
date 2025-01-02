#ifndef _MICROPHONE_TASK_NOTIFICATION_H__
#define _MICROPHONE_TASK_NOTIFICATION_H__

#include "microphone-task-interface.h"

typedef bool (*NotificationHandlerMicrophoneTask)(NotificationMicrophoneTask_t*);

bool init_microphone_task_notification(void);
bool wait_microphone_task_notification(NotificationMicrophoneTask_t* ntf);

#endif
