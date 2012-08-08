#include <avr/interrupt.h>

#include "Timer.h"

volatile uint32_t millis;
void Timer_Init() {
    // CTC mode, TOP = OCR0A
    TCCR0A = 2;
    // No clock for now
    TCCR0B = 0;
    // 250 * 64 = 16000, overflow every ms
    OCR0A = 125;
    TCNT0 = 0;
    cli();
    // enable overflow interrupt
    TIMSK0 = _BV(TOIE0);
    // clear interrupt flag
    TIFR0 = _BV(TOV0);
    sei();
    // start the timer with 64 divider
    TCCR0B = 3;
}

ISR(TIMER0_OVF_vect) {
    ++millis;
}
