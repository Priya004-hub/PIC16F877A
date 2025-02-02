#include <pic.h>

#define LED1 RD0
#define LED2 RD1
#define LED3 RD2
#define LED4 RD3
#define LED5 RD4
#define LED6 RD5
#define LED7 RD6

void delay();

void main() {
    TRISD = 0;  // Set PORTD as output
    PORTD = 0x00;  // Initialize PORTD to 0
    
    unsigned char a[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
    // Common anode 7-segment encoding for digits 0-9.
    // 0xC0 = 0, 0xF9 = 1, 0xA4 = 2, ..., 0x90 = 9

    unsigned int i;
    
    for(i = 0; i <= 9; i++) {  // Loop through the digits 0-9
        PORTD = a[i];  // Display the current digit on the 7-segment display
        delay();  // Delay to make the digit visible
    }
}

void delay() {
    unsigned int i;
    for(i = 0; i <= 10000; i++);  // Simple delay
}
