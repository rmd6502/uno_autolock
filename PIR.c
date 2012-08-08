#include <avr/interrupt.h>
#include <avr/io.h>
#include "PIR.h"

volatile uint8_t PIR_State = 0;
PIR_Changed service_routine = 0;

void PIR_Init() {
    cli();
    // disable the UART
    UCSR1B &= ~(_BV(RXEN1) | _BV(TXEN1));
    // set the pin to an input
    DDRD &= ~_BV(3);
    // interrupt on either edge
    EICRA |= _BV(ISC30);
    EICRA &= ~_BV(ISC31);
    // enable the interrup
    EIMSK |= _BV(INT3);
    // clear the interrupt flag
    EIFR = _BV(INTF3);
    sei();
}

ISR(INT3_vect) {
    PIR_State = (PIND & _BV(3)) >> 3;
    if (service_routine != 0) {
        service_routine(PIR_State);
    }
}
