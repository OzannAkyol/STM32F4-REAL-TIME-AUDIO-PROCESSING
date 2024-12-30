#include "cs43l22.h"

//TODO:this function will moved from main  
static inline bool cs43l22_gpio_init();
//TODO:This function will moved there from main
static inline bool cs43l22_i2c1_init(void);
static inline void cs43l22_reset();

inline void cs43l22_reset(){
  /* PD4 assign as a reset pin.*/
	HAL_GPIO_WritePin(GPIOD, CS43L22_RESET_PIN, GPIO_PIN_SET);
}

bool cs43l22_config(){
  uint8_t byte;

  /*Set high to reset signal.*/
  cs43l22_reset();

  /*Power Down)*/
  byte = 0x01;
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_CTRL1_REG_ADDR, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /*Five steps to apply required initialization.*/
  /* Step 1 */
  byte = 0x99;
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_INIT_SEQ_REGISTER_1, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /* Step 2 */
  byte = 0x81;
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_INIT_SEQ_REGISTER_2, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /* Step 3 */
  byte = 0x00;
  byte = (1 << 7);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_INIT_SEQ_REGISTER_3, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /* Step 4 */
  byte = 0x00;
  byte &= ~(1 << 7);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_INIT_SEQ_REGISTER_3, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /* Step 5 */
  byte = 0x00;
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_INIT_SEQ_REGISTER_1, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /* Power control*/
  byte = (0xEF);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_CTRL2_REG_ADDR, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;;

  /* Headphone analog gain control */
  byte = (0x50);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_PLAYBACK_CTRL_REG, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /*Clock control to auto detection */
  byte = (0x80);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_CLOCK_CTRL_REG, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /*Configure I2S standart*/
  byte = (0x14);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_IF_CTRL1_REG, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /*CS43L22_ZC_SR_REG*/
  byte = (0x02);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_ZC_SR_REG, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /*CS43L22_REG_MISC_CTL*/
  byte = (0x06);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_MISCEL_CTRL_REG, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

  /*Volume control*/
  byte = (0xC0);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS,  CS43L22_HP_A_VOLUME_CTRL, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

   /*Volume control*/
   byte = (0xC0);
   if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS,  CS43L22_HP_B_VOLUME_CTRL, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
     return false;

  /*Passthrough A volume */
  byte = (0x4F);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS,  CS43L22_PASSTHROUGH_A_REG, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

//   /*Passthrough B volume */
//   byte = (0x4F);
//   if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS,  CS43L22_PASSTHROUGH_B_REG, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
//     return false;

  /*Master volume A control*/
  byte = (0x18);
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS,  CS43L22_MASTER_VOLUME_A_CTRL, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
    return false;

//   /*Master volume B control*/
//   byte = (24);
//   if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS,  CS43L22_MASTER_VOLUME_B_CTRL, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK)
//     return false;

  /*Power up*/
  byte = 0x9E;
  if(HAL_I2C_Mem_Write(&hi2c1, CS43L22_BASE_ADDRESS, CS43L22_CTRL1_REG_ADDR, CS43L22_REG_SIZE, &byte, 1, I2C_TIMEOUT_DURATION_MS) != HAL_OK){
	  return false;
  }

  return true;
}

static inline bool cs43l22_gpio_init(){
    return true;
}

static inline bool cs43l22_i2c1_init(){
    return true;
}

