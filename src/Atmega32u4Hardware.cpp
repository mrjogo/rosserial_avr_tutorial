#include "Atmega32u4Hardware.h"

USB_ClassInfo_CDC_Device_t Atmega32u4Hardware::VirtualSerial_CDC_Interface = {
  {
    0,

    CDC_TX_EPNUM,
    CDC_TXRX_EPSIZE,
    false,

    CDC_RX_EPNUM,
    CDC_TXRX_EPSIZE,
    false,

    CDC_NOTIFICATION_EPNUM,
    CDC_NOTIFICATION_EPSIZE,
    false,
  },
};

/** Event handler for the library USB Configuration Changed event. */

void EVENT_USB_Device_ConfigurationChanged(void)
{
  CDC_Device_ConfigureEndpoints(&Atmega32u4Hardware::VirtualSerial_CDC_Interface);
}



/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{
  CDC_Device_ProcessControlRequest(&Atmega32u4Hardware::VirtualSerial_CDC_Interface);
}
