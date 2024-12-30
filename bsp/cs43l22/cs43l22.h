#ifndef _CS43L22_
#define _CS43L22_

#include "gpio.h"
#include "i2c.h"
#include "stdbool.h"

#define CS43L22_RESET_PIN		               (GPIO_PIN_4)
        
#define CS43L22_BASE_ADDRESS			       (0x94)
        
#define CS43L22_HEADPHONE_POWER_BIT            (0x01)           
#define CS43L22_CTRL1_REG_ADDR		           (0x02)
#define CS43L22_CTRL2_REG_ADDR                 (0x04)
#define CS43L22_IF_CTRL1_REG                   (0x06)
#define CS43L22_MISCEL_CTRL_REG		           (0x0E)
#define CS43L22_HP_A_VOLUME_CTRL               (0x22)
#define CS43L22_HP_B_VOLUME_CTRL               (0x23)
#define CS43L22_PLAYBACK_CTRL_REG              (0x0D)    
#define CS43L22_CLOCK_CTRL_REG                 (0x05)
#define CS43L22_ZC_SR_REG                      (0x0A)
#define CS43L22_REG_PLAYBACK_CTL2	           (0x0F)
#define CS43L22_TONE_CTRL_REG                  (0x1F)
#define CS43L22_PASSTHROUGH_A_REG              (0x14)
#define CS43L22_PASSTHROUGH_B_REG              (0x15) 
#define CS43L22_MASTER_VOLUME_A_CTRL           (0x20)
#define CS43L22_MASTER_VOLUME_B_CTRL           (0x21)
#define CS43L22_STATUS_REG			           (0x2E)
#define CS43L22_INIT_SEQ_REGISTER_1            (0x00)
#define CS43L22_INIT_SEQ_REGISTER_2            (0x47)
#define CS43L22_INIT_SEQ_REGISTER_3            (0x32)

#define I2C_TIMEOUT_DURATION_MS                (100)                
#define	CS43L22_REG_SIZE				       (1)

bool cs43l22_config();

#endif
