#include "stdheader.h"

#define LED0 0
#define LED1 1
#define ON 1
#define OFF 0

void error_report()
{
    printf("Invalid Operation !!!\n");
    printf("Usage :\n");
    printf("       led LED0 ON\n");
    printf("       led LED1 ON\n");
    printf("       led LED0 OFF\n");
    printf("       led LED1 OFF\n");
    exit(-1);
}
int led_ctrl(u8 led_num, u8 cmd)
{
    int fd = 0;
    if (fd = open("/dev/leds", O_RDWR | O_NOCTTY | O_NDELAY) < 0)
        return -1;
    else
    {
        ioctl(fd, cmd, led_num);
    }
    close(fd);
    return 0;
}
int led_twinkle(u8 led_num, u8 mode)
{
    int fd = 0;
    int sleep_time = 50000;
    switch (mode)
    {
    case 1:
        sleep_time = 50000;
        break;
    case 0:
        sleep_time = 990000;
        break;

    default:
        return -1;
        break;
    }
    if (fd = open("/dev/leds", O_RDWR | O_NOCTTY | O_NDELAY) < 0)
        return -1;
    else
    {
       
            ioctl(fd, ON, led_num);
            usleep(sleep_time);
            ioctl(fd, OFF, led_num);
            usleep(sleep_time);
        
    }
    close(fd);
    return 0;
}

int main(int argc, char **argv)
{
    if(fork()==0)
    while (1)
    {
        led_twinkle(LED0,1);
        printf("led0000000000    \n");
    }
    else
    while (1)
    {
        led_twinkle(LED1,0);
         printf("led11111111111    \n");
    }
    
    exit(0);
}