
# scat

Simple utility that allows for 'cat'ting a serial device 
with a specific baud rate. Useful in combination with
for example a flashing tool. 

Background - on *BSD and MacOSX using normal 'cat' of a 
serial device (re)sets the terminal settings back to the
default; so you need to do a 'stty -F ..' from another
terminal each time after opening. 

This utility avoids that the need for that. It just
lets you set the baudrate.

# Usage

Example use with a baudrate of 115200 as the default

     scat /dev/cu.usb-serial0001

or, for non default baudrates:

     scat /dev/cu.usb-serial0001 4800

Or when you want to re-connect straight after an upload

     arduino-cli upload --port /dev/cu.usbserial-0001 \
              --fqbn esp32:esp32:esp32wrover Blink && \
                  scat  /dev/cu.usbserial-0001 9600

I.e. attempt an upload and connect to the serial straight
afterwards if that was succesful.

# Compiling

Typically use something like

     clang -o scat ./scat.c

or

     gcc -o scat ./scat.c

or

     cc -o scat ./scat.c

# Bugs

Replies on OS sanity in its baudrate enum definitions to be the
same as the actual baudrate (see tsetattr(3), section on setting
and getting the baudrate). This app does not yet support things
such as 7E1; but picks up whatever is the default (8N1).
