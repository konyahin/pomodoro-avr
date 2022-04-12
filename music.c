#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdarg.h>

#include "music.h"

void
play_melody(const melody_t *melody)
{
    // set clk/8 prescaling
    TCCR0B |= (1 << CS01);

    for (int8_t i = 0; i < melody->length; i++)
    {
        OCR0A = melody->tones[i];
        _delay_ms(DELAY);
    }

    // disable timer
	TCCR0B &= ~(1 << CS01);
}

void
init_music(void)
{
    DDRB |= (1 << SOUND);
    PORTB &= ~(1 << SOUND);

    // set timer setting
    TCCR0A |= (1 << WGM01);
    TCCR0A |= (1 << COM0A0);
}
