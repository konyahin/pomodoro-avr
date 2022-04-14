#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stddef.h>

#include "interrupt.h"
#include "music.h"
#include "timer.h"

#define LED_GREEN PB4
#define LED_RED PB3

#define WORK_MIN 25
#define REST_MIN 5

melody_t start_melody;
melody_t work_melody;
melody_t rest_melody;
melody_t end_melody;

enum status_e
{
    ON,
    WORK,
    REST
};

int8_t status = ON;

int8_t sleep = false;
void status_to_on()
{
    status = ON;
    PORTB &= ~(1 << LED_RED);
    PORTB &= ~(1 << LED_GREEN);
    play_melody(&end_melody);
    set_timer_callback(0, NULL);
    sleep = true;
}

void status_to_rest()
{
    status = REST;
    PORTB &= ~(1 << LED_RED);
    PORTB |= (1 << LED_GREEN);
    play_melody(&rest_melody);
    set_timer_callback(REST_MIN, &status_to_on);
}

void status_to_work()
{
    status = WORK;
    PORTB |= (1 << LED_RED);
    PORTB &= ~(1 << LED_GREEN);
    play_melody(&work_melody);
    set_timer_callback(WORK_MIN, &status_to_rest);
}

void switch_status()
{
    if (status == ON)
        status_to_work();
    else
        status_to_on();
}

int main(void)
{
    DDRB |= (1 << LED_GREEN);
    DDRB |= (1 << LED_RED);

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sei();

    init_interrupt(switch_status);
    init_music();
    init_timer();

    PORTB |= (1 << LED_GREEN);
    PORTB |= (1 << LED_RED);
    play_melody(&start_melody);
    PORTB &= ~(1 << LED_GREEN);
    PORTB &= ~(1 << LED_RED);

    while (true) {
        if (sleep)
        {
            sleep = false;
            sleep_cpu();
        }
    }

    return 0;
}

melody_t start_melody = {
    .length = 5,
    .tones = {
        TONE_A,
        TONE_D,
        TONE_G,
        TONE_E,
        TONE_B
    }
};

melody_t work_melody = {
    .length = 4,
    .tones = {
        TONE_A,
        TONE_E,
        TONE_F,
        TONE_D
    }
};

melody_t rest_melody = {
    .length = 4,
    .tones = {
        TONE_A,
        TONE_D,
        TONE_E,
        TONE_A
    }
};

melody_t end_melody = {
    .length = 6,
    .tones = {
        TONE_A,
        TONE_B,
        TONE_A,
        TONE_C,
        TONE_A,
        TONE_D
    }
};
