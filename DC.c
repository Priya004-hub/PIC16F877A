#include<pic.h>
#define IN1 RC0
#define IN2 RC1
#define IN3 RC3
#define IN4 RC4

#define R1 RD4
#define R2 RD5
#define R3 RD6
#define R4 RD7

#define C1 RD0
#define C2 RD1
#define C3 RD2
void delay();
void main(){
		TRISC=0x00;
		TRISD=0xF0;
		
		PORTC=0x00;
		PORTD=0x00;
		
		while(1){
			C1=1;C2=0;C3=0;
			delay();
			if(R1==1){
				IN1=1;
				IN2=0;

			}
			if(R2==1){
				IN4=1;
				IN3=0;
			}
			if(R3==1){
				IN1=1;
				IN2=0;
				IN3=1;
				IN4=0;
			}
			
		  C1=0;C2=1;C3=0;
		  delay();
		  if(R1==1){
				IN2=1;
				IN1=0;
			}
			if(R2==1){
				IN1=1;
				IN2=0;
			}
			if(R3==1){
				IN2=1;
				IN1=0;
				IN4=1;
				IN3=0;
			}
		  
			C1=0;C2=0;C3=1;
			delay();
			if(R1==1){
				IN3=1;
				IN4=0;
			}
			if(R2==1){
				IN2=1;
				IN1=0;
			}
			if(R3==1){
				IN1=0;
				IN2=0;
				IN3=0;
				IN4=0;
			}
		
		}
}
void delay(){
	unsigned int i;
	for(i=0;i<=1000;i++);
}
