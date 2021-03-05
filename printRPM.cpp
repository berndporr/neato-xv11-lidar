#include "xv11.h"

int main(int, char **) {
	Xv11 xv11;
	xv11.start();
	do {
		fprintf(stderr,"RPM = %f\n",xv11.getRPM());
	} while (getchar() != 27);
}
