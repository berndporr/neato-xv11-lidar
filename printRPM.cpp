#include "xv11.h"

int main(int, char **) {
	Xv11 xv11;
	while (1) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		fprintf(stderr,"RPM = %f\n",xv11.getRPM());
	}
}
