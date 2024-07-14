#include<stdio.h>
#include<unistd.h>
#include<fcntl.h> 

void main (void)
{
    int fd=0;

    fd = open("/sys/class/leds/input2::capslock",O_RDWR);
    printf("%d\n%d\n",fd,fd);

}



