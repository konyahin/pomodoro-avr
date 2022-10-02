/*
 * avr pomodoro timer
 * © 2022 Anton Konyahin <me@konyahin.xyz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
