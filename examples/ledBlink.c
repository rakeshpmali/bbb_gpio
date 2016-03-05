#include "gpio.h"

// ledBlink.o P3_39 1000 10
void main(int argc, char **argv)
{
    int iMicroSecs = 0, iCount = 0;
    char chPin[PORT_PIN_LENGTH];
    
    if (argc == 4)
    {
        //iMicroSecs = atoi(argv[1]);
        strncpy(chPin, argv[1], strlen(argv[1]));
        iMicroSecs = strtol(argv[2], NULL, 10) * 1000;
        iCount = strtol(argv[3], NULL, 10);
    } else {
        printf("\nInvalid Arguments ! Defaulting to: \nPort = P8_39 \nBlink Rate = 1000 ms\nCount = 10\n");
        strncpy(chPin, P8_39, strlen(P8_39));
        iMicroSecs = 1000000;
        iCount = 10;
    }
    
    if (0 != setPinMode(chPin, PIN_MODE_DEFAULT))
        exit(EXIT_FAILURE);

    if (0 != exportPin(chPin)) 
        exit(EXIT_FAILURE);

    if (0 != setPinDirection(chPin, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);
    
    int i = 0;
    for (i = 0; i < iCount; i++) {
        if (0 != setPinValue(chPin, GPIO_HIGH))
            exit(EXIT_FAILURE);
        usleep(iMicroSecs);
        if (0 != setPinValue(chPin, GPIO_LOW))
            exit(EXIT_FAILURE);
        usleep(iMicroSecs);
    }
}

