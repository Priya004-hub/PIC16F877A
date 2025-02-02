#include <pic.h>
#define RS RC0
#define RW RC1
#define EN RC2

void cmd(unsigned char a);
void data(unsigned char a);
void delay();

void main() {
    TRISD = 0x00;
    PORTD = 0x00; 

    TRISC = 0x00; 
    PORTC = 0x00; 

    
    cmd(0x38); 
    cmd(0x0C); 
    cmd(0x06); 	
    cmd(0x01); 
    cmd(0x80); 
	cmd(0xC0);

	unsigned char a[50]={"MY NAME IS PRIYA"};
	unsigned int i;
    while (1) {
		for(i=0;i<=50;i++){
	
    	   data(a[i]);
		}
	while(1);
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
