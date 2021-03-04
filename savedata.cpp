#include "xv11.h"

int main(int, char **) {
	Xv11 xv11;
	while (1) {
		for(int i=0; i < xv11.n; i++) {
			if (xv11.getXYData()[i].valid)
				printf("%f\t%f\n",
				       xv11.getXYData()[i].x,
				       xv11.getXYData()[i].y);
		}
	}
}
