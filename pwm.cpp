#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (int argc, char* argv[]) {

  if (argc < 2) {
    fprintf(stderr,"Value, please!\n");
    return -1;
  }
  
  if (wiringPiSetup () == -1)
    exit (1) ;
  
  pinMode (1, PWM_OUTPUT);
  
  pwmWrite (1, atoi(argv[1]));
  
  return 0 ;
}
