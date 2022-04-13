#ifndef TIMERH
#define TIMERH

void
init_timer(void);

void
set_timer_callback(uint8_t min, void (*call) (void));

#endif
