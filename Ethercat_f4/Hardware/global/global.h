#ifndef __GLOBAL_H
#define __GLOBAL_H 	
#include "stm32f4xx.h"

//void DAS_GPIO_Init(void);
void LED_Twinkle(void);
//void Amp_Set(int chn,int times);
//void EXTIX_Init(void);
//void TIM5_CH4_PWM_Init(int arr,int psc);

void Ethercat_irq_handle(void);
void Ethercat_sync0_handle(void);
void Ethercat_sync1_handle(void);

//#define G1_IN1_H       //GPIO_SetBits(GPIOC,GPIO_Pin_9)
//#define G1_IN2_H       //GPIO_SetBits(GPIOC,GPIO_Pin_8)
//#define G1_IN3_H      // GPIO_SetBits(GPIOC,GPIO_Pin_6)
//#define G1_IN4_H       //GPIO_SetBits(GPIOC,GPIO_Pin_7)

//#define G2_IN1_H      // GPIO_SetBits(GPIOD,GPIO_Pin_15)
//#define G2_IN2_H       //GPIO_SetBits(GPIOD,GPIO_Pin_14)
//#define G2_IN3_H       //GPIO_SetBits(GPIOD,GPIO_Pin_12)
//#define G2_IN4_H      // GPIO_SetBits(GPIOD,GPIO_Pin_13)

//#define G3_IN1_H      // GPIO_SetBits(GPIOD,GPIO_Pin_11)
//#define G3_IN2_H      // GPIO_SetBits(GPIOD,GPIO_Pin_10)
//#define G3_IN3_H      // GPIO_SetBits(GPIOD,GPIO_Pin_8)
//#define G3_IN4_H      // GPIO_SetBits(GPIOD,GPIO_Pin_9)

//#define G4_IN1_H      // GPIO_SetBits(GPIOB,GPIO_Pin_15)
//#define G4_IN2_H       //GPIO_SetBits(GPIOB,GPIO_Pin_14)
//#define G4_IN3_H       //GPIO_SetBits(GPIOB,GPIO_Pin_12)
//#define G4_IN4_H       //GPIO_SetBits(GPIOB,GPIO_Pin_13)

//#define G1_IN1_L       //GPIO_ResetBits(GPIOC,GPIO_Pin_9)
//#define G1_IN2_L       //GPIO_ResetBits(GPIOC,GPIO_Pin_8)
//#define G1_IN3_L      // GPIO_ResetBits(GPIOC,GPIO_Pin_6)
//#define G1_IN4_L      // GPIO_ResetBits(GPIOC,GPIO_Pin_7)

//#define G2_IN1_L       //GPIO_ResetBits(GPIOD,GPIO_Pin_15)
//#define G2_IN2_L       //GPIO_ResetBits(GPIOD,GPIO_Pin_14)
//#define G2_IN3_L       //GPIO_ResetBits(GPIOD,GPIO_Pin_12)
//#define G2_IN4_L      // GPIO_ResetBits(GPIOD,GPIO_Pin_13)

//#define G3_IN1_L       //GPIO_ResetBits(GPIOD,GPIO_Pin_11)
//#define G3_IN2_L       //GPIO_ResetBits(GPIOD,GPIO_Pin_10)
//#define G3_IN3_L       //GPIO_ResetBits(GPIOD,GPIO_Pin_8)
//#define G3_IN4_L       //GPIO_ResetBits(GPIOD,GPIO_Pin_9)

//#define G4_IN1_L       //GPIO_ResetBits(GPIOB,GPIO_Pin_15)
//#define G4_IN2_L       //GPIO_ResetBits(GPIOB,GPIO_Pin_14)
//#define G4_IN3_L       //GPIO_ResetBits(GPIOB,GPIO_Pin_12)
//#define G4_IN4_L       //GPIO_ResetBits(GPIOB,GPIO_Pin_13)

//#define G1_IN1(State)	HAL_GPIO_WritePin(AD_G1_IN1_GPIO_Port,AD_G1_IN1_Pin,(GPIO_PinState)State)
//#define G1_IN2(State)	HAL_GPIO_WritePin(AD_G1_IN2_GPIO_Port,AD_G1_IN2_Pin,(GPIO_PinState)State)
//#define G1_IN3(State)	HAL_GPIO_WritePin(AD_G1_IN3_GPIO_Port,AD_G1_IN3_Pin,(GPIO_PinState)State)
//#define G1_IN4(State)	HAL_GPIO_WritePin(AD_G1_IN4_GPIO_Port,AD_G1_IN4_Pin,(GPIO_PinState)State)

//#define G2_IN1(State)	HAL_GPIO_WritePin(AD_G2_IN1_GPIO_Port,AD_G2_IN1_Pin,(GPIO_PinState)State)
//#define G2_IN2(State)	HAL_GPIO_WritePin(AD_G2_IN2_GPIO_Port,AD_G2_IN2_Pin,(GPIO_PinState)State)
//#define G2_IN3(State)	HAL_GPIO_WritePin(AD_G2_IN3_GPIO_Port,AD_G2_IN3_Pin,(GPIO_PinState)State)
//#define G2_IN4(State)	HAL_GPIO_WritePin(AD_G2_IN4_GPIO_Port,AD_G2_IN4_Pin,(GPIO_PinState)State)

//#define G3_IN1(State)	HAL_GPIO_WritePin(AD_G3_IN1_GPIO_Port,AD_G3_IN1_Pin,(GPIO_PinState)State)
//#define G3_IN2(State)	HAL_GPIO_WritePin(AD_G3_IN2_GPIO_Port,AD_G3_IN2_Pin,(GPIO_PinState)State)
//#define G3_IN3(State)	HAL_GPIO_WritePin(AD_G3_IN3_GPIO_Port,AD_G3_IN3_Pin,(GPIO_PinState)State)
//#define G3_IN4(State)	HAL_GPIO_WritePin(AD_G3_IN4_GPIO_Port,AD_G3_IN4_Pin,(GPIO_PinState)State)

//#define G4_IN1(State)	HAL_GPIO_WritePin(AD_G4_IN1_GPIO_Port,AD_G4_IN1_Pin,(GPIO_PinState)State)
//#define G4_IN2(State)	HAL_GPIO_WritePin(AD_G4_IN2_GPIO_Port,AD_G4_IN2_Pin,(GPIO_PinState)State)
//#define G4_IN3(State)	HAL_GPIO_WritePin(AD_G4_IN3_GPIO_Port,AD_G4_IN3_Pin,(GPIO_PinState)State)
//#define G4_IN4(State)	HAL_GPIO_WritePin(AD_G4_IN4_GPIO_Port,AD_G4_IN4_Pin,(GPIO_PinState)State)

#endif





























