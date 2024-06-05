#include "headfile.h"
#include "oledfront.h"

#define AIN1 P13
#define AIN2 P14
#define BIN1 P07
#define BIN2 P15


#define sensor0 P04
#define sensor1 P03
#define sensor2 P02
#define sensor3 P01
#define sensor4 P00


extern flagfalsegoright;
extern flag_R90delay;


extern flag_L45 ;
extern flag_R45 ;

extern flag_01110 ;
extern flag_L90 ;
extern flag_R90 ;
extern flag_45_00100 ;
extern flaggoright;
extern flaggoleft;

extern PwmA;
extern PwmB;
extern stop;


void read_sensor(void) {

	//一、跑直线
	if (sensor0 == 0 && sensor1 == 0 && sensor2 == 1 && sensor3 == 0 && sensor4 == 0)
	{
       /*跑直线代码*/
		PwmA=3550;
		PwmB=5800;
		flaggoright=0;
		flaggoleft=0;
	}
		
		
	//二、弯道和类135度
	//（小车位置偏右，直线在左侧）
	else if (sensor0 == 0 && sensor1 == 1 && sensor2 == 0 && sensor3 == 0 && sensor4 == 0) 
	{
		/*调整代码*/
			PwmA=2500;
			PwmB=-2500;
			flaggoright=0;
			flaggoleft=0;
	}
		
	
	//（小车位置偏左，直线在右侧）
	else if (sensor0 == 0 && sensor1 ==0&& sensor2 == 0 && sensor3 == 1 && sensor4 == 0)
	{
	/*调整代码*/
		PwmA=-2500;
		PwmB=2500;
		flaggoright=0;
		flaggoleft=0;
	}
	
	//（小车位置偏左很多，直线在右侧）
	else if (sensor0 == 0 && sensor1 ==0&& sensor2 == 0 && sensor3 == 0 && sensor4 == 1)
	{
		PwmA=-3000;
		PwmB=3000;
		flaggoright=1;
	}
	//小车位置偏右很多
	else if (sensor0 == 1 && sensor1 ==0&& sensor2 == 0 && sensor3 == 0 && sensor4 == 0)
	{
		PwmA=3000;
		PwmB=-3000;
		flaggoleft=1;
	}
		
		
	else if(sensor0 == 0 && sensor1 ==0&& sensor2 == 0 && sensor3 == 0 && sensor4 == 0)
	{
		if(flaggoright==1)
		{
		PwmA=3000;
		PwmB=10;
		flaggoright=0;
		}
		else if(flaggoleft==1)
		{
		PwmA=10;
		PwmB=3000;
		flaggoleft=0;
		}
		
	}

	//三、遇到（01110或11110或01111）后再判断是否遇到终点还是十字
	else if ((sensor0 == 0 && sensor1 == 1 && sensor2 == 1 && sensor3 == 1 && sensor4 == 0)
		||(sensor0 == 0 && sensor1 == 1 && sensor2 == 1 && sensor3 == 1 && sensor4 == 0)
	||(sensor0 == 0 && sensor1 == 1 && sensor2 == 1 && sensor3 == 1 && sensor4 == 1)) {
		flag_01110 = 1;
	}
	
	//四、遇到90度
	//左90度(11000)
	else if ((sensor0 == 0 && sensor1 == 1 && sensor2 == 1 && sensor3 == 0 && sensor4 == 0)) {
		flag_L90 = 1;
	}
	//右90（00011）
	else if ((sensor0 == 0 && sensor1 == 0 && sensor2 == 1 && sensor3 == 1 && sensor4 == 0)) {
		flag_R90 = 1;
	}

	//遇到类45度角
	//左则类45度角（10100）
	else if (sensor0 == 1 && sensor1 == 0 && sensor2 == 1 && sensor3 == 0 && sensor4 == 0) {
		flag_L45 = 1;
	}
	//右侧类45度角（）
	else if (sensor0 == 0 && sensor1 == 0 && sensor2 == 1 && sensor3 == 0 && sensor4 == 1) {
		flag_R45 = 1;
	}
}




int myabs(int a)
{ 		   
	  int temp;
		if(a<0)  temp=-a;  
	  else temp=a;
	  return temp;
}

void Set_Pwm(int moto1,int moto2)
{
			if(moto1<0)
			{				
				BIN1=0,	BIN2=1;
			pwm_duty(PWMA_CH1P_P10, myabs(moto1));
			}
			else if(moto1>0)
			{
					BIN1=1,	BIN2=0;
			pwm_duty(PWMA_CH1P_P10, myabs(moto1));
			}
			else
				{
				BIN2=1,	BIN1=1;
				}
	
    	if(moto2<0)
		{
			AIN1=1,	AIN2=0;
			pwm_duty(PWMA_CH4P_P26, myabs(moto2));
		}
			else if(moto2>0)
			{
				AIN1=0,	AIN2=1;
				pwm_duty(PWMA_CH4P_P26, myabs(moto2));
			}

			else {AIN1=1,	AIN2=1;}
}


