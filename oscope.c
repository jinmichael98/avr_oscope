#include <avr/io.h>
#include <avr/iom168.h>
#include <util/delay.h>

#include "oscope.h"

 /* start Usart module */
void initUsart() {
# /* start Usart module */
void initUsart();

/* start adc*/
void initAdc();

/* takes reading off adc, return actual voltage */
uint8_t read();

/* sends reading to serial by usart */
void sendToSerial(uint8_t reading);
if USE_2X
    ADCSRA
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
