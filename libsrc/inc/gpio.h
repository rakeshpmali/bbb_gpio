#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GPIO_DIR_OUT    ("out")
#define GPIO_DIR_IN     ("in")
#define GPIO_HIGH       (1)
#define GPIO_LOW        (0)

#define MAX_PIN_COUNT   (44)
#define PORT_PIN_LENGTH (5)

#define P8_3   ("P8_3")
#define P8_4   ("P8_4")
#define P8_5   ("P8_5")
#define P8_6   ("P8_6")
#define P8_7   ("P8_7")
#define P8_8   ("P8_8")
#define P8_9   ("P8_9")
#define P8_10   ("P8_10")
#define P8_11   ("P8_11")
#define P8_12   ("P8_12")
#define P8_13   ("P8_13")
#define P8_14   ("P8_14")
#define P8_15   ("P8_15")
#define P8_16   ("P8_16")
#define P8_17   ("P8_17")
#define P8_18   ("P8_18")
#define P8_19   ("P8_19")
#define P8_20   ("P8_20")
#define P8_21   ("P8_21")
#define P8_22   ("P8_22")
#define P8_23   ("P8_23")
#define P8_24   ("P8_24")
#define P8_25   ("P8_25")
#define P8_26   ("P8_26")
#define P8_27   ("P8_27")
#define P8_28   ("P8_28")
#define P8_29   ("P8_29")
#define P8_30   ("P8_30")
#define P8_31   ("P8_31")
#define P8_32   ("P8_32")
#define P8_33   ("P8_33")
#define P8_34   ("P8_34")
#define P8_35   ("P8_35")
#define P8_36   ("P8_36")
#define P8_37   ("P8_37")
#define P8_38   ("P8_38")
#define P8_39   ("P8_39")
#define P8_40   ("P8_40")
#define P8_41   ("P8_41")
#define P8_42   ("P8_42")
#define P8_43   ("P8_43")
#define P8_44   ("P8_44")
#define P8_45   ("P8_45")
#define P8_46   ("P8_46")

#define PIN_MODE_DEFAULT ("default")

#define DELAY_SECONDS(d) (usleep(d*1000000))
#define DELAY_MILLI_SECONDS(d) (usleep(d*1000))
#define DELAY_MICRO_SECONDS(d) (usleep(d))

// structure having pin details
typedef struct
{
    char chPin[PORT_PIN_LENGTH];          // BBB PIN. e.g. P8.39
    //char chGpioPin[8];      // mode 7 name. e.g. GPIO2_12 
    int iPin;               // pin = gpio base * 32 + pin number
                            // e.g. for P8.39, mode 7 is GPIO2_12 then, pin = 2 * 32 + 12 = 76
} PIN;

// Table containing details of all pins
static PIN PIN_TABLE[MAX_PIN_COUNT] = 
{
    { P8_3, /*GPIO1_6*/ 38 },
    { P8_4, /*GPIO1_7*/ 39 },
    { P8_5, /*GPIO1_2*/ 34 },
    { P8_6, /*GPIO1_3*/ 35 },
    { P8_7, /*GPIO2_2*/ 66 },
    { P8_8, /*GPIO2_3*/ 67 },
    { P8_9, /*GPIO2_5*/ 69 },
    { P8_10, /*GPIO2_4*/ 68 },
    { P8_11, /*GPIO1_13*/ 45 },
    { P8_12, /*GPIO1_12*/ 44 },
    { P8_13, /*GPIO0_23*/ 23 },
    { P8_14, /*GPIO0_26*/ 26 },
    { P8_15, /*GPIO1_15*/ 47 },
    { P8_16, /*GPIO1_14*/ 46 },
    { P8_17, /*GPIO0_27*/ 27 },
    { P8_18, /*GPIO2_1*/ 65 },
    { P8_19, /*GPIO0_22*/ 22 },
    { P8_20, /*GPIO1_31*/ 63 },
    { P8_21, /*GPIO1_30*/ 62 },
    { P8_22, /*GPIO1_5*/ 37 },
    { P8_23, /*GPIO1_4*/ 46 },
    { P8_24, /*GPIO1_1*/ 33 },
    { P8_25, /*GPIO1_0*/ 32 },
    { P8_26, /*GPIO2_29*/ 93 },
    { P8_27, /*GPIO2_22*/ 86 },
    { P8_28, /*GPIO2_24*/ 88 },
    { P8_29, /*GPIO2_23*/ 87 },
    { P8_30, /*GPIO2_25*/ 89 },
    { P8_31, /*GPIO0_10*/ 10 },
    { P8_32, /*GPIO0_11*/ 11 },
    { P8_33, /*GPIO0_9*/ 9 },
    { P8_34, /*GPIO2_17*/ 81 },
    { P8_35, /*GPIO0_8*/ 8 },
    { P8_36, /*GPIO2_16*/ 80 },
    { P8_37, /*GPIO2_14*/ 78 },
    { P8_38, /*GPIO2_15*/ 79 },
    { P8_39, /*GPIO2_12*/ 76 },
    { P8_40, /*GPIO2_13*/ 77 },
    { P8_41, /*GPIO2_10*/ 74 },
    { P8_42, /*GPIO2_11*/ 75 },
    { P8_43, /*GPIO2_8*/ 72 },
    { P8_44, /*GPIO2_9*/ 73 },
    { P8_45, /*GPIO2_6*/ 70 },
    { P8_46, /*GPIO2_7*/ 71 }
};

// Function Declerations
int setPinMode(char *pchPin, char *pchMode);
int exportPin(char *pchPin);
int setPinDirection(char *pchPin, char *pchDir);
int setPinValue(char *pchPin, int iValue);
int getPin(char *pchPin);
int getPinValue(char *pchPin, int *iValue);
