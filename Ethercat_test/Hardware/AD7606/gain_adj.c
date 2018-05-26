/**
 *************************************************************************************
 * @file gain_adj.c
 * @author liucongjun
 * @version 0.1
 * @date 
 * @brief INA826 可控增益
 *************************************************************************************
*/
#include "gain_adj.h"
#include "main.h"

#define G1_IN1(State)	HAL_GPIO_WritePin(AD_G1_IN1_GPIO_Port,AD_G1_IN1_Pin,(GPIO_PinState)State)
#define G1_IN2(State)	HAL_GPIO_WritePin(AD_G1_IN2_GPIO_Port,AD_G1_IN2_Pin,(GPIO_PinState)State)
#define G1_IN3(State)	HAL_GPIO_WritePin(AD_G1_IN3_GPIO_Port,AD_G1_IN3_Pin,(GPIO_PinState)State)
#define G1_IN4(State)	HAL_GPIO_WritePin(AD_G1_IN4_GPIO_Port,AD_G1_IN4_Pin,(GPIO_PinState)State)

#define G2_IN1(State)	HAL_GPIO_WritePin(AD_G2_IN1_GPIO_Port,AD_G2_IN1_Pin,(GPIO_PinState)State)
#define G2_IN2(State)	HAL_GPIO_WritePin(AD_G2_IN2_GPIO_Port,AD_G2_IN2_Pin,(GPIO_PinState)State)
#define G2_IN3(State)	HAL_GPIO_WritePin(AD_G2_IN3_GPIO_Port,AD_G2_IN3_Pin,(GPIO_PinState)State)
#define G2_IN4(State)	HAL_GPIO_WritePin(AD_G2_IN4_GPIO_Port,AD_G2_IN4_Pin,(GPIO_PinState)State)

#define G3_IN1(State)	HAL_GPIO_WritePin(AD_G3_IN1_GPIO_Port,AD_G3_IN1_Pin,(GPIO_PinState)State)
#define G3_IN2(State)	HAL_GPIO_WritePin(AD_G3_IN2_GPIO_Port,AD_G3_IN2_Pin,(GPIO_PinState)State)
#define G3_IN3(State)	HAL_GPIO_WritePin(AD_G3_IN3_GPIO_Port,AD_G3_IN3_Pin,(GPIO_PinState)State)
#define G3_IN4(State)	HAL_GPIO_WritePin(AD_G3_IN4_GPIO_Port,AD_G3_IN4_Pin,(GPIO_PinState)State)

#define G4_IN1(State)	HAL_GPIO_WritePin(AD_G4_IN1_GPIO_Port,AD_G4_IN1_Pin,(GPIO_PinState)State)
#define G4_IN2(State)	HAL_GPIO_WritePin(AD_G4_IN2_GPIO_Port,AD_G4_IN2_Pin,(GPIO_PinState)State)
#define G4_IN3(State)	HAL_GPIO_WritePin(AD_G4_IN3_GPIO_Port,AD_G4_IN3_Pin,(GPIO_PinState)State)
#define G4_IN4(State)	HAL_GPIO_WritePin(AD_G4_IN4_GPIO_Port,AD_G4_IN4_Pin,(GPIO_PinState)State)

