#ifndef _ATMEGA32U4_HARDWARE_H
#define _ATMEGA32U4_HARDWARE_H

extern "C" {
  #include "Descriptors.h"
  #include "avr_time.h"
  #include <LUFA/Drivers/USB/USB.h>
}


class Atmega32u4Hardware {
  public:
    Atmega32u4Hardware() {}

    void init() {
      avr_time_init();
      USB_Init();
      sei();
    }

    int read() {
      return CDC_Device_ReceiveByte(&VirtualSerial1_CDC_Interface);
    }

    void write(uint8_t* data, int length) {
      CDC_Device_SendData(&VirtualSerial1_CDC_Interface, (char *)data, (uint16_t)length);
    }

    unsigned long time() {
      return avr_time_now();
    }

    static USB_ClassInfo_CDC_Device_t VirtualSerial1_CDC_Interface;
};

void EVENT_USB_Device_ConfigurationChanged(void);
void EVENT_USB_Device_ControlRequest(void);

#endif
