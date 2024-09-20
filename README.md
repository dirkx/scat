# scat

Serial cat(1) utility that allows for setting the baudrate.
Simple utility that allows for 'cat'ting a serial device 
with a specific baud rate. Useful in combination with
for example a flashing tool. 

Background - on *BSD and MacOSX using normal 'cat' of a 
serial device (re)sets the terminal settings back to the
default; so you need to do a 'stty -F ..' each time 
after opening. 

# Usage

Example use

     scat /dev/cu.usb-serial0001 115200

Or when you want to re-connect straight after an upload

     arduino-cli upload --port /dev/cu.usbserial-0001 --fqbn esp32:esp32:esp32wrover Blink && scat  /dev/cu.usbserial-0001 9600

# Compiling

Typically use something like

     clang -o scat ./scat.c

or

     gcc -o scat ./scat.c

or

     cc -o scat ./scat.c
