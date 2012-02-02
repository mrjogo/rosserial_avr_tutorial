#include "ros.h"
#include "std_msgs/String.h"
// Include C headers (ie, non C++ headers) in this block
extern "C"
{
  #include <util/delay.h>
#include <avr/io.h>
#include "avr_time.h"
}

// Needed for AVR to use virtual functions
extern "C" void __cxa_pure_virtual(void);
void __cxa_pure_virtual(void) {}

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

int main()
{
  uint8_t r[3] = {-1, 'x', 'v'};
  int narf = -1;
  uint32_t ahora;
  uint32_t lasttime = 0UL;
  DDRE = 0xFF;
  // // Initialize ROS
  nh.initNode();
  nh.advertise(chatter);

  while(1)
  {
    // Send the message every second
    if(avr_time_now() - lasttime > 1000)
    {
      // PORTE ^= 0xFF;
      str_msg.data = hello;
      chatter.publish(&str_msg);
      lasttime = avr_time_now();
    }
    nh.spinOnce();
    // ahora = avr_time_now();
    // for(int i = 0; i < 4; i++)
    // {
    //   avr_uart_send_byte(((uint8_t *)&ahora)[i]);
    // }
  }

  return 0;
}

// int main (void)
// {
//     int8_t result = -1;
//     avr_uart_init();

//     while(1)
//     {
//       while(result == -1)
//         result = avr_uart_receive_byte();

//       avr_uart_send_byte((uint8_t)result);
//       avr_uart_send_byte('p');
//       avr_uart_send_byte('c');
//       result = -1;
//     }
   
//     return(0);
// }