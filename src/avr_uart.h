#ifndef _AVR_UART_H_
#define _AVR_UART_H_

void avr_uart_init(void);
void avr_uart_send_byte(uint8_t tx_byte);
int16_t avr_uart_receive_byte(void);

#endif
