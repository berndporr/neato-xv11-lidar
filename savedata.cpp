#include "xv11.h"

class Xv11Print : public Xv11 {
	void newScanAvail() {
		for(int j=0; j<10; j++) {
			for(int i=0; i < n; i++) {
				if (getXYData()[i].valid)
					printf("%f\t%f\t%f\t%f\n",
					       getXYData()[i].x,
					       getXYData()[i].y,
					       getAngleDistData()[i].r,
					       getAngleDistData()[i].phi);
			}
		}
		fprintf(stderr,".");
	}
};

int main(int, char **) {
	Xv11Print xv11;
	do {
		sleep(1);
	} while (getchar() != 27);
	fprintf(stderr,"\n");
}
