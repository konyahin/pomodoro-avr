#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "interrupt.h"

static void (*callback)(void);

void
init_interrupt(void (*on_press) (void))
{
    callback = on_press;

    DDRB &= ~(1 << BUTTON);

    cli();
    // enable pin-change interrupt
    GIMSK |= (1 << PCIE);
    // interrupt on specific pin
    PCMSK |= (1 << INTERRUPT);
    sei();
}

ISR (PCINT0_vect)
{
    int8_t pressed = !(PINB & (1 << BUTTON));
    if (pressed) {
        _delay_ms(30);
        pressed = !(PINB & (1 << BUTTON));
        if (pressed)
            (*callback)();
    }
}

