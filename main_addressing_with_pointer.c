#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 8000000
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF

// Register TRISB
#define DDRB (*((volatile uint8_t*) 0x086))
//bit TRISB
typedef struct
{
    unsigned DDRB0  :1;
    unsigned DDRB1  :1;
    unsigned DDRB2  :1;
    unsigned DDRB3  :1;
    unsigned DDRB4  :1;
    unsigned DDRB5  :1;
    unsigned DDRB6  :1;
    unsigned DDRB7  :1;
}DDRBbits_t;

volatile DDRBbits_t* const DDRBbits = (DDRBbits_t*)0x086;

// Register PORTB
#define PB (*((volatile uint8_t*) 0x006))
//bit TRISB
typedef struct
{
    unsigned PB0    :1;
    unsigned PB1    :1;
    unsigned PB2    :1;
    unsigned PB3    :1;
    unsigned PB4    :1;
    unsigned PB5    :1;
    unsigned PB6    :1;
    unsigned PB7    :1;
}PBbits_t;

volatile PBbits_t* const PBbits = (PBbits_t*)0x006;

void main(void) 
{
    DDRBbits->DDRB0 = 0;
    DDRBbits->DDRB1 = 0;
    DDRBbits->DDRB2 = 0;
    DDRBbits->DDRB3 = 0;
    while(1)
    {
        PBbits->PB0 = 0;
        PBbits->PB1 = 0;
        PBbits->PB2 = 0;
        PBbits->PB3 = 0;
        __delay_ms(1000);
        PBbits->PB0 = 1;
        PBbits->PB1 = 1;
        PBbits->PB2 = 1;
        PBbits->PB3 = 1;
        __delay_ms(1000);
    }
    return;
}

