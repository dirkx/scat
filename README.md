# scat

Serial cat(1) utility that allows for setting the baudrate.
Simple utility that allows for 'cat'ting a serial device 
with a specific baud rate. Useful in combination with
for example a flashing tool. 

Background - on *BSD and MacOSX using normal 'cat' of a 
serial device (re)sets the terminal settings back to the
default; so you need to do a 'stty -F ..' each time 
after opening. 
