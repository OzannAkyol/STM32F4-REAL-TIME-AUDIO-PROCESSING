#include <stdbool.h>
#include "speaker-task-interface.h"

typedef bool (*NotificationSpeakerTaskHandler)(NotificationSpeakerTask_t*);

bool init_speaker_task_notification(void);
bool wait_speaker_task_notification(NotificationSpeakerTask_t* ntf);