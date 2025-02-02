#include<pic.h>
#define LED1 RD2 
#define LED2 RD1
#define LED3 RD0
#define BUTTON1 RC0
#define BUTTON2 RC1
#define BUTTON3 RC2
#define BUTTON4 RC3
#define BUTTON5 RC4
#define BUTTON6 RC5

void delay();
void main(){
	TRISD=1;
	PORTD=0x00;
while(1){
	if(BUTTON1==1){
		LED1=1;
		delay();
		}
	else if(BUTTON2||BUTTON3==1){
		LED2=1;
		delay();
		}
	else if(BUTTON4&&BUTTON5==1){
		LED3=1;
		delay();
		}
	else{
		LED1=0;
		LED2=0;
		LED3=0;
		delay();
		}
	}
}
	void delay(){
		unsigned int i;
		for(i=0;i<1000;i++);
		}
	