#include "global.h"	
#include "stm32f4xx.h"
//#include "delay.h"
//#include "ad7606.h"

//void DAS_GPIO_Init(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	//LED
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);
//	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
//	
//	//G1_IN1--G1_IN4: PC9,PC8,PC6,PC7
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7| GPIO_Pin_8| GPIO_Pin_9;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//  GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIO
//	GPIO_SetBits(GPIOC,GPIO_Pin_6 | GPIO_Pin_7| GPIO_Pin_8| GPIO_Pin_9);//Ĭ�ϸߵ�ƽ�Ŵ���Ϊ1
//	
//	//G2_IN1--G2_IN4, G3_IN1--G3_IN4: PD15,PD14,PD12,PD13,PD11,PD10,PD8,PD9,
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//  GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��GPIO
//	GPIO_SetBits(GPIOD,GPIO_Pin_8|GPIO_Pin_9| GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);//Ĭ�ϸߵ�ƽ�Ŵ���Ϊ1
//	
//	//G4_IN1--G4_IN4: PB15,PB14,PB12,PB13
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14| GPIO_Pin_12| GPIO_Pin_13;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
//  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIO
//	GPIO_SetBits(GPIOB,GPIO_Pin_15 | GPIO_Pin_14| GPIO_Pin_12| GPIO_Pin_13);//Ĭ�ϸߵ�ƽ�Ŵ���Ϊ1
//}

void LED_Twinkle(void)
{
//		GPIO_ToggleBits(GPIOA, GPIO_Pin_2);
//		delay_ms(60);
	HAL_GPIO_TogglePin(LED_STATE_GPIO_Port,LED_STATE_Pin);
	HAL_Delay(60);
}

//#define AD_GAIN_X1 1
//#define AD_GAIN_X4 4
//#define AD_GAIN_X16 16
//#define AD_GAIN_X64 64
//#define AD_GAIN_X128 128
//#define AD_GAIN_X209 209

///*����ָ��ͨ�����źŷŴ�����chn=1-4��times=1,4,16,64,128,209(�ݶ���ʵ���ϷŴ���1-209֮��������)*/
//void Amp_Set(int chn,int times)
//{
//	switch(chn)
//	{
//		case 1:
//		{
//			switch(times)
//			{
//				case 1:   {G1_IN1_H; G1_IN2_H; G1_IN3_H; G1_IN4_H; break;}//1,1,1,1
//				case 4:   {G1_IN1_L; G1_IN2_H; G1_IN3_H; G1_IN4_H; break;}//0,1,1,1
//				case 16:  {G1_IN1_H; G1_IN2_L; G1_IN3_H; G1_IN4_H; break;}//1,0,1,1
//				case 64:  {G1_IN1_H; G1_IN2_H; G1_IN3_L; G1_IN4_H; break;}//1,1,0,1
//				case 128: {G1_IN1_H; G1_IN2_H; G1_IN3_H; G1_IN4_L; break;}//1,1,1,0
//				case 209: {G1_IN1_L; G1_IN2_L; G1_IN3_L; G1_IN4_L; break;}//0,0,0,0
//				default:  {G1_IN1_H; G1_IN2_H; G1_IN3_H; G1_IN4_H; break;}//Ĭ��1��
//			}
//		}
//		case 2:
//		{
//			switch(times)
//			{
//				case 1:   {G2_IN1_H; G2_IN2_H; G2_IN3_H; G2_IN4_H; break;}//1,1,1,1
//				case 4:   {G2_IN1_L; G2_IN2_H; G2_IN3_H; G2_IN4_H; break;}//0,1,1,1
//				case 16:  {G2_IN1_H; G2_IN2_L; G2_IN3_H; G2_IN4_H; break;}//1,0,1,1
//				case 64:  {G2_IN1_H; G2_IN2_H; G2_IN3_L; G2_IN4_H; break;}//1,1,0,1
//				case 128: {G2_IN1_H; G2_IN2_H; G2_IN3_H; G2_IN4_L; break;}//1,1,1,0
//				case 209: {G2_IN1_L; G2_IN2_L; G2_IN3_L; G2_IN4_L; break;}//0,0,0,0
//				default:  {G2_IN1_H; G2_IN2_H; G2_IN3_H; G2_IN4_H; break;}//Ĭ��1��
//			}
//		}
//		case 3:
//		{
//			switch(times)
//			{
//				case 1:   {G3_IN1_H; G3_IN2_H; G3_IN3_H; G3_IN4_H; break;}//1,1,1,1
//				case 4:   {G3_IN1_L; G3_IN2_H; G3_IN3_H; G3_IN4_H; break;}//0,1,1,1
//				case 16:  {G3_IN1_H; G3_IN2_L; G3_IN3_H; G3_IN4_H; break;}//1,0,1,1
//				case 64:  {G3_IN1_H; G3_IN2_H; G3_IN3_L; G3_IN4_H; break;}//1,1,0,1
//				case 128: {G3_IN1_H; G3_IN2_H; G3_IN3_H; G3_IN4_L; break;}//1,1,1,0
//				case 209: {G3_IN1_L; G3_IN2_L; G3_IN3_L; G3_IN4_L; break;}//0,0,0,0
//				default:  {G3_IN1_H; G3_IN2_H; G3_IN3_H; G3_IN4_H; break;}//Ĭ��1��
//			}
//		}
//		case 4:
//		{
//			switch(times)
//			{
//				case 1:   {G4_IN1_H; G4_IN2_H; G4_IN3_H; G4_IN4_H; break;}//1,1,1,1
//				case 4:   {G4_IN1_L; G4_IN2_H; G4_IN3_H; G4_IN4_H; break;}//0,1,1,1
//				case 16:  {G4_IN1_H; G4_IN2_L; G4_IN3_H; G4_IN4_H; break;}//1,0,1,1
//				case 64:  {G4_IN1_H; G4_IN2_H; G4_IN3_L; G4_IN4_H; break;}//1,1,0,1
//				case 128: {G4_IN1_H; G4_IN2_H; G4_IN3_H; G4_IN4_L; break;}//1,1,1,0
//				case 209: {G4_IN1_L; G4_IN2_L; G4_IN3_L; G4_IN4_L; break;}//0,0,0,0
//				default:  {G4_IN1_H; G4_IN2_H; G4_IN3_H; G4_IN4_H; break;}//Ĭ��1��
//			}
//		}
//		default:break;
//	}
//}

