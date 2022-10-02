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

#ifndef MUSIC_H_
#define MUSIC_H_

#define	SOUND PB0

#define TONE_A 42
#define TONE_AS 39
#define TONE_B 37
#define TONE_C 71
#define TONE_CS 67
#define TONE_D 63
#define TONE_DS 59
#define TONE_E 56
#define TONE_F 53
#define TONE_FS 50
#define TONE_G 47
#define TONE_GS 44

#define DELAY 250

typedef struct melody_s {
    uint8_t length;
    uint8_t tones[];
} melody_t;

void
init_music(void);

void
play_melody(const melody_t *melody);


#endif
