#include "motor.h"
extern TIM_HandleTypeDef htim1;

int limit(int a)
{
   if(a>100)
		 a=100;
	 else if(a<0)
		 a=0-a;
	 else if(a<-100)
		 a=-100;
	 return a;
}
	
void load(int motor1,int motor2)
{
	//	MOTOR1_PWMA_TIM1 Channel4
   if(motor1<0)
	 {  
		 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
		 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
	 }
	 if(motor1>0)
	 {  
		 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
		 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
	 }
	 __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_4,limit(motor1));
	 if(motor2<0)
	 {  
		 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_SET);
		 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
	 }
	 if(motor2>0)
	 {  
		 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,GPIO_PIN_RESET);
		 HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
	 }
	 __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,limit(motor2));
}