//void EXTIX_Init(void)
//{
//	NVIC_InitTypeDef   NVIC_InitStructure;
//	EXTI_InitTypeDef   EXTI_InitStructure;
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//ʹ��SYSCFGʱ��

//	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource4);//PA4���ӵ��ж���4
//	
//  /* ����EXTI_Line4 */
//  EXTI_InitStructure.EXTI_Line = EXTI_Line4;//LINE4
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж��¼�
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; 
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//ʹ��LINE4
//  EXTI_Init(&EXTI_InitStructure);
//	
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;//�ⲿ�ж�4
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;//��ռ���ȼ�1
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;//�����ȼ�2
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
//  NVIC_Init(&NVIC_InitStructure);
//}

//int16_t data[4] = {0};
//int16_t cmd[4] = {0};

//void EXTI4_IRQHandler(void)
//void AD7606_handle(void)
//{	 
//	AD7606_Read4CH();

//	data[0] = (int16_t)(AD7606_BUF.bytebuf[0] << 8) |  AD7606_BUF.bytebuf[1];
//	data[1] = (int16_t)(AD7606_BUF.bytebuf[2] << 8) |  AD7606_BUF.bytebuf[3];
//	data[2] = (int16_t)(AD7606_BUF.bytebuf[4] << 8) |  AD7606_BUF.bytebuf[5];
//	data[3] = (int16_t)(AD7606_BUF.bytebuf[6] << 8) |  AD7606_BUF.bytebuf[7];

//	//EXTI_ClearITPendingBit(EXTI_Line4);//���LINE4�ϵ��жϱ�־λ  
////	__HAL_GPIO_EXTI_CLEAR_FLAG(AD_BUSY_Pin);
//}

//void TIM5_CH4_PWM_Init(int arr,int psc)
//{		 					 
//	//�˲������ֶ��޸�IO������
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;
//	
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);  	//TIM5ʱ��ʹ��    
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 	//ʹ��PORTAʱ��	
//	
//	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_TIM5); //GPIOA3����Ϊ��ʱ��5
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;           //GPIOA3
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;        //���ù���
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      //���츴�����
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        //����
//	GPIO_Init(GPIOA,&GPIO_InitStructure);              //��ʼ��PA3
//	  
//	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
//	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
//	TIM_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
//	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
//	
//	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);//��ʼ����ʱ��5
//	
//	//��ʼ��TIM5 Channel4 PWMģʽ	 
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
// 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ե�
//	TIM_OC4Init(TIM5, &TIM_OCInitStructure);

//	TIM_OC4PreloadConfig(TIM5, TIM_OCPreload_Enable);  //ʹ��TIM5��CCR4�ϵ�Ԥװ�ؼĴ���
// 
//  TIM_ARRPreloadConfig(TIM5,ENABLE);//ARPEʹ�� 
//	
//	TIM_Cmd(TIM5,ENABLE);  //ʹ��TIM5			
//}  

#include "ecatappl.h"
#include "tim.h"

void Ethercat_irq_handle(void){
   PDI_Isr();
}
void Ethercat_sync0_handle(void){
	NVIC_DisableIRQ(ETHERCAT_IRQ_EXTI_IRQn);
   Sync0_Isr();
	NVIC_EnableIRQ(ETHERCAT_IRQ_EXTI_IRQn);
}

void Ethercat_sync1_handle(void){
	NVIC_DisableIRQ(ETHERCAT_IRQ_EXTI_IRQn);
   Sync1_Isr();
	NVIC_EnableIRQ(ETHERCAT_IRQ_EXTI_IRQn);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  if(htim == &htim5){
	   ECAT_CheckTimer();
	}
}





















