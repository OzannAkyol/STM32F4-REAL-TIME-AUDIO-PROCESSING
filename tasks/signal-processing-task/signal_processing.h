#ifndef _SIGNAL_PROCCESSING_
#define _SIGNAL_PROCESSING_
#include <stdbool.h>
#include "arm_math.h"

#define SIGNAL_PROCESSING_LED       GPIO_PIN_14
#define FIR_FILTER_NUM_TAPS         (31)
#define BLOCK_SIZE                  (256)

void signal_processing_task(void *argument);

extern float32_t fir_filter_output[BLOCK_SIZE];
/*alternative to 32 coefficient array

  -0.0007,  0.0002, -0.0002,  0.0000,  0.0001, -0.0004,  0.0006, -0.0008,  0.0009, -0.0008,  0.0006, -0.0003, -0.0002,  0.0007, -0.0012,  0.0016, -0.0018,  0.0016,
  -0.0012,  0.0005,  0.0005, -0.0015,  0.0024, -0.0031,  0.0033, -0.0031,  0.0022, -0.0009, -0.0008,  0.0026, -0.0043,  0.0054, -0.0058,  0.0053, -0.0038,  0.0015,
   0.0015, -0.0046,  0.0073, -0.0093,  0.0100, -0.0091,  0.0065, -0.0025, -0.0026,  0.0080, -0.0129,  0.0164, -0.0178,  0.0164, -0.0120,  0.0046,  0.0050, -0.0159,
   0.0266, -0.0354,  0.0405, -0.0399,  0.0317, -0.0137, -0.0176,  0.0705, -0.1762,  0.6243,  0.6243, -0.1762,  0.0705, -0.0176, -0.0137,  0.0317, -0.0399,  0.0405,
  -0.0354,  0.0266, -0.0159,  0.0050,  0.0046, -0.0120,  0.0164, -0.0178,  0.0164, -0.0129,  0.0080, -0.0026, -0.0025,  0.0065, -0.0091,  0.0100, -0.0093,  0.0073,
  -0.0046,  0.0015,  0.0015, -0.0038,  0.0053, -0.0058,  0.0054, -0.0043,  0.0026, -0.0008, -0.0009,  0.0022, -0.0031,  0.0033, -0.0031,  0.0024, -0.0015,  0.0005,
   0.0005, -0.0012,  0.0016, -0.0018,  0.0016, -0.0012,  0.0007, -0.0002, -0.0003,  0.0006, -0.0008,  0.0009, -0.0008,  0.0006, -0.0004,  0.0001,  0.0000, -0.0002,
   0.0002,   -0.0007,
};
*/
#endif