// @ function: AD_Amp_Set
// @ description:
// @ input:chn(通道数),times(放大倍数)
// @ note:设置指定通道的信号放大倍数，chn=1-4，times=1,4,16,64,128,209(暂定，实际上放大倍数1-209之间多种组合)
void AD_Amp_Set(int chn,AD_GAIN_ADJ_Rate times)
{
	switch(chn)
	{
		case 1:
		{
			switch(times)
			{
				case AD_GAIN_X1:   {G1_IN1(1); G1_IN2(1); G1_IN3(1); G1_IN4(1); break;}//1,1,1,1
				case AD_GAIN_X4:   {G1_IN1(0); G1_IN2(1); G1_IN3(1); G1_IN4(1); break;}//0,1,1,1
				case AD_GAIN_X16:  {G1_IN1(1); G1_IN2(0); G1_IN3(1); G1_IN4(1); break;}//1,0,1,1
				case AD_GAIN_X64:  {G1_IN1(1); G1_IN2(1); G1_IN3(0); G1_IN4(1); break;}//1,1,0,1
				case AD_GAIN_X128: {G1_IN1(1); G1_IN2(1); G1_IN3(1); G1_IN4(0); break;}//1,1,1,0
				case AD_GAIN_X209: {G1_IN1(0); G1_IN2(0); G1_IN3(0); G1_IN4(0); break;}//0,0,0,0
				default:  {G1_IN1(1); G1_IN2(1); G1_IN3(1); G1_IN4(1); break;}//默认1倍
			}
		}
		case 2:
		{
			switch(times)
			{
				case AD_GAIN_X1:   {G2_IN1(1); G2_IN2(1); G2_IN3(1); G2_IN4(1); break;}//1,1,1,1
				case AD_GAIN_X4:   {G2_IN1(0); G2_IN2(1); G2_IN3(1); G2_IN4(1); break;}//0,1,1,1
				case AD_GAIN_X16:  {G2_IN1(1); G2_IN2(0); G2_IN3(1); G2_IN4(1); break;}//1,0,1,1
				case AD_GAIN_X64:  {G2_IN1(1); G2_IN2(1); G2_IN3(0); G2_IN4(1); break;}//1,1,0,1
				case AD_GAIN_X128: {G2_IN1(1); G2_IN2(1); G2_IN3(1); G2_IN4(0); break;}//1,1,1,0
				case AD_GAIN_X209: {G2_IN1(0); G2_IN2(0); G2_IN3(0); G2_IN4(0); break;}//0,0,0,0
				default:  {G2_IN1(1); G2_IN2(1); G2_IN3(1); G2_IN4(1); break;}//默认1倍
			}
		}
		case 3:
		{
			switch(times)
			{
				case AD_GAIN_X1:   {G3_IN1(1); G3_IN2(1); G3_IN3(1); G3_IN4(1); break;}//1,1,1,1
				case AD_GAIN_X4:   {G3_IN1(0); G3_IN2(1); G3_IN3(1); G3_IN4(1); break;}//0,1,1,1
				case AD_GAIN_X16:  {G3_IN1(1); G3_IN2(0); G3_IN3(1); G3_IN4(1); break;}//1,0,1,1
				case AD_GAIN_X64:  {G3_IN1(1); G3_IN2(1); G3_IN3(0); G3_IN4(1); break;}//1,1,0,1
				case AD_GAIN_X128: {G3_IN1(1); G3_IN2(1); G3_IN3(1); G3_IN4(0); break;}//1,1,1,0
				case AD_GAIN_X209: {G3_IN1(0); G3_IN2(0); G3_IN3(0); G3_IN4(0); break;}//0,0,0,0
				default:  {G3_IN1(1); G3_IN2(1); G3_IN3(1); G3_IN4(1); break;}//默认1倍
			}
		}
		case 4:
		{
			switch(times)
			{
				case AD_GAIN_X1:   {G4_IN1(1); G4_IN2(1); G4_IN3(1); G4_IN4(1); break;}//1,1,1,1
				case AD_GAIN_X4:   {G4_IN1(0); G4_IN2(1); G4_IN3(1); G4_IN4(1); break;}//0,1,1,1
				case AD_GAIN_X16:  {G4_IN1(1); G4_IN2(0); G4_IN3(1); G4_IN4(1); break;}//1,0,1,1
				case AD_GAIN_X64:  {G4_IN1(1); G4_IN2(1); G4_IN3(0); G4_IN4(1); break;}//1,1,0,1
				case AD_GAIN_X128: {G4_IN1(1); G4_IN2(1); G4_IN3(1); G4_IN4(0); break;}//1,1,1,0
				case AD_GAIN_X209: {G4_IN1(0); G4_IN2(0); G4_IN3(0); G4_IN4(0); break;}//0,0,0,0
				default:  {G4_IN1(1); G4_IN2(1); G4_IN3(1); G4_IN4(1); break;}//默认1倍
			}
		}
		default:break;
	}
}
// @ function: 
// @ description:
// @ input:
// @ note:
void AD_Amp_SetAll(void){
	//设置各通道信号放大倍数(1,4,16,64,128,209)
	AD_Amp_Set(1,AD_GAIN_X1);
	AD_Amp_Set(2,AD_GAIN_X1);
	AD_Amp_Set(3,AD_GAIN_X1);
	AD_Amp_Set(4,AD_GAIN_X1);
}

