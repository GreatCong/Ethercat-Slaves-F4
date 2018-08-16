/**
 *************************************************************************************
 * @file 
 * @author
 * @version
 * @date
 * @brief Ethercat hardware timer (USE tim5)
 *************************************************************************************
*/

#include "stm32f4xx.h"
#include "ecat_def.h"

#include "tim.h"

/*******************************************************************************
* Function Name  : TIM_Configuration
* Description    : TIM_Configuration program.
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void TIM_Configuration(uint8_t period)		//100us
{
//  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure; 
//  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);
//	
//  TIM_DeInit(TIM2);
//  TIM_TimeBaseStructure.TIM_Period= period*200 ; //200;		 					/* �Զ���װ�ؼĴ������ڵ�ֵ(����ֵ) */
//																	/* �ۼ� TIM_Period��Ƶ�ʺ����һ�����»����ж� */
//  TIM_TimeBaseStructure.TIM_Prescaler= (42 - 1);				    /* ʱ��Ԥ��Ƶ��   ���磺ʱ��Ƶ��=72MHZ/(ʱ��Ԥ��Ƶ+1) */
//  TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 			/* ������Ƶ */
//  TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 		/* ���ϼ���ģʽ */
//  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
//  TIM_ClearFlag(TIM2, TIM_FLAG_Update);							    /* �������жϱ�־ */
//	#if ECAT_TIMER_INT
//  TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
//	#endif
//  TIM_Cmd(TIM2, ENABLE);											/* ����ʱ�� */
//	
//	#if ECAT_TIMER_INT
//						/* Configure NVIC Interrupt  -------------------------*/	
//		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);  													
//		NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;	  
//		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
//		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;	
//		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//		NVIC_Init(&NVIC_InitStructure);
//	#endif

//   MX_TIM2_Init();
	TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 42-1;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = period*200 ; //200;		 					/* �Զ���װ�ؼĴ������ڵ�ֵ(����ֵ) */
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim5, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	
	
	#if ECAT_TIMER_INT
//	HAL_TIM_Base_MspInit(&htim2);//NVIC������,��timerinit���Ѿ�ִ����
	 HAL_TIM_Base_Start_IT(&htim5);//��������ж�
	 NVIC_DisableIRQ(TIM5_IRQn) ;//ethercat��ʼ����ʱ���ٿ���NVIC
	#endif
}
