/**
 *************************************************************************************
 * @file AD7606.c
 * @author liucongjun
 * @version 1.0
 * @date 2018-3-7
 * @brief AD7606的驱动
 *************************************************************************************
*/
#include "ad7606.h"
#include "gpio.h"
//#include "usart.h"
#include "tim.h"
#include "main.h"
#include "stm32f4xx.h"
#include "spi.h"

#include "global.h"

#define USE_AD_GAIN_ADJ 1 //USE gain_adj
#define USE_AD_ETHERCAT 1 // USE ETHERCAT

#if USE_AD_GAIN_ADJ
#include "gain_adj.h"
#endif

/* AD7606引脚定义
PC5 -O- OS 0							
PB0 -O- OS 1
PB1 -O- OS 2
RANGE		0:+/-5V 
PA3 -O- CONVST A&B					rising edge:start to convert
PC4 -O- _CS
PA4 -I- BUSY
PA2 -O- ICP_EN
*/

////配置读取的通道
//#define AD_CH1 1<<0
//#define AD_CH2 1<<1
//#define AD_CH3 1<<2
//#define AD_CH4 1<<3

//#define AD_USE_RST 0//新板子有RST功能

//#include "my_task.h"//包含一些宏定义

/*USB*/
#include "usbd_cdc_if.h"

#define TX_BUF_LEN_USB 1024*6
uint8_t txBuf_usb[TX_BUF_LEN_USB];//USB传输的缓冲数组
uint16_t txCount_usb=0;
/*USB end*/

/*AD queue*/
//#include "my_queue.h"
////#define AD_QUEUE_SIZE 1200
//QueueArray_type myAD_queue;
//Elemtype myAD_buff[AD_QUEUE_SIZE] = {0};//要根据实际速度更改
//Elemtype myAD_test_data2[60]={0x258,0x28c,0x2bf,0x2f2,0x323,0x351,0x37d,0x3a6,0x3cb,0x3ec,
//	                            0x409,0x420,0x433,0x441,0x449,0x44b,0x449,0x441,0x433,0x420,
//	                            0x409,0x3ec,0x3cb,0x3a6,0x37d,0x352,0x323,0x2f2,0x2bf,0x28c,
//	                            0x258,0x223,0x1f0,0x1bd,0x18c,0x15e,0x132,0x109,0xe4, 0xc3,
//	                            0xa6, 0x8f, 0x7c, 0x6e, 0x66, 0x64, 0x66, 0x6e, 0x7c, 0x8f,
//	                            0xa6, 0xc3, 0xe4, 0x109,0x132,0x15d,0x18c,0x1bd,0x1f0,0x223,};
int16_t myAD_test_data2[60]={0x258,0x28c,0x2bf,0x2f2,0x323,0x351,0x37d,0x3a6,0x3cb,0x3ec,
	                            0x409,0x420,0x433,0x441,0x449,0x44b,0x449,0x441,0x433,0x420,
	                            0x409,0x3ec,0x3cb,0x3a6,0x37d,0x352,0x323,0x2f2,0x2bf,0x28c,
	                            0x258,0x223,0x1f0,0x1bd,0x18c,0x15e,0x132,0x109,0xe4, 0xc3,
	                            0xa6, 0x8f, 0x7c, 0x6e, 0x66, 0x64, 0x66, 0x6e, 0x7c, 0x8f,
	                            0xa6, 0xc3, 0xe4, 0x109,0x132,0x15d,0x18c,0x1bd,0x1f0,0x223,};
/*AD queue end*/

#define OS2(State)	HAL_GPIO_WritePin(AD_OS2_GPIO_Port,AD_OS2_Pin,(GPIO_PinState)State)
#define OS1(State)	HAL_GPIO_WritePin(AD_OS1_GPIO_Port,AD_OS1_Pin,(GPIO_PinState)State)
#define OS0(State)	HAL_GPIO_WritePin(AD_OS0_GPIO_Port,AD_OS0_Pin,(GPIO_PinState)State)
#define SPI_CS(State)	HAL_GPIO_WritePin(AD_CS_GPIO_Port,AD_CS_Pin,(GPIO_PinState)State)

