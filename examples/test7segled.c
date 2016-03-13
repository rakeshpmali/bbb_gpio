#include "7segled.h"

void main(int argc, char **argv)
{
    int iNum = 0;
    while(1)
    {   
        if(iNum == 10)
            iNum = 0;

        setBlank();

        switch(iNum)
        {
            case 0:
                {
                    setNum_0();
                    break;
                }

            case 1:
                {
                    setNum_1();
                    break;
                }

            case 2:
                {
                    setNum_2();
                    break;
                }

            case 3:
                {
                    setNum_3();
                    break;
                }

            case 4:
                {
                    setNum_4();
                    break;
                }

            case 5:
                {
                    setNum_5();
                    break;
                }

            case 6:
                {
                    setNum_6();
                    break;
                }
            
            case 7:
                {
                    setNum_7();
                    break;
                }

            case 8:
                {
                    setNum_8();
                    break;
                }
            
            case 9:
                {
                    setNum_9();
                    break;
                }

            default:
                {
                }
        }
        
        DELAY_SECONDS(1);
        ++iNum;
    }
}
