#include <avr/interrupt.h>

#include "Timer.h"

volatile uint32_t millis;
void Timer_Init() {
}

ISR(TIMER1_COMPA_vect) {
}
