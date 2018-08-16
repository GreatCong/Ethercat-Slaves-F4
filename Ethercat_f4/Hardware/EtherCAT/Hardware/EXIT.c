/**
 *************************************************************************************
 * @file 
 * @author lcj
 * @version
 * @date 2018-6-1
 * @brief Ethercat外部中断
          HAL库下，该文件没有用
 *************************************************************************************
*/
#include "stm32f4xx.h"
/*******************************************************************************
* Function Name  :EXTI0_Configuration
* Description    : EXTI0_Configuration初始化
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void EXTI3_Configuration(void)
{

//  EXTI_InitTypeDef   EXTI_InitStructure;
//  GPIO_InitTypeDef   GPIO_InitStructure;
//  NVIC_InitTypeDef   NVIC_InitStructure;

//  /* Enable GPIOE clock */
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
//  /* Enable SYSCFG clock */
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
//  
//  /* Configure PE3 pin as input floating */
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//  GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_NOPULL;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
//  GPIO_Init(GPIOE, &GPIO_InitStructure);

//  /* Connect EXTI Line3 to PE3 pin */
//  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);

//  /* Configure EXTI Line0 */
//  EXTI_InitStructure.EXTI_Line = EXTI_Line3;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure);

//  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);  				
//  NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 6;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);

}
/*******************************************************************************
* Function Name  : EXTI1_Configuration
* Description    : EXTI1_Configuration 初始化
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void EXTI1_Configuration(void)
{
//  EXTI_InitTypeDef   EXTI_InitStructure;
//  GPIO_InitTypeDef   GPIO_InitStructure;
//  NVIC_InitTypeDef   NVIC_InitStructure;

//  /* Enable GPIOA clock */
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
//  /* Enable SYSCFG clock */
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
//  
//  /* Configure PA0 pin as input floating */
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);

//  /* Connect EXTI Line0 to PA0 pin */
//  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource1);

//  /* Configure EXTI Line0 */
//  EXTI_InitStructure.EXTI_Line = EXTI_Line1;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure);

//  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);  				
//  NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 6;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);


}

/*******************************************************************************
* Function Name  : EXTI3_Configuration
* Description    : EXTI3_Configuration 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void EXTI2_Configuration(void)
{
//  EXTI_InitTypeDef   EXTI_InitStructure;
//  GPIO_InitTypeDef   GPIO_InitStructure;
//  NVIC_InitTypeDef   NVIC_InitStructure;

//  /* Enable GPIOA clock */
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
//  /* Enable SYSCFG clock */
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
//  
//  /* Configure PA0 pin as input floating */
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
//  GPIO_Init(GPIOC, &GPIO_InitStructure);

//  /* Connect EXTI Line0 to PA0 pin */
//  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource2);

//  /* Configure EXTI Line0 */
//  EXTI_InitStructure.EXTI_Line = EXTI_Line2;
//  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
//  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//  EXTI_Init(&EXTI_InitStructure);

//  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);  				
//  NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 7;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
}
