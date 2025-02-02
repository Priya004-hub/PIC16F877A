#include <pic.h>
#include <string.h>
#include <stdio.h>

// Define LCD control pins
#define RS RB5
#define RW RB6
#define EN RB7

// Define keypad row pins
#define R1 RD4
#define R2 RD5
#define R3 RD6
#define R4 RD7

// Define keypad column pins
#define C1 RD0
#define C2 RD1
#define C3 RD2
#define C4 RD3

void output(unsigned char a);
void cmd(unsigned char a);
void data(unsigned char a);
void delay();

// Variables for arithmetic operations
unsigned char first_number[16], second_number[16];
unsigned char operation = '\0';
unsigned char result[16];
unsigned int idx1 = 0, idx2 = 0;

// Function Prototypes
void calculate();
unsigned char get_key();
int string_to_int(unsigned char *str);

void main() {
    TRISD = 0xF0;  // Rows as inputs, columns as outputs
    TRISC = 0x00;  // Port C as output for LCD
    TRISB = 0x00;  // Port B as output for LCD control
    PORTB = 0x00;  
    PORTD = 0x00;
    PORTC = 0x00;

    // LCD Initialization
    cmd(0x38); // 8-bit mode, 2-line display
    cmd(0x0C); // Display ON, cursor OFF
    cmd(0x01); // Clear display
    cmd(0x06); // Increment cursor
    cmd(0x80); // Move to first line

    while (1) {
        unsigned char key = get_key(); // Get the pressed key

        if (key != '\0') { // If a key is pressed
            data(key); // Display key on LCD

            if (key >= '0' && key <= '9') { // If numeric key
                if (operation == '\0') { // Storing the first number
                    first_number[idx1++] = key;
                } else { // Storing the second number
                    second_number[idx2++] = key;
                }
            } else if (key == '+' || key == '-' || key == '*' || key == '/') {
                operation = key; // Store the operator
            } else if (key == '=') { // Perform calculation
                calculate();
            } else if (key == 'C') { // Clear inputs
                cmd(0x01); // Clear LCD
                idx1 = idx2 = 0;
                operation = '\0';
                memset(first_number, 0, sizeof(first_number));
                memset(second_number, 0, sizeof(second_number));
            }
        }
    }
}

// Get the pressed key from the keypad
unsigned char get_key() {
    // Loop through each column to detect key presses
    C1 = 1; C2 = 0; C3 = 0; C4 = 0;
    if (R1 == 1) { delay(); while (R1 == 1); return '7'; }
    if (R2 == 1) { delay(); while (R2 == 1); return '4'; }
    if (R3 == 1) { delay(); while (R3 == 1); return '1'; }
    if (R4 == 1) { delay(); while (R4 == 1); return 'C'; } // Clear key

    C1 = 0; C2 = 1; C3 = 0; C4 = 0;
    if (R1 == 1) { delay(); while (R1 == 1); return '8'; }
    if (R2 == 1) { delay(); while (R2 == 1); return '5'; }
    if (R3 == 1) { delay(); while (R3 == 1); return '2'; }
    if (R4 == 1) { delay(); while (R4 == 1); return '0'; }

    C1 = 0; C2 = 0; C3 = 1; C4 = 0;
    if (R1 == 1) { delay(); while (R1 == 1); return '9'; }
    if (R2 == 1) { delay(); while (R2 == 1); return '6'; }
    if (R3 == 1) { delay(); while (R3 == 1); return '3'; }
    if (R4 == 1) { delay(); while (R4 == 1); return '='; }

    C1 = 0; C2 = 0; C3 = 0; C4 = 1;
    if (R1 == 1) { delay(); while (R1 == 1); return '/'; }
    if (R2 == 1) { delay(); while (R2 == 1); return '*'; }
    if (R3 == 1) { delay(); while (R3 == 1); return '-'; }
    if (R4 == 1) { delay(); while (R4 == 1); return '+'; }

    return '\0'; // No key pressed
}

// Perform the calculation
void calculate() {
    int num1 = string_to_int(first_number);
    int num2 = string_to_int(second_number);
    int calc_result = 0;

    if (operation == '+') {
        calc_result = num1 + num2;
    } else if (operation == '-') {
        calc_result = num1 - num2;
    } else if (operation == '*') {
        calc_result = num1 * num2;
    } else if (operation == '/') {
        if (num2 != 0) {
            calc_result = num1 / num2;
        } else {
            cmd(0x01); // Clear LCD
            data('E'); // Display "Error"
            data('r');
            data('r');
            data('o');
            data('r');
            return;
        }
    }

    // Convert result to string and display
    sprintf(result, "%d", calc_result);
    cmd(0x01); // Clear LCD
    for (unsigned char i = 0; result[i] != '\0'; i++) {
        data(result[i]);
    }

    // Reset variables for next operation
    idx1 = idx2 = 0;
    operation = '\0';
    memset(first_number, 0, sizeof(first_number));
    memset(second_number, 0, sizeof(second_number));
}

// Custom string-to-integer conversion
int string_to_int(unsigned char *str) {
    int num = 0, i = 0;
    while (str[i] != '\0') {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
}

// Send a command to the LCD
void cmd(unsigned char a) {
    PORTC = a;
    RS = 0;
    RW = 0;
    EN = 1;
    delay();
    EN = 0;
}

// Send data to the LCD
void data(unsigned char a) {
    PORTC = a;
    RS = 1;
    RW = 0;
    EN = 1;
    delay();
    EN = 0;
}

// Delay function
void delay() {
    for (unsigned int i = 0; i <= 5000; i++);
}
