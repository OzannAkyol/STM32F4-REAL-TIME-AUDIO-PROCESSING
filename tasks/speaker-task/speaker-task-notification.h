#include <stdbool.h>

#define IS_VALID_SPEAKER_TASK_NOTIFICATION(ntf)             (ntf < NUM_OF_SPEAKER_TASK_FUNCTION)

typedef enum{
    NTF_SEND_SPEAKER_DATA,
    NUM_OF_SPEAKER_TASK_FUNCTION,
}NotificationIDSpeaker;

typedef struct{
    NotificationIDSpeaker id;
    void* data;
}NotificationSpeakerTask_t;

typedef bool (*NotificationSpeakerTaskHandler)(NotificationSpeakerTask_t*);

bool init_speaker_task_notification(void);
bool speaker_task_notify(NotificationSpeakerTask_t* ntf);
bool wait_speaker_task_notification(NotificationSpeakerTask_t* ntf);
