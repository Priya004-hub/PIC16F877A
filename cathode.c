#include<pic.h>
#define LED1 RD0
#define LED2 RD1
#define LED3 RD2
#define LED4 RD3
#define LED5 RD4
#define LED6 RD5
#define LED7 RD6
void delay();
void main(){
	TRISD=1;
	PORTD=0x00;
	unsigned char a[50]={0x3F,0x06,0x53,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	unsigned int i;
	for(i=0;i<=10;i++){
		PORTD=a[i];
		delay();
		}
	}
	void delay(){
		unsigned int i;
		for(i=0;i<=10000;i++);
		} 