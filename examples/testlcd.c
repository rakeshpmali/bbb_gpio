#include "gpio.h"

//LCD control pins
#define LCD_RW (P8_6)
#define LCD_RS (P8_8)
#define LCD_EN (P8_10)
//LCD data pins - higher nibble
#define LCD_D7 (P8_12)
#define LCD_D6 (P8_14)
#define LCD_D5 (P8_16)
#define LCD_D4 (P8_18)

/*
//LCD data pins - lower nibble
#define LCD_D3 (P8_20)
#define LCD_D2 (P8_22)
#define LCD_D1 (P8_24)
#define LCD_D0 (P8_26)
*/

int lcdInit();
int lcdSendCommand4Bit(int iCmdCode);
int lcdSendText(char *pchText);
int lcdGoToXY(int iX, int iY);
int lcdGoToAddr(int iAddr);
int lcdClear();
void printBinary(int n);

void main(int argc, char **argv)
{
    lcdInit();
    lcdSendText("* Beagle Bone *");
    lcdGoToXY(1,4);
    lcdSendText("Rakesh");
    lcdGoToXY(2,4);
    lcdSendText("Mali");
    lcdGoToXY(3,0);
    lcdSendText("***************");

}

int lcdInit()
{
    //Initialize the LCD pins
    //LCD control pins
    pinInit(LCD_RW, GPIO_DIR_OUT);
    pinInit(LCD_RS, GPIO_DIR_OUT);
    pinInit(LCD_EN, GPIO_DIR_OUT);
    //LCD data pins - higher nibble (4-bit mode)
    pinInit(LCD_D7, GPIO_DIR_OUT);
    pinInit(LCD_D6, GPIO_DIR_OUT);
    pinInit(LCD_D5, GPIO_DIR_OUT);
    pinInit(LCD_D4, GPIO_DIR_OUT);

    //wake up
    DELAY_MILLI_SECONDS(15);
    lcdSendCommand4Bit(0x33);
    DELAY_MILLI_SECONDS(15);
    lcdSendCommand4Bit(0x32);  // 4-bit mode 
    DELAY_MILLI_SECONDS(15);

    lcdSendCommand4Bit(0x28); //N = 1 (2 line display) F = 0 (5x8 characters)
    lcdSendCommand4Bit(0x08); //Display on/off control D=0,C=0, B=0 
    lcdSendCommand4Bit(0x01); //Clear Display
    lcdSendCommand4Bit(0x06); //Entry mode set - I/D = 1 (increment cursor) & S = 0 (no shift) 
    lcdSendCommand4Bit(0x0C); //Display on/off control. D = 1, C and B = 0. (Cursor and blink, last two bits)  
}

int lcdSendCommand4Bit(int iCmdCode)
{
    //printBinary(iCmdCode);
    //printf("\nlcdSendCommand4Bit(%d%d%d%d%d%d%d%d)\n", ((iCmdCode & (1<<7))>>7), ((iCmdCode & (1<<6))>>6), ((iCmdCode & (1<<5))>>5), ((iCmdCode & (1<<4))>>4), ((iCmdCode & (1<<3))>>3), ((iCmdCode & (1<<2))>>2), ((iCmdCode & (1<<1))>>1), ((iCmdCode & (1<<0))>>0));
    pinWrite(LCD_D4, ((iCmdCode & (1<<4))>>4));
    pinWrite(LCD_D5, ((iCmdCode & (1<<5))>>5));
    pinWrite(LCD_D6, ((iCmdCode & (1<<6))>>6));
    pinWrite(LCD_D7, ((iCmdCode & (1<<7))>>7));

    pinWrite(LCD_EN, GPIO_LOW);
    DELAY_MICRO_SECONDS(1);
    pinWrite(LCD_EN, GPIO_HIGH);
    DELAY_MICRO_SECONDS(1);
    pinWrite(LCD_EN, GPIO_LOW);
    DELAY_MICRO_SECONDS(1);

    pinWrite(LCD_D4, ((iCmdCode & (1<<0))>>0));
    pinWrite(LCD_D5, ((iCmdCode & (1<<1))>>1));
    pinWrite(LCD_D6, ((iCmdCode & (1<<2))>>2));
    pinWrite(LCD_D7, ((iCmdCode & (1<<3))>>3));

    pinWrite(LCD_EN, GPIO_LOW);
    DELAY_MICRO_SECONDS(1);
    pinWrite(LCD_EN, GPIO_HIGH);
    DELAY_MICRO_SECONDS(1);
    pinWrite(LCD_EN, GPIO_LOW);

    DELAY_MILLI_SECONDS(1); //LCD busy - wait
    //TODO: check busy flag here
}

void printBinary(int n)
{
    printf("\n\n");
    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");

        n >>= 1;
    }
    printf("\n");
}

int lcdSendText(char *pchText)
{
    while( *pchText)
    {
        pinWrite(LCD_RS, GPIO_HIGH);
        if(*pchText == '\n')
        {
            //lcdSendCommand4Bit();
        } else {    
            lcdSendCommand4Bit(*pchText++);
        }
    }
    
    return 0;
}

int lcdGoToXY(int iX, int iY)
{
    int iAddr = 0;
    switch(iX)
    {
        case 0: iAddr = 0x00; break; //Starting address of 1st line
        case 1: iAddr = 0x40; break; //Starting address of 2nd line
        case 2: iAddr = 0x14; break; //Starting address of 3rd line
        case 3: iAddr = 0x54; break; //Starting address of 4th line
        default: ; 
    }
   
    if (iY) 
        iAddr += --iY;
    printf("\nAddress = %X\n", iAddr);
    
    lcdGoToAddr(iAddr);
    
    return 0;
}

int lcdGoToAddr(int iAddr)
{
    int iCmd = 0x80|iAddr;
    pinWrite(LCD_RS, GPIO_LOW);
    lcdSendCommand4Bit(iCmd);
    
    return 0;
}

int lcdClear()
{
    pinWrite(LCD_RS, GPIO_LOW);
    lcdSendCommand4Bit(0x01);

    return 0;
}
