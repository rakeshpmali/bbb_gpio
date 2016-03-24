#include "lcd.h"

int lcdScrollText(char *pchText, int iDelayMilliSec);

void main(int argc, char **argv)
{
    lcdInit();

    lcdDisplayText("***********\nBeagle Bone\n***********");
    DELAY_SECONDS(5);

    lcdClear();
    lcdGoToXY(2,5);
    lcdDisplayText("Rakesh");
    lcdGoToXY(3,5);
    lcdDisplayText("Mali");
    DELAY_SECONDS(5);
        
    lcdClear();
    lcdGoToXY(3,0);
    lcdScrollText("Scroll", 100);
}

int lcdScrollText(char *pchText, int iDelayMilliSec)
{
    int i = 0;
    lcdDisplayText(pchText);
    while(1)
    {
        for(i=0; i<(LCD_COLUMNS-strlen(pchText)); i++)
        {
            lcdSendCmd4Bit(SHIFT_DISP_RIGHT);
            DELAY_MILLI_SECONDS(iDelayMilliSec);
        }
        for(i=0; i<(LCD_COLUMNS-strlen(pchText)); i++) 
        {
            lcdSendCmd4Bit(SHIFT_DISP_LEFT);
            DELAY_MILLI_SECONDS(iDelayMilliSec);
        }
    }
    return 0;
}

