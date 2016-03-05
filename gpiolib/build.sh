#!/bin/sh
echo "Building ledBlink ..."
arm-linux-gnueabihf-gcc -o ledBlink.o ledBlink.c gpio.c
echo "Build Finished"
