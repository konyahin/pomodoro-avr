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
#include <stddef.h>

#include "timer.h"

// should be 60, but I calibrate it for my needs
#define SEC 57

static uint8_t minutes = 0;
static uint8_t seconds = 0;
static void (*callback) (void) = NULL;

ISR (TIMER1_COMPA_vect)
{
    if (seconds > 0)
    {
        --seconds;
        return;
    }
    else
    {
        seconds = SEC;
        --minutes;
    }
    if (minutes == 0 && callback != NULL)
        callback();
}

void
init_timer(void)
{
    cli();
    // value for compare
    OCR1A = 244;
    // enable compare unterrupt
    TIMSK |= (1 << OCIE1A);
    // CTC1 start comparing
    // CS13 CS12 CS10 - CK/4096 prescaling
    TCCR1 |= (1 << CTC1) | (1 << CS13) | (1 << CS12) | (1 << CS10);
    sei();
}

void
set_timer_callback(uint8_t min, void (*call) (void))
{
    minutes = min;
    callback = call;
    seconds = SEC;
}
