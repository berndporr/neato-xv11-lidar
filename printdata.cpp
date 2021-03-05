#include "xv11.h"

class Xv11Print : public Xv11 {
public:
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
		fprintf(stderr,"\n");
	}
};

int main(int, char **) {
	Xv11Print xv11;
	xv11.start();
	do {
	} while (!getchar());
	fprintf(stderr,"\n");
	xv11.stop();
}
