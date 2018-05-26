#ifndef __AD7606_DRIVER_H__
#define __AD7606_DRIVER_H__

#include "stm32f4xx_hal.h"

//#define AD7606_SOFT_SPI //软件模拟SPI
#define AD_USE_RST 0//新板子有RST功能

/*
PC5 -O- OS 0							
PB0 -O- OS 1
PB1 -O- OS 2
RANGE		0:+/-5V 
PA3 -O- CONVST A&B					rising edge:start to convert
PC4 -O- _CS
PA4 -I- BUSY
PA2 -O- ICP_EN
*/

typedef enum
{
	AD_OS_NO = 0u,
	AD_OS_X2 = 1u,
	AD_OS_X4 = 2u,
	AD_OS_X8 = 3u,
	AD_OS_X16 = 4u,
	AD_OS_X32 = 5u,
	AD_OS_X64 = 6u
}AD7606_OS_Rate;

union _AD7606_BUF
{
	uint16_t shortbuf[4];
	uint8_t bytebuf[8];
};

//配置读取的通道
#define AD_CH1 1<<0
#define AD_CH2 1<<1
#define AD_CH3 1<<2
#define AD_CH4 1<<3

extern union _AD7606_BUF AD7606_BUF;

void AD7606_Init(void);
void AD7606_SetOsRate(AD7606_OS_Rate rate);
void AD7606_Read4CH(void);
void AD_CONVEST_PWM_Init(uint8_t f_khz);
void AD7606_handle(void);
void AD7606_rst(void);

extern void AD_rst_handle(void);//外部调用
extern uint8_t AD_CH_ctrl;//选择通道

#ifdef AD7606_SOFT_SPI
void AD7606_GPIO_SPI(void);
#endif

#endif

