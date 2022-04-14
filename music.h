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
