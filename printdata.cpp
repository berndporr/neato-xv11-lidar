#include "xv11.h"

class DataInterface : public Xv11::DataInterface {
public:
	void newScanAvail(XV11Data (&data)[Xv11::n]) {
		for(XV11Data &data: data) {
			if (data.valid)
				printf("%f\t%f\t%f\t%f\n",
				       data.x,
				       data.y,
				       data.r,
				       data.phi);
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
