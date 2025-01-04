#ifndef _SIGNAL_PROCCESSING_
#define _SIGNAL_PROCESSING_
#include <stdbool.h>
#include "arm_math.h"

#define SIGNAL_PROCESSING_LED       GPIO_PIN_14
#define FIR_FILTER_NUM_TAPS         (31)
#define BLOCK_SIZE                  (256)

void signal_processing_task(void *argument);

#endif

