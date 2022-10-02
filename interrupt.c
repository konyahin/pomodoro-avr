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

