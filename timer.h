#ifndef TIMER_H_
#define TIMER_H_

void
init_timer(void);

void
set_timer_callback(uint8_t min, void (*call) (void));

#endif
