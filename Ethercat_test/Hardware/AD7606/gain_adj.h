#ifndef __GAIN_ADJ_H__
#define __GAIN_ADJ_H__

#include "stm32f4xx_hal.h"

typedef enum
{
	AD_GAIN_X1 = 0u,
	AD_GAIN_X4 = 1u,
	AD_GAIN_X16 = 2u,
	AD_GAIN_X64 = 3u,
	AD_GAIN_X128 = 4u,
	AD_GAIN_X209 = 5u,
}AD_GAIN_ADJ_Rate;

//#if USE_AD_GAIN_ADJ
void AD_Amp_Set(int chn,AD_GAIN_ADJ_Rate times);
extern void AD_Amp_SetAll(void);


#endif
