#include <stdbool.h>

#define IS_VALID_SIGNAL_TASK_NOTIFICATION(ntf)             (ntf < NUM_OF_SIGNAL_PROCESSING_TASK_FUNCTION)

typedef enum{
    NTF_COMPUTE_FIR_FILTER,
    NUM_OF_SIGNAL_PROCESSING_TASK_FUNCTION,
}NotificationIDSignalProcessing;

typedef struct{
    NotificationIDSignalProcessing id;
    void* data;
}NotificationSignalProcessing_t;

typedef bool (*NotificationHandlerSignalProcessing)(NotificationSignalProcessing_t*);

bool init_signal_processing_task_notification(void);
bool signal_processing_task_notify(NotificationSignalProcessing_t* ntf);
bool wait_signal_processing_task_notification(NotificationSignalProcessing_t* ntf);
