#include <pic.h>
#define d1 RB6
#define d2 RB7

void delay();

void main() {
    // Configure PORTD and PORTB
    TRISD = 0x00; // PORTD as output
    PORTD = 0x00; // Clear PORTD

    TRISB = 0x00; // Configure RB6 and RB7 as outputs
    PORTB = 0x00; // Clear PORTB

    // 7-segment display values for digits 0-9 (common anode configuration)
    unsigned char a[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
    unsigned int i, j;

    while (1) {
        for (i = 0; i < 100; i++) {
            // Display units place
            j = i % 10; // Extract units digit
            d1 = 1;     // Enable first digit
            d2 = 0;     // Disable second digit
            PORTD = a[j]; // Display the digit
            delay();

            // Display tens place
            j = i / 10; // Extract tens digit
            d1 = 0;     // Disable first digit
            d2 = 1;     // Enable second digit
            PORTD = a[j]; // Display the digit
            delay();
        }
    }
}

void delay() {
    unsigned int i;
    for (i = 0; i <= 10000; i++); // Simple delay loop
}
