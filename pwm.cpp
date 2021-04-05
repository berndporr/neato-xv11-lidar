#include <pigpiod_if2.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (int argc, char* argv[]) {

	const int GPIO = 18;

	int v = 0;
	
	if (argc > 1) {
		v = atoi(argv[1]);
	}
  
	int pi = pigpio_start(NULL,NULL);
	if ( pi < 0 ) {
		fprintf(stderr,"Could not connect to the daemon.\n");
		exit(1);
	}
  
	set_mode(pi,GPIO,PI_OUTPUT);
	
	if (v > 100) v = 100;
  
	set_PWM_dutycycle(pi,18,v);

	getchar();

	set_PWM_dutycycle(pi,18,0);

	pigpio_stop(pi);
	
	return 0 ;
}
