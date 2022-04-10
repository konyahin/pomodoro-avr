#define BUTTON PB3
#define INTERRUPT PCINT3

void
init_interrupt(void (*on_press) (void));