#define OS2(State)	HAL_GPIO_WritePin(AD_OS2_GPIO_Port,AD_OS2_Pin,(GPIO_PinState)State)
#define OS1(State)	HAL_GPIO_WritePin(AD_OS1_GPIO_Port,AD_OS1_Pin,(GPIO_PinState)State)
#define OS0(State)	HAL_GPIO_WritePin(AD_OS0_GPIO_Port,AD_OS0_Pin,(GPIO_PinState)State)
#define SPI_CS(State)	HAL_GPIO_WritePin(AD_CS_GPIO_Port,AD_CS_Pin,(GPIO_PinState)State)

#if AD_USE_RST //由于旧板子没有rst功能,为兼容旧板子
#define AD_RST(State)	HAL_GPIO_WritePin(BT_EN_GPIO_Port,BT_EN_Pin,(GPIO_PinState)State)
#else
#define AD_RST(State) 
#endif

union _AD7606_BUF AD7606_BUF;
//uint8_t AD_CH_ctrl = AD_CH4;//默认选择CH4
uint8_t AD_CH_ctrl = AD_CH1|AD_CH2|AD_CH3;//默认选择CH4

/**functiion**/

// @ function: AD7606_Init
// @ description:初始化AD7606
// @ input:
// @ note:
void AD7606_Init(void)
{
	AD7606_SetOsRate(AD_OS_X16);
	
	#ifdef AD7606_SOFT_SPI
	AD7606_GPIO_SPI();
	#endif
	
	#if USE_AD_GAIN_ADJ //如果定义了可控增益
	AD_Amp_SetAll();
	#endif
	
	
	//初始化队列
//  Init_queue(&myAD_queue,myAD_buff,AD_QUEUE_SIZE);
}

//  @ fuction:  
//  @ description:  过采样位解码
//  @ input:
//  @ output:
//  @ note: 
void AD7606_SetOsRate(AD7606_OS_Rate rate)
{
	switch(rate)
	{
		case AD_OS_NO:{OS2(0);OS1(0);OS0(0);break;}
		case AD_OS_X2:{OS2(0);OS1(0);OS0(1);break;}
		case AD_OS_X4:{OS2(0);OS1(1);OS0(0);break;}
		case AD_OS_X8:{OS2(0);OS1(1);OS0(1);break;}
		case AD_OS_X16:{OS2(1);OS1(0);OS0(0);break;}
		case AD_OS_X32:{OS2(1);OS1(0);OS0(1);break;}
		case AD_OS_X64:{OS2(1);OS1(1);OS0(0);break;}
		default:{OS2(0);OS1(0);OS0(0);break;}//111 invalid
	}
}

// @ function: 
// @ description:AD复位
// @ input:
// @ note:
void AD7606_rst(void)
{
	AD_RST(1);
	HAL_Delay(1);
	AD_RST(0);
}

// @ function: 
// @ description:AD rst
// @ input:
// @ note:供外部调用
void AD_rst_handle(void)
{
	AD7606_rst();
	
	//USB handle
	txCount_usb = 0;
	//wifi handle
//	DeInit_queue(&myAD_queue);//反初始化队列
	
}

//  @ fuction:  
//  @ description:  
//  @ input:
//  @ output:
//  @ note: 读取AD7606，兼容硬件和软件SPI
#ifdef AD7606_SOFT_SPI

