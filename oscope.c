#include <avr/io.h>
#include <avr/iom168.h>
#include <util/delay.h>
#include <util/setbaud.h>

#include "oscope.h"

#define SET_BIT(byte, bit) (byte |= (1 << (bit)))
#define CLEAR_BIT(byte, bit) (byte &= ~(1 << (bit)))

#define DELAY_TIME_MS 10

/* start Usart module */
void initUsart() {
    SET_BIT(UCSR0B, TXEN0); // transmitter enable
    
    UBRR0H = UBRRH_VALUE; // Set baud, prob 9600
    UBRR0L = UBRRL_VALUE;

    CLEAR_BIT(UCSR0A, U2X0); // do not use 2x transmission

    CLEAR_BIT(UCSR0C, USBS0); // 1 stop bit
    UCSR0C |= ((1 << UCSZ00) | (1 << UCSZ01)); // 8 data bits
}

/* start adc*/
void initAdc() {
    ADMUX &= ~((1 << REFS0) | (1 << REFS1)); // use external voltage ref
    SET_BIT(ADMUX, ADLAR); // 'round' off conversions to 8 bits to fit a byte

    SET_BIT(ADCSRA, ADEN); // enable adc
    SET_BIT(ADCSRA, ADATE); // enable autotrigger
    ADCSRA |= ((1 << ADPS0) | (1 << ADPS1)); // set prescaler to 8, clock adc at 125kHz
}

/* takes reading off adc */
uint8_t read() {
    return ADCH;
}

/* sends reading to serial by usart */
void sendToSerial(uint8_t reading) {
    loop_until_bit_is_clear(UCSR0A, UDRE0); // wait for transmitter to clear
    UDR0 = reading; // transmit reading
}

int main(void) {
    initUsart();
    initAdc();

    SET_BIT(ADCSRA, ADSC); // Start adc conversion

    while (1) {
        sendToSerial(read()); // send data to script to be processed for display
    }

    return 0;
}

