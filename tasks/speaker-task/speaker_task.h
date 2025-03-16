#ifndef _SPEAKER_TASK_
#define _SPEAKER_TASK_

#include <stdint.h>

#define SPEAKER_LED_PIN         GPIO_PIN_13
#define SPEAKER_BUFFER_SIZE		(32)

void speaker_task(void *argument);

extern uint32_t speaker_buffer[SPEAKER_BUFFER_SIZE];
#endif