#define SPI_SCK(State)	HAL_GPIO_WritePin(AD_SPI1_SCK_GPIO_Port,AD_SPI1_SCK_Pin,(GPIO_PinState)State)
#define SPI_MISO()	HAL_GPIO_ReadPin(AD_SPI1_MISO_GPIO_Port,(GPIO_PinState)AD_SPI1_MISO_Pin)
void AD7606_Read4CH(void)
{
	uint8_t i,j;
	uint8_t value;
	for(i=0;i<8;i++)
	{
		SPI_CS(0);//chip select
		for(j=0;j<8;j++)
		{
			value <<=1;
			if((AD_SPI1_MISO_GPIO_Port->IDR & AD_SPI1_MISO_Pin) != 0)
				value |= 1;
			AD_SPI1_SCK_GPIO_Port->BSRR = AD_SPI1_SCK_Pin;//set high
			SPI_SCK(0);//set low
		}
		SPI_CS(1);//chip deselect
		AD7606_BUF.bytebuf[i] = value;
	}
}
#else
void AD7606_Read4CH(void){
  uint8_t 						dummy;
  uint8_t 						recv;
	uint8_t 						i;
	HAL_StatusTypeDef status = HAL_OK;
	
	SPI_CS(0);//chip select
	for(i=0;i<8;i++){
	  SPI_CS(0);//chip select
		while(HAL_SPI_GetState(&hspi1)==HAL_SPI_STATE_BUSY_TX){};//等待发送缓冲区空
		
	  status = HAL_SPI_TransmitReceive(&hspi1,&dummy,&recv,1,5000);
	  assert_param(status == HAL_OK);		
		
		SPI_CS(1);//chip deselect
		AD7606_BUF.bytebuf[i] = recv;
	}
	//DMA 有数据，但是数据有问题??
//	status = HAL_SPI_Receive_DMA(&hspi1,AD7606_BUF.bytebuf,8);//HAL_SPI_Receive自带向从机发送空字节
//  assert_param(status == HAL_OK);	//硬件SPI没有调通？？注意OS情况下，DMA如果被OS管理了，会有问题
	SPI_CS(1);//chip deselect
	
}
#endif

//  @ fuction:  
//  @ description:  AD_CONVEST_PWM
//  @ input:
//  @ output:
//  @ note: TIM2 channal 4 --> output: f_khz Hz
void AD_CONVEST_PWM_Init(uint8_t f_khz){
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 70-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1200/f_khz-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 600/f_khz;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim2);
}

#ifdef AD7606_SOFT_SPI

