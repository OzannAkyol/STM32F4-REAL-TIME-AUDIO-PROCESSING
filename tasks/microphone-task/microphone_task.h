#ifndef _MICROPHONE_TASK_
#define _MICROPHONE_TASK_


#include "stdint.h"

#define MICROPHONE_LED_PIN      GPIO_PIN_12
#define MIC_BUFFER_SIZE         (256)

void microphone_task(void *argument);

extern uint32_t mic_buffer[MIC_BUFFER_SIZE];

#endif
