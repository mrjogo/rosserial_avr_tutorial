#include <avr/io.h>

#define BAUD 57600
#define UBRR_VAL ((F_CPU / (16UL * BAUD)) - 1)


// Initialize the UART
void avr_uart_init(void)
{
  // Enable bidirectional UART
  UCSR1B |= _BV(RXEN1) | _BV(TXEN1);
  // Use 8-bit characters
  UCSR1C |= _BV(UCSZ10) | _BV(UCSZ11);
  // Set the Baud rate
  UBRR1H = (UBRR_VAL >> 8);
  UBRR1L = UBRR_VAL;
}


// Send one char (blocking)
void avr_uart_send_byte(uint8_t tx_byte)
{
  // Wait to be able to transmit
  while((UCSR1A & _BV(UDRE1)) == 0)
    asm volatile("nop"::);
  // Put the data into the send buffer
  UDR1 = tx_byte;
}


// Get one char if available, otherwise -1
int16_t avr_uart_receive_byte(void)
{
  if((UCSR1A & _BV(RXC1)) != 0)
  {
    return UDR1;
  }
  else
  {
    return -1;
  }
}
