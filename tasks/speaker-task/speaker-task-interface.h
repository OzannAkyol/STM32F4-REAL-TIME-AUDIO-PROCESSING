/*
 * speaker-task-interface.h
 *
 *  Created on: Dec 30, 2024
 *      Author: oakyol
 */

#ifndef SPEAKER_TASK_SPEAKER_TASK_INTERFACE_H_
#define SPEAKER_TASK_SPEAKER_TASK_INTERFACE_H_

#include <stdbool.h>

typedef enum{
    NTF_SEND_SPEAKER_DATA,
    NUM_OF_SPEAKER_TASK_FUNCTION,
}NotificationIDSpeaker;

typedef struct{
    NotificationIDSpeaker id;
    void* data;
}NotificationSpeakerTask_t;

bool speaker_task_notify(NotificationSpeakerTask_t* ntf);


#endif /* SPEAKER_TASK_SPEAKER_TASK_INTERFACE_H_ */
