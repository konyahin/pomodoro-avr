#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

#include "interrupt.h"

static void (*callback) (void);

void
init_interrupt(void (*on_press) (void))
{
    callback = on_press;

    // as input
    DDRB &= ~(1 << PB2);
    // enable external interrupt
    GIMSK |= (1 << INT0);
}

ISR (INT0_vect)
{
    if (PINB & (1 << PB2))
        return;
    _delay_ms(30);
    if (PINB & (1 << PB2))
        return;
    (*callback)();
}

