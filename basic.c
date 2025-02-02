#include<pic.h>
#define LED RD0
void delay();
void main(){
	TRISD=0;
	PORTD=0x00;
	while(1){
		LED=1;
		delay();
		LED=0;
		delay();
		}
		}
		void delay()
		{
			unsigned int i;
			for(i=0;i<10000;i++);
			}