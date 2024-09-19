/* 
 *  Copyright 1999, 2024 Dirk-Willem van Gulik, all rights reserved
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  version 1.00  18/2/199
 *  version 1.01  updated for OSX, Sept 2024
 */
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

#define _(s) #s
#define S(X) { int e = (X); if (e) { perror("Failed  " _(X)); exit(1); }; }

int main(int argc, char ** argv) {
  struct termios tios;
  int baud = B115200;
  if (argc < 2 || argc > 3) {
	fprintf(stderr,"Syntax: %s <serial-device> [baudrate]\n", argv[0]);
	exit(1);
  };
  if (argc == 3) baud = atoi(argv[2]);
  int fd = open(argv[1], O_RDWR,0);
  S(tcgetattr(fd, &tios));
  S(cfsetspeed(&tios, baud));
  S(tcsetattr(fd,0,&tios));
  while(1) {
        unsigned char buff[1024];
        int n = read(fd,buff,sizeof(buff));
	if (n > 0) 
		write(0,buff,n);
        else if (n == 0) {
		fprintf(stderr,"Serial device %s closed\n", argv[1]);
                break;
        }
        else if (errno != EAGAIN && errno != EINTR) {
                perror("Error reading");
                exit(-errno);
        };
  };
  return 0;
}

