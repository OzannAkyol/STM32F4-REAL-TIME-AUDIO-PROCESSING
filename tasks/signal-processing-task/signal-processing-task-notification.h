#ifndef _SIGNAL_PROCESSING_TASK_NOTIFICATION_H_
#define _SIGNAL_PROCESSING_TASK_NOTIFICATION_H_

#include <stdbool.h>
#include "signal-processing-task-interface.h"

typedef bool (*NotificationHandlerSignalProcessing)(NotificationSignalProcessingTask_t*);

bool init_signal_processing_task_notification(void);
bool wait_signal_processing_task_notification(NotificationSignalProcessingTask_t* ntf);

#endif