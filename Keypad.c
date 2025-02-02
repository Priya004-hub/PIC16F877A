#include<pic.h>
#define RS RB7
#define RW RB6
#define EN RB5

#define R1 RD4
#define R2 RD5
#define R3 RD6
#define R4 RD7

#define C1 RC0
#define C2 RC1
#define C3 RC2
void cmd(unsigned char a);
void data(unsigned char a);
void delay();

void main() {
    TRISD = 0xF0;
    PORTD = 0x00; 
	
    TRISC = 0x00; 
    PORTC = 0x00; 
	
	TRISB = 0x00;
	PORTB = 0x00;

	   
    cmd(0x38); 
    cmd(0x0C); 
    cmd(0x06); 	
    cmd(0x01); 
    cmd(0x80); 

	while(1){
 	C1=1;C2=0;C3=0;
	R1=R2=R3=R4=1;
	if(R1==1){
		data('1');
		delay();
	}
	if(R2==1){
		data('4');
		delay();
	}
	if(R3==1){
		data('7');
		delay();
	}
	if(R4==1){
		data('*');
		delay();
	}
}
	while(1){
	R1=R2=R3=R4=1;
	C1=0;C2=1;C3=0;
	if(R1==1){
		data('2');
		delay();
	}
	if(R2==1){
		data('5');
		delay();
	}
	if(R3==1){
		data('8');
		delay();
	}
	if(R4==1){
		data('0');
		delay();
	}
}

	while(1){
		R1=R2=R3=R4=1;
		C1=0;C2=0;C3=1;
	if(R1==1){
		data('3');
		delay();
	}
	if(R2==1){
		data('6');
		delay();
	}
	if(R3==1){
		data('9');
		delay();
	}
	if(R4==1){
		data('#');
		delay();
	}
}
}


void cmd(unsigned char a) {
    PORTD = a; 
    RS = 0;    
    RW = 0;    
    EN = 1;    
    delay();
    EN = 0;    
}

void data(unsigned char a) {
    PORTD = a; 
    RS = 1;    
    RW = 0;    
    EN = 1;       
    delay();
    EN = 0;   
}

void delay() {
    unsigned int i;
    for (i = 0; i <= 1000; i++);
}
