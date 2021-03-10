#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (int argc, char* argv[]) {

	int v = 0;
	
	if (argc > 1) {
		v = atoi(argv[1]);
	}
  
	if (wiringPiSetup () == -1)
		throw "Could not init WiringPI\n";
  
	pinMode (1, PWM_OUTPUT);
	
	if (v > 500) v = 500;
  
	pwmWrite (1, v);
	
	return 0 ;
}
