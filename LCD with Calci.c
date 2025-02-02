#include<pic.h>
#include<string.h>
#include<stdio.h>
#define RS RB5
#define RW RB6
#define EN RB7

#define R1 RD4
#define R2 RD5
#define R3 RD6
#define R4 RD7

#define C1 RD0
#define C2 RD1
#define C3 RD2
#define C4 RD3
void output(unsigned char a);
void key(unsigned char a);
void cmd(unsigned char a);
void data(unsigned char a);
void delay();

void main() {
    TRISD = 0xF0;
    TRISC = 0x00; 
   	TRISB = 0x00;
	PORTB = 0x00;
	PORTD = 0x00;
	PORTC = 0x00;	   
    cmd(0x38); 
    cmd(0x0C); 
	cmd(0x10);  	
    cmd(0x01); 
 	cmd(0x06);
    cmd(0x80); 

	while(1){
 	C1=1;C2=0;C3=0;C4=0;
	if(R1==1){
		data('7');
	}
	if(R2==1){
		data('4');
	}
	if(R3==1){
		data('1');
	}
	if(R4==1){
		cmd(0x01);
		cmd(0x0c);
	}
	C1=0;C2=1;C3=0;C4=0;
	if(R1==1){
		data('8');
	}
	if(R2==1){
		data('5');
	}
	if(R3==1){
		data('2');
	}
	if(R4==1){
		data('0');
	}
	C1=0;C2=0;C3=1;C4=0;
	if(R1==1){
		data('9');
	}
	if(R2==1){
		data('6');
	}
	if(R3==1){
		data('3');
	}
	if(R4==1){
		data('=');

	}
	C1=0;C2=0;C3=0;C4=1;
	if(R1==1){
		data('%');
	}
	if(R2==1){
		data('*');
	}
	if(R3==1){
		data('-');
	}
	if(R4==1){
		data('+');
	}
	
}

}


void cmd(unsigned char a) {
    PORTC = a; 
    RS = 0;    
    RW = 0;    
    EN = 1;    
    delay();
    EN = 0;    
}

void data(unsigned char a) {
    PORTC = a; 
    RS = 1;    
    RW = 0;    
    EN = 1;       
    delay();
    EN = 0;   
}

void key(unsigned char a){
	PORTC=a;
	if(data=='\0'){
		RS=1;
		RW=1;
	}
	unsigned char num[40]={ 
		'7','8','9','/',
		'4','5','6','*',
		'1','2','3','-',
		'0','=','+'};
	unsigned int i;
	unsigned char temp;
	if(RW>0){
		for(i=0;i<100;i++){
			cmd(0x06);
			temp=1;
			if(num[i]==temp);
				RW=num[i];
		}	
			
		if(RW == num[i] && 
		RW=='+'||RW=='-' || RW == '*' || RW=='/'){
			if(RW!=0){
				if(RW=='+'){
					temp+=num[i];
				}
				if(RW=='-'){
					temp-=num[i];
				}
				if(RW=='*'){
					temp*=num[i];
				}
				if(RW=='/'){
					temp/=num[i];
				}
			else{
				cmd(0x01);
			}
	}
}

	EN=1;
	delay();
	EN=0;
}
}


void output(unsigned char a){

	PORTC=a;
	RS=0;
	RW=1;
	if(RW=='='){
		key(100);
	}
	EN=1;
	delay();
	EN=0;
}						
	
void delay() {
    unsigned int i;
    for (i = 0; i <= 5000; i++);
}  