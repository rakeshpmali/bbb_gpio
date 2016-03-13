#include "7segled.h"

int init7SegLedDisplay()
{
    //Initialise GPIO pins for out operation
    if (0 != exportPin(LED_A)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_A, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);
    
    if (0 != exportPin(LED_B)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_B, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);
    
    if (0 != exportPin(LED_C)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_C, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    if (0 != exportPin(LED_D)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_D, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);
    
    if (0 != exportPin(LED_E)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_E, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);
    
    if (0 != exportPin(LED_F)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_F, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);

    if (0 != exportPin(LED_G)) 
        exit(EXIT_FAILURE);
    if (0 != setPinDirection(LED_G, GPIO_DIR_OUT))
        exit(EXIT_FAILURE);
        
    //all segments OFF
    if (0 != setPinValue(LED_A, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_B, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_D, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_E, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_F, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_G, GPIO_HIGH))
        exit(EXIT_FAILURE);

    return 0;
}

int setBlank()
{
    //all segments OFF
    if (0 != setPinValue(LED_A, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_B, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_D, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_E, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_F, GPIO_HIGH))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_G, GPIO_HIGH))
        exit(EXIT_FAILURE);

    return 0;
}

int setNum_0()
{
    if (0 != setPinValue(LED_A, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_B, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_D, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_E, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_F, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int setNum_1()
{
    if (0 != setPinValue(LED_B, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int setNum_2()
{
    if (0 != setPinValue(LED_A, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_B, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_D, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_E, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_G, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int setNum_3()
{
    if (0 != setPinValue(LED_A, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_B, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_D, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_G, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int setNum_4()
{
    if (0 != setPinValue(LED_B, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_F, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_G, GPIO_LOW))
        exit(EXIT_FAILURE);
    
    return 0;
}

int setNum_5()
{
    if (0 != setPinValue(LED_A, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_D, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_F, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_G, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int setNum_6()
{
    if (0 != setPinValue(LED_A, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_D, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_E, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_F, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_G, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int setNum_7()
{
    if (0 != setPinValue(LED_A, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_B, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int setNum_8()
{
    if (0 != setPinValue(LED_A, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_B, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_D, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_E, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_F, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_G, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}

int setNum_9()
{
    if (0 != setPinValue(LED_A, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_B, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_C, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_D, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_F, GPIO_LOW))
        exit(EXIT_FAILURE);
    if (0 != setPinValue(LED_G, GPIO_LOW))
        exit(EXIT_FAILURE);

    return 0;
}



