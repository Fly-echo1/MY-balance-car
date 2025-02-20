#include "pid.h"

//��ʼ���һ����
extern int Encoder_Left,Encoder_Right;
float Med_Angle=3;	
float Vertical_Kp=?,Vertical_Kd=?;			
float Velocity_Kp=?,Velocity_Ki=?;	//Velocity_Ki=Velocity_Kp/200;

// float Turn_Kp=10,Turn_Kd=0.6;											


//ֱ�������⻷�� 
//PD����
//���� ��Ŀ��Ƕȣ���ǰ�Ƕȣ���ǰ���ٶ�
//�����Ŀ���ٶ�
int vertical(float Med_Angle,float angle,float d_angle) //
{  
    int temp;
    temp=Vertical_Kp*(Med_Angle-angle)+Vertical_Kd*d_angle;
    return temp;
}

//�ٶȻ����ڻ���
//PI����
//���룺Ŀ���ٶȣ���ǰ�ٶ�
//��������PWM [-100,100]
int Velocity(int target,int Encoder_Left,int Encoder_Right)
{   
    int temp;  
    static float error_lowout_last;//��ͨ�˲�����һ�ε����
    float a=0.6; //��ͨ�˲����� 
    int Encoder_average=(Encoder_Left+Encoder_Right)/2;//����ƽ���ٶ�   
    int error=target-Encoder_average;//�ٶ����
    int error_LowOut;//��ͨ�˲�������
 
     //��ͨ�˲���
    error_LowOut=(1-a)*error_lowout_last+a*error;
    error_lowout_last=error_LowOut;

    //���������
    int error_LowOut_sum=error_LowOut+error_LowOut_sum;
    //���ƻ�����������Χ(-250~250)
    if (error_LowOut_sum < -250) {
    error_LowOut_sum = -250;
    } else if (error_LowOut_sum > 250) {
    error_LowOut_sum = 250;
    }

    //PI����
    temp=Velocity_Kp*error_LowOut+Velocity_Ki*error_LowOut_sum;
    return temp;
}

//ת��
//��ʱ���ò���

void Control(void)
{



}