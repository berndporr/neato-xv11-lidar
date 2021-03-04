#include "xv11.h"

int main(int, char **) {
	Xv11 xv11;
	while (1) {
		for(int i=0; i < xv11.n; i++) {
			if (xv11.getAngleDistData()[i].valid)
				printf("r=%f, phi=%f\n",
				       xv11.getAngleDistData()[i].r,
				       xv11.getAngleDistData()[i].phi);
		}
	}
}
