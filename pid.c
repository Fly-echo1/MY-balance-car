#include "pid.h"

//开始大干一场！
extern int Encoder_Left,Encoder_Right;
float Med_Angle=3;	
float Vertical_Kp=?,Vertical_Kd=?;			
float Velocity_Kp=?,Velocity_Ki=?;	//Velocity_Ki=Velocity_Kp/200;

// float Turn_Kp=10,Turn_Kd=0.6;											


//直立环（外环） 
//PD控制
//输入 ：目标角度，当前角度，当前角速度
//输出：目标速度
int vertical(float Med_Angle,float angle,float d_angle) //
{  
    int temp;
    temp=Vertical_Kp*(Med_Angle-angle)+Vertical_Kd*d_angle;
    return temp;
}

//速度环（内环）
//PI控制
//输入：目标速度，当前速度
//输出：电机PWM [-100,100]
int Velocity(int target,int Encoder_Left,int Encoder_Right)
{   
    int temp;  
    static float error_lowout_last;//低通滤波器上一次的输出
    float a=0.6; //低通滤波参数 
    int Encoder_average=(Encoder_Left+Encoder_Right)/2;//两轮平均速度   
    int error=target-Encoder_average;//速度误差
    int error_LowOut;//低通滤波后的误差
 
     //低通滤波器
    error_LowOut=(1-a)*error_lowout_last+a*error;
    error_lowout_last=error_LowOut;

    //计算积分项
    int error_LowOut_sum=error_LowOut+error_LowOut_sum;
    //控制积分项的输出范围(-250~250)
    if (error_LowOut_sum < -250) {
    error_LowOut_sum = -250;
    } else if (error_LowOut_sum > 250) {
    error_LowOut_sum = 250;
    }

    //PI控制
    temp=Velocity_Kp*error_LowOut+Velocity_Ki*error_LowOut_sum;
    return temp;
}

//转向环
//暂时还用不上

void Control(void)
{



}