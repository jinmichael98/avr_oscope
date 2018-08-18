 /* start Usart module */
void initUsart();

/* start adc*/
void initAdc();

/* takes reading off adc, return actual voltage */
uint8_t read();

/* sends reading to serial by usart */
void sendToSerial(uint8_t reading);

int main(void) {

}
