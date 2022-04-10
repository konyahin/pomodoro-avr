#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

#include "interrupt.h"

#define LED_GREEN PB4
#define LED_RED PB1
#define SOUND PB0

enum status_e {
    ON,
    WORK,
    REST
};

int8_t status = ON;

void set_status()
{
    switch (status)
    {
        case ON:
            PORTB &= ~(1 << LED_RED);
            PORTB &= ~(1 << LED_GREEN);
            break;
        case WORK:
            PORTB |= (1 << LED_RED);
            PORTB &= ~(1 << LED_GREEN);
            break;
        case REST:
            PORTB &= ~(1 << LED_RED);
            PORTB |= (1 << LED_GREEN);
            break;
    }
}

void switch_status()
{
    if (++status > REST)
        status = ON;
    set_status();
}

void main(void)
{
    DDRB |= (1 << LED_GREEN);
    DDRB |= (1 << LED_RED);
    DDRB |= (1 << SOUND);

    init_interrupt(switch_status);

    cli();
    sei();
    
    while (true) {
    }
}
