#include <pic.h>
#define d1 RB6
#define d2 RB7
#define LED1 RD0
#define LED2 RD1
#define LED3 RD2
#define LED4 RD3
#define LED5 RD4
#define LED6 RD5
#define LED7 RD6

void delay();

void main() {
    // Set PORTD as output
    TRISD = 0x00;
    PORTD = 0x00;

    // Set PORTB6 and PORTB7 as output for digit control
    TRISB = 0x00;
    PORTB = 0x00;

    unsigned char a[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    unsigned int i, j;

    while (1) {
        // Display units place
        for (i = 0; i < 99; i++) {
            j = i % 10; // Extract units digit
            d1 = 1;     // Enable first digit
            d2 = 0;     // Disable second digit
            PORTD = a[j]; // Display digit
            delay();

            // Display tens place
            j = i / 10; // Extract tens digit
            d2 = 1;     // Enable second digit
            d1 = 0;     // Disable first digit
            PORTD = a[j]; // Display digit
            delay();
        }
    }
}

void delay() {
    unsigned int i;
    for (i = 0; i <= 1000; i++);
}
