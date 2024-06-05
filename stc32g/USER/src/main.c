/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897(����)  ��Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32G12K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "headfile.h"


void Delay100ms(void)	//@11.0592MHz
{
	unsigned long edata i;
	i = 276478UL;
	while (i) i--;
}

void Delay500ms(void)	//@11.0592MHz
{
	unsigned long edata i;
	i = 1382398UL;
	while (i) i--;
}

void Delay1000ms(void)	//@11.0592MHz
{
	unsigned long edata i;

	i = 2764798UL;
	while (i) i--;
}

void Delay50ms(void)	//@11.0592MHz
{
	unsigned long edata i;

	i = 138238UL;
	while (i) i--;
}

void Delay40ms(void)	//@11.0592MHz
{
	unsigned long edata i;

	_nop_();
	_nop_();
	i = 110590UL;
	while (i) i--;
}

void Delay30ms(void)	//@11.0592MHz
{
	unsigned long edata i;
	i = 82942UL;
	while (i) i--;
}

void Delay10ms(void)	//@11.0592MHz
{
	unsigned long edata i;
	i = 27646UL;
	while (i) i--;
}
#define sensor0 P04
#define sensor1 P03
#define sensor2 P02
#define sensor3 P01
#define sensor4 P00

//���
	void showwandao(void)
	{
		oled_fill(0x00);
		OLED_ShowCHinese(70,4,0);
		OLED_ShowCHinese(90,4,1);
	}
//��ʮ���
	void show45(void)
	{
		oled_fill(0x00);
		OLED_ShowCHinese(50,4,19);
		OLED_ShowCHinese(70,4,20);
		OLED_ShowCHinese(90,4,21);
		OLED_ShowCHinese(110,4,4);
	}

//��ʮ��
	void show90(void)
	{
		oled_fill(0x00);
		OLED_ShowCHinese(70,4,17);
		OLED_ShowCHinese(90,4,18);
		OLED_ShowCHinese(110,4,4);
	}

//ʮ��
	void showshizi(void)
	{
		oled_fill(0x00);
		OLED_ShowCHinese(70,4,7);
		OLED_ShowCHinese(90,4,8);
	}

//��·
	void showsilu(void)
	{
		oled_fill(0x00);
		OLED_ShowCHinese(70,4,9);
		OLED_ShowCHinese(90,4,10);
	}

//���
	void showqidian(void)
	{
		oled_fill(0x00);
		OLED_ShowCHinese(70,4,11);
		OLED_ShowCHinese(90,4,12);
	}
	
//�յ�
	void showzhongdian(void)
	{
		oled_fill(0x00);
		OLED_ShowCHinese(70,4,13);
		OLED_ShowCHinese(90,4,14);
	}

//����
	void showhuandao(void)
	{
		oled_fill(0x00);
		OLED_ShowCHinese(70,4,15);
		OLED_ShowCHinese(90,4,16);
	}

//T��
	void showT(void)
	{
		oled_fill(0x00);
		OLED_ShowCHinese(70,4,22);
		OLED_ShowCHinese(86,4,8);
	}
/*
 * ϵͳƵ�ʣ��ɲ鿴board.h�е� FOSC �궨���޸ġ�
 * board.h�ļ���FOSC��ֵ����Ϊ0,������Զ�����ϵͳƵ��Ϊ33.1776MHZ
 * ��board_init��,�Ѿ���P54��������Ϊ��λ
 * �����Ҫʹ��P54����,������board.c�ļ��е�board_init()������ɾ��SET_P54_RESRT����
 */
int PwmA=0;
int PwmB=0;
int stop=0;


int flag=0;
int flagfalsegoright=0;
int flag_R90delay=0;

int flag_01110 = 0;
int flag_L90 = 0;
int flag_R90 = 0;
int flag_45_00100 = 0;
int flaggoright=0;
int flaggoleft=0;
int flag_L45 = 0;
int flag_R45 = 0;
int count=0;
int flag_in_Lhuan=0;
int flag_in_Rhuan=0;

