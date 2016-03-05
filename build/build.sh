#Build examples
ARMGCC=arm-linux-gnueabihf-gcc
BIN_LOC=../bin
EXAMPLE_LOC=../examples
LIB_SRC=../libsrc/src/gpio.c
LIB_INC=../libsrc/inc

$ARMGCC -I$LIB_INC -o $BIN_LOC/$1.o $EXAMPLE_LOC/$1.c $LIB_SRC
