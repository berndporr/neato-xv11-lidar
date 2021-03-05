#include "xv11.h"

class DataInterface : public Xv11::DataInterface {
public:
	void newScanAvail(XV11Data (&data)[Xv11::n]) {
		for(int i=0; i < Xv11::n; i++) {
			if (data[i].valid)
				printf("%f\t%f\t%f\t%f\n",
				       data[i].x,
				       data[i].y,
				       data[i].r,
				       data[i].phi);
		}
		fprintf(stderr,".");
	}
};

int main(int, char **) {
	Xv11 xv11;
	DataInterface dataInterface;
	xv11.registerInterface(&dataInterface);
	xv11.start();
	do {
	} while (!getchar());
	fprintf(stderr,"\n");
	xv11.stop();
}