void main()
{
	board_init();			// ��ʼ���Ĵ���,��ɾ���˾���롣
	
    oled_init(); 
	
	
	pwm_init(PWMA_CH1P_P10, 17000, 0);     //��ʼ��PWM1�� P1.0  ���PWMƵ��17000HZ   ռ�ձ�Ϊ�ٷ�֮ pwm_duty / PWM_DUTY_MAX * 100
	pwm_init(PWMA_CH4P_P26, 17000, 0);     //��ʼ��PWM4�� P2.6���PWMƵ��17000HZ   ռ�ձ�Ϊ�ٷ�֮ pwm_duty / PWM_DUTY_MAX * 100
	
    // �˴���д�û����� ���������ʼ�������

    while(1)
    {
		if(flag==0)
		{
			oled_fill();
		showqidian();
			flag=1;
		}
		read_sensor();
		if(PwmA==2250&&PwmB==2250)
		{
		oled_fill(0x00);
		OLED_ShowCHinese(70,4,0);
		OLED_ShowCHinese(90,4,1);
		}
		if((PwmA==2500&&PwmB==-2500)||(PwmA==-2500&&PwmB==2500))
		{
			showwandao();
		}
		
		
		if(flag_in_Lhuan&&(((int)sensor0+(int)sensor1+(int)sensor2+(int)sensor3+(int)sensor4)>=2)){
			Set_Pwm(3000,-3000);
			Delay100ms();
			Delay100ms();
			Delay100ms();
			Set_Pwm(2250,2250);
			Delay1000ms();
			flag_in_Lhuan=0;
			flag_01110 = 0;
			flag_L90 = 0;
			flag_R90 = 0;
			flag_45_00100 = 0;
			flaggoright=0;
			flaggoleft=0;
			flag_L45 = 0;
			flag_R45 = 0;
			count=0;
			flag_in_Lhuan=0;
			flag_in_Rhuan=0;
		}
		if(flag_in_Rhuan&&(((int)sensor0+(int)sensor1+(int)sensor2+(int)sensor3+(int)sensor4)>=2)){
			Set_Pwm(-3000,3000);
			Delay100ms();
			Delay100ms();
			Delay100ms();
			Set_Pwm(2250,2250);
			Delay1000ms();
			flag_in_Rhuan=0;
			flag_01110 = 0;
			flag_L90 = 0;
			flag_R90 = 0;
			flag_45_00100 = 0;
			flaggoright=0;
			flaggoleft=0;
			flag_L45 = 0;
			flag_R45 = 0;
			count=0;
			flag_in_Lhuan=0;
			flag_in_Rhuan=0;
		}
		
		
		//��⵽��01110��
		if (flag_01110) 
		{
			//��ʱ0.2�����ٴμ�⵽��01110����Ϊֹͣ��
			Delay50ms();
			if(((int)sensor0+(int)sensor1+(int)sensor2+(int)sensor3+(int)sensor4)>=3)
			{
				oled_fill(0x00);
				showzhongdian();
				PwmA=0;PwmB=0;
				Set_Pwm(0,0);
				Delay1000ms();
				Delay1000ms();
				Delay1000ms();
				Delay1000ms();
				Delay1000ms();
			}else{
					oled_fill(0x00);
					showshizi();
				Set_Pwm(2250,2250);
				Delay100ms();
				flag_01110=0;
			}
		}

		if(flag_L45){
			Set_Pwm(2250,2250);
			Delay500ms();
			Delay100ms();
			Delay100ms();
			if((sensor0 == 0 && sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0)){
				count++;
			}
			Delay100ms();
			Delay100ms();
			Delay100ms();
			if((sensor0 == 0 && sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0)){
				count++;
			}
			if(count==2){
				oled_fill(0x00);
				show45();
				Set_Pwm(4700,-4700);
				Delay500ms();
				Delay100ms();
				Set_Pwm(2250,2250);
				Delay100ms();
				Delay100ms();
				count=0;
				flag_L45=0;
			}else
			{
				if(sensor0==1||sensor1==1){
					oled_fill(0x00);
					showhuandao();
					Set_Pwm(3000,-3000);
					Delay500ms();
					Set_Pwm(2250,2250);
					Delay500ms();
					Delay100ms();
					Delay50ms();
					Delay100ms();
					Delay100ms();
					count=0;
					flag_L45=0;
					flag_in_Lhuan=1;
				}
			}
		}
		if(flag_R45){
			Set_Pwm(2250,2250);
			Delay500ms();
			Delay100ms();
			Delay100ms();
			if((sensor0 == 0 && sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0)){
				count++;
			}
			Delay100ms();
			Delay100ms();
			Delay100ms();
			if((sensor0 == 0 && sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0)){
				count++;
			}
			if(count==2){
				oled_fill(0x00);
				show45();
				Set_Pwm(-4700,4700);
				Delay500ms();
				Delay100ms();
				Set_Pwm(2250,2250);
				Delay100ms();
				Delay100ms();
				count=0;
				flag_R45=0;
			}else
			{
				if(sensor4==1||sensor3==1){
					oled_fill(0x00);
					showhuandao();
					Set_Pwm(-3000,3000);
					Delay500ms();
					Set_Pwm(2250,2250);
					Delay500ms();
					Delay50ms();
					Delay100ms();
					Delay100ms();
					Delay100ms();
					count=0;
					flag_R45=0;
					flag_in_Rhuan=1;
				}
		}
		}
		if(flag_L90)
		{
			if(sensor4==1||sensor3==1){
					oled_fill(0x00);
					showshizi();
				Set_Pwm(2250,2250);
				Delay500ms();
				Delay100ms();
				Delay100ms();
				Delay100ms();
				flag_L90=0;
			}
			else{
				Delay10ms();
				if(sensor4==1||sensor3==1){
						oled_fill(0x00);
						showshizi();
					Set_Pwm(2250,2250);
					Delay500ms();
					Delay100ms();
					Delay100ms();
					Delay100ms();
					flag_L90=0;
				}else{
				Delay30ms();
				if(sensor4==1||sensor3==1){
						oled_fill(0x00);
						showshizi();
					Set_Pwm(2250,2250);
					Delay500ms();
					Delay100ms();
					Delay100ms();
					Delay100ms();
					flag_L90=0;
				}else
				{
					Delay10ms();
					if(sensor4==1||sensor3==1){
						oled_fill(0x00);
						showshizi();
						Set_Pwm(2250,2250);
						Delay500ms();
						Delay100ms();
						Delay100ms();
						Delay100ms();
						flag_L90=0;
					}
					else{
						Delay30ms();
						if(sensor4==1||sensor3==1){
						oled_fill(0x00);
						showshizi();
							Set_Pwm(2250,2250);
							Delay500ms();
							Delay100ms();
							Delay100ms();
							Delay100ms();
							flag_L90=0;
						}
						else
						{
							Delay10ms();
							if(sensor4==1||sensor3==1){
						oled_fill(0x00);
						showshizi();
								Set_Pwm(2250,2250);
								Delay500ms();
								Delay100ms();
								Delay100ms();
								Delay100ms();
								flag_L90=0;
							}
							else
							{
								Delay100ms();
								Delay100ms();
								Delay100ms();
								Delay10ms();
								if((sensor0 == 0 && sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0)){
									count++;
								}
								Delay100ms();
								if((sensor0 == 0 && sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0)){
									count++;
								}
								if(count==2){
									oled_fill(0x00);
									show90();
									Set_Pwm(4000,-4000);
									Delay500ms();
									Delay100ms();
									Delay100ms();
									flag_L90=0;
									count=0;
								}
								else if(((int)sensor0+(int)sensor1+(int)sensor2+(int)sensor3+(int)sensor4)>=2){
									oled_fill(0x00);
									showzhongdian();
									PwmA=0;PwmB=0;
									Set_Pwm(0,0);
									Delay1000ms();
									Delay1000ms();
									Delay1000ms();
									Delay1000ms();
									count=0;
								}
								else{
									oled_fill(0x00);
									showT();
									Set_Pwm(3500,-3500);
									Delay500ms();
									Delay100ms();
									flag_L90=0;
									Set_Pwm(2250,2250);
									Delay500ms();
									Delay500ms();
									Set_Pwm(3500,-3500);
									Delay500ms();
									Delay500ms();
									Delay100ms();
									Delay100ms();
									Delay100ms();
									Delay100ms();
									Set_Pwm(2250,2250);
									Delay500ms();
									Delay100ms();
									Delay100ms();
									Delay100ms();
									Set_Pwm(3500,-3500);
									Delay500ms();
									Delay100ms();
									Delay100ms();
									Set_Pwm(2250,2250);
									Delay100ms();
									Delay100ms();
									count=0;
								}
							}
						}
					}
				}
			}
			}
		}
		if(flag_R90)
		{
			if(sensor0==1||sensor1==1){
					oled_fill(0x00);
					showshizi();
				Set_Pwm(2250,2250);
				Delay500ms();
				Delay100ms();
				Delay100ms();
				Delay100ms();
				flag_R90=0;
			}else{
			Set_Pwm(2250,2250);
			Delay10ms();
			if(sensor0==1||sensor1==1){
					oled_fill(0x00);
					showshizi();
				Set_Pwm(2250,2250);
				Delay500ms();
				Delay100ms();
				Delay100ms();
				Delay100ms();
				flag_R90=0;
			}else{
			Delay30ms();
			if(sensor0==1||sensor1==1){
					oled_fill(0x00);
					showshizi();
				Set_Pwm(2250,2250);
				Delay500ms();
				Delay100ms();
				Delay100ms();
				Delay100ms();
				flag_R90=0;
			}else{
			Delay10ms();
			if(sensor0==1||sensor1==1){
					oled_fill(0x00);
					showshizi();
				Set_Pwm(2250,2250);
				Delay500ms();
				Delay100ms();
				Delay100ms();
				Delay100ms();
				flag_R90=0;
			}else{
			Delay30ms();
			if(sensor0==1||sensor1==1){
					oled_fill(0x00);
					showshizi();
				Set_Pwm(2250,2250);
				Delay500ms();
				Delay100ms();
				Delay100ms();
				Delay100ms();
				flag_R90=0;
			}else{
				Delay100ms();
				Delay100ms();
				Delay100ms();
				Delay10ms();
			if((sensor0 == 0 && sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0)){
				count++;
			}
			Delay100ms();
			if((sensor0 == 0 && sensor1 == 0 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0)){
				count++;
			}
			if(count==2)
			{
				oled_fill(0x00);
				show90();
				Set_Pwm(-4000,4000);
				Delay500ms();
				Delay100ms();
				Delay100ms();
				flag_R90=0;
				count=0;
			}
			else if(((int)sensor0+(int)sensor1+(int)sensor2+(int)sensor3+(int)sensor4)>=2){
					oled_fill(0x00);
					showzhongdian();
				PwmA=0;PwmB=0;
				Set_Pwm(0,0);
				Delay1000ms();
				Delay1000ms();
				Delay1000ms();
				Delay1000ms();
				Delay1000ms();
				count=0;
			}
			else{
				oled_fill(0x00);
				showT();
				Set_Pwm(-3000,3000);
				Delay500ms();
				Delay100ms();
				flag_R90=0;
				Set_Pwm(2250,2250);
				Delay500ms();
				Delay500ms();
				Set_Pwm(-3000,3000);
				Delay500ms();
				Delay500ms();
				Delay100ms();
				Delay100ms();
				Delay100ms();
				Delay100ms();
				Set_Pwm(2250,2250);
				Delay500ms();
				Delay500ms();
				Set_Pwm(-3000,3000);
				Delay500ms();
				Delay100ms();
				Set_Pwm(2250,2250);
				Delay100ms();
				Delay100ms();
				count=0;
			}
		}
		}
		}
		}
		}
		}
		Set_Pwm(PwmA,PwmB);
		oled_uint16(20,3,sensor0);
		oled_uint16(20,4,sensor1);
		oled_uint16(20,5,sensor2);
		oled_uint16(20,6,sensor3);
		oled_uint16(20,7,sensor4);
	}
}