//  @ fuction:  
//  @ description:  
//  @ input:
//  @ output:
//  @ note: 软件模拟SPI
void AD7606_GPIO_SPI(void){
  GPIO_InitTypeDef GPIO_InitStruct;
	
	  /**SPI1 GPIO Configuration    
    PA5     ------> SPI1_SCK
    PA6     ------> SPI1_MISO
    PA7     ------> SPI1_MOSI 
    */

  HAL_SPI_MspDeInit(&hspi1);//关闭硬件SPI
	
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, AD_SPI1_SCK_Pin|AD_SPI1_MOSI_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = AD_SPI1_SCK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(AD_SPI1_SCK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = AD_SPI1_MISO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(AD_SPI1_MISO_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = AD_SPI1_MOSI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(AD_SPI1_MOSI_GPIO_Port, &GPIO_InitStruct);

}
#endif

// @ function: 
// @ description:外部中断调用
// @ input:
// @ note: 由于无wifi,rw_lib_platform.c中copy
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
//  if (GPIO_Pin == WIFI_INT_Pin)
//  {
//		DRIVER_INT_HANDLE();
//  }
	
  //AD7606 Handle
	if(GPIO_Pin == AD_BUSY_Pin){
	  AD7606_handle();
	}
	
	//Ethercat IRQ
	if(GPIO_Pin == ETHERCAT_IRQ_Pin){
	  Ethercat_irq_handle();
	}
	//Ethercat SYNC0
	if(GPIO_Pin == SYNC0_Pin){
	  Ethercat_sync0_handle();
	}
	//Ethercat SYNC1
	if(GPIO_Pin == SYNC1_Pin){
	  Ethercat_sync0_handle();
	}
}

#if USE_AD_ETHERCAT
int16_t data[4] = {0};
int16_t cmd[4] = {0};
#endif
//  @ fuction:  
//  @ description:  AD7606_EXTI_Handle
//  @ input:
//  @ output:
//  @ note: 在rw_lib_platform.c中，wifi模块的中断中调用
//          注意 在本程序中，AD7606的中断须为下降沿触发(AD转换结束后),否则会有问题
void AD7606_handle(void){
//	uint8_t i = 0;
	int channel_data16[4] = {0};
//	static int temp;
	
  AD7606_Read4CH();
	
//	for(i=0;i<4;i++) 
//	{
//		printf("AD7606 = 0x%x,i=%d\r\n",AD7606_BUF.shortbuf[0+i],i);//会造成阻塞，Wifi无法初始化
//		
//	}
	//USB发送
//	for(i=6;i<8;i++) 
//	{ 
//		txBuf[txCount]=AD7606_BUF.bytebuf[i];
//		txCount++;
//	}
	
	if(AD_CH_ctrl & AD_CH1){
	#ifdef AD_CH1
	txBuf_usb[txCount_usb++]=AD7606_BUF.bytebuf[0];
	txBuf_usb[txCount_usb++]=AD7606_BUF.bytebuf[1];
	#endif
	}
	if(AD_CH_ctrl & AD_CH2){
	#ifdef AD_CH2
	txBuf_usb[txCount_usb++]=AD7606_BUF.bytebuf[2];
	txBuf_usb[txCount_usb++]=AD7606_BUF.bytebuf[3];
	#endif
	}
	if(AD_CH_ctrl & AD_CH3){
	#ifdef AD_CH3
	txBuf_usb[txCount_usb++]=AD7606_BUF.bytebuf[4];
	txBuf_usb[txCount_usb++]=AD7606_BUF.bytebuf[5];
	#endif
	}
	if(AD_CH_ctrl & AD_CH4){
	#ifdef AD_CH4
	txBuf_usb[txCount_usb++]=AD7606_BUF.bytebuf[6];
	txBuf_usb[txCount_usb++]=AD7606_BUF.bytebuf[7];	
	#endif
	}
//    txBuf_usb[txCount_usb++]=myAD_test_data2[temp]/255;
//    txBuf_usb[txCount_usb++]=myAD_test_data2[temp]%255;	
//		temp++;
//		if(temp>59) temp=0;
	
	if(txCount_usb >= TX_BUF_LEN_USB)
	{
		UsbSendData(txBuf_usb,TX_BUF_LEN_USB);
		txCount_usb = 0;
//		LED_Toggle();
	}
	//测试
//			if(temp > 59) temp = 0;
//			EnQueue(&myAD_queue,myAD_test_data2[temp++]);
//			EnQueue(&myAD_queue,myAD_test_data2[temp++]);
//			EnQueue(&myAD_queue,myAD_test_data2[temp++]);
//			EnQueue(&myAD_queue,myAD_test_data2[temp++]);
	
	channel_data16[0] = AD7606_BUF.bytebuf[0]<<8 | AD7606_BUF.bytebuf[1];
	channel_data16[1] = AD7606_BUF.bytebuf[2]<<8 | AD7606_BUF.bytebuf[3];
	channel_data16[2] = AD7606_BUF.bytebuf[4]<<8 | AD7606_BUF.bytebuf[5];
	channel_data16[3] = AD7606_BUF.bytebuf[6]<<8 | AD7606_BUF.bytebuf[7];
	
	//Ethercat
	#if USE_AD_ETHERCAT
	data[0] = channel_data16[0];
	data[1] = channel_data16[1];
	data[2] = channel_data16[2];
	data[3] = channel_data16[3];
	#endif
	
	//wifi发送
//	channel_data16[0] = AD7606_BUF.bytebuf[0]*255+AD7606_BUF.bytebuf[1];
//	if(AD_CH_ctrl & AD_CH1){
//	#ifdef AD_CH1
//	EnQueue(&myAD_queue,channel_data16[0]);
//	#endif
//	}
//	if(AD_CH_ctrl & AD_CH2){
//	#ifdef AD_CH2
//	EnQueue(&myAD_queue,channel_data16[1]);
//	#endif
//	}
//	if(AD_CH_ctrl & AD_CH3){
//	#ifdef AD_CH3
//	EnQueue(&myAD_queue,channel_data16[2]);
//	#endif
//	}
//	if(AD_CH_ctrl & AD_CH4){
//	#ifdef AD_CH4
//	EnQueue(&myAD_queue,channel_data16[3]);
//	#endif
//	}
	
}

