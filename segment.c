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
	TRISD=0;
	PORTD=0x00;
	unsigned int i;
	for(i=0;i<=6;i++);{
		switch(i>0){
			case 1:PORTD=0x3F;
					delay();
			case 2:PORTD=0x06;
					delay();
			case 3:PORTD=0x5B;
					delay();
			case 4:PORTD=0x4F;
					delay();
			case 5:PORTD=0x66;
					delay();
			case 6:PORTD=0x6D;
					delay();
			case 7:PORTD=0x7D;
					delay();
			case 8:PORTD=0x07;
					delay();
			case 9:PORTD=0x7F;
					delay();
			case 10:PORTD=0x6F;
					delay();

}
}
}
void delay(){
	unsigned int i;
	for(i=0;i<=10000;i++);
	}
			
	
	