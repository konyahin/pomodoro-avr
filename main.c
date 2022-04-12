#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "interrupt.h"
#include "music.h"

#define LED_GREEN PB4
#define LED_RED PB3

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

melody_t start_work_melody = {
    .length = 4,
    .tones = {
        TONE_A,
        TONE_E,
        TONE_F,
        TONE_D
    }
};

melody_t start_rest_melody = {
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

enum status_e
{
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
            play_melody(&end_melody);
            break;
        case WORK:
            PORTB |= (1 << LED_RED);
            PORTB &= ~(1 << LED_GREEN);
            play_melody(&start_work_melody);
            break;
        case REST:
            PORTB &= ~(1 << LED_RED);
            PORTB |= (1 << LED_GREEN);
            play_melody(&start_rest_melody);
            break;
    }
}

void switch_status()
{
    if (++status > REST)
        status = ON;
    set_status();
}

int main(void)
{
    DDRB |= (1 << LED_GREEN);
    DDRB |= (1 << LED_RED);

    init_interrupt(switch_status);
    init_music();

    PORTB |= (1 << LED_GREEN);
    PORTB |= (1 << LED_RED);
    play_melody(&start_melody);
    PORTB &= ~(1 << LED_GREEN);
    PORTB &= ~(1 << LED_RED);

    while (true) {
    }

    return 0;
}
