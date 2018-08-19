#include <avr/io.h>
#include <avr/iom168.h>
#include <util/delay.h>
#include <util/setbaud.h>

#include "oscope.h"

#define SET_BIT(byte, bit) (byte |= (1 << (bit)))
#define CLEAR_BIT(byte, bit) (byte &= ~(1 << (bit)))
 
/* start Usart module */
void initUsart() {
    SET_BIT(UCSR0B, TXEN0); // transmitter enable
    
    UBRR0H = UBRRH_VALUE; // Set baud
    UBRR0L = UBRRL_VALUE;

    CLEAR_BIT(UCSR0A, U2X0);

    CLEAR_BIT(UCSR0C, USBS0); // 1 stop bit
    UCSR0C |= ((1 << UCSZ00) | (1 << UCSZ01)); // 8 data bits
}

/* start adc*/
void initAdc();

/* takes reading off adc, return actual voltage */
uint8_t read();

/* sends reading to serial by usart */
void sendToSerial(uint8_t reading) {

}

/* start adc*/
void initAdc() {

}

/* takes reading off adc, return actual voltage */
uint8_t read() {

}

/* sends reading to serial by usart */
void sendToSerial(uint8_t reading) {

}
