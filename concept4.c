#include<pic.h>
#define LED1 RD2
#define LED2 RD1
#define LED3 RD0
#define SWITCH1 RC0
#define SWITCH2 RC1
#define SWITCH3 RC2
#define SWITCH4 RC3
#define SWITCH5 RC4
#define SWITCH6 RC5

void delay();
void main(){
	TRISD=0;
	PORTD=0x00;
	while(1)
	{
		if(SWITCH1==1){
			LED1=1;
			delay();
		}
		else if(SWITCH2||SWITCH3==1){
			LED1=0;
			LED2=1;
			delay();
		}
		else if(SWITCH4&&SWITCH5==1){
			LED2=0;
			LED3=1;
			delay();
		}
		else if(SWITCH6==1){
			LED3=0;
			delay();
		}
		else{
		LED1=0;
		LED2=0;
		LED3=0;
		}
	}
}
void delay(){
	unsigned int i;
	for(i=0;i<1000;i++);
}