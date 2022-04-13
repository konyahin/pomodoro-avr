#ifndef INTERRUPTH
#define INTERRUPTH

#define BUTTON PB1
#define INTERRUPT PCINT1

void
init_interrupt(void (*on_press) (void));

#endif
