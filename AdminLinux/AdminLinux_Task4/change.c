#include<stdio.h>
#include<unistd.h>
#include<fcntl.h> 


int main()
{
    char* v0 = "0";
    char* v1 = "1";

    char read = 0;

    int fd = 0;

    FILE *file = fopen("/sys/class/leds/input2::capslock/brightness", "r");

    fscanf(file, " %c", &read);

    printf("%c\n", read);
    fclose(file);

    fd = open("/sys/class/leds/input2::capslock/brightness", O_RDWR);


    if(read == *v0)
    {
        write(fd, v1, 1);
        
    }
    else
    {
        write(fd, v0, 1);
      
    }

    return 0;

}