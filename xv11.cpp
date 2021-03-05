#include "xv11.h"
#include <math.h>

void Xv11::stop() {
	running = 0;
	if (nullptr != worker) {
		worker->join();
		delete worker;
		worker = nullptr;
	}
}

float Xv11::rpm(unsigned char *packet) { // 22 bytes in the packet
    return float(packet[2] | ((packet[3]<<8))) / 64.f;
}

bool Xv11::verify_packet_checksum(unsigned char *packet) { // 22 bytes in the packet
    int checksum32 = 0;
    for (int i=0; i<10; i++)
        checksum32 = (checksum32<<1) + packet[2*i] + (packet[2*i+1]<<8);
    return packet[20]+(packet[21]<<8) == (((checksum32 & 0x7FFF) + (checksum32 >> 15)) & 0x7FFF);
}

int Xv11::count_errors(unsigned char *buf) { // 1980 bytes in the buffer (90 packets)
    int nb_err = 0;
    for (int i=0; i<90; i++) {
        nb_err += !verify_packet_checksum(buf+i*22);
    }
    return nb_err;
}

// no return/max range/too low of reflectivity
bool Xv11::invalid_data_flag(unsigned char *data) { // 4 bytes in the data buffer
    return (data[1] & 0x80) >> 7;
}

// object too close, possible poor reading due to proximity; kicks in at < 0.6m
bool Xv11::strength_warning_flag(unsigned char *data) { // 4 bytes in the data buffer
    return (data[1] & 0x40) >> 6;
}

int Xv11::dist_mm(unsigned char *data) { // 4 bytes in the data buffer
    return data[0] | (( data[1] & 0x3F) << 8); // 14 bits for the distance
}

int Xv11::signal_strength(unsigned char *data) { // 4 bytes in the data buffer
    return data[2] | (data[3] << 8); // 16 bits for the signal strength
}

void Xv11::start(const char *serial_port) {
	if (nullptr != worker) return;
	tty_fd = open(serial_port, O_RDWR);
	if (tty_fd < 0) {
		throw "Could not open serial port";
	}
// 115200 baud 8n1 blocking read
	struct termios tty_opt;
	memset(&tty_opt, 0, sizeof(tty_opt));
	tty_opt.c_cflag = CS8 | CLOCAL | CREAD;
// CS8: 8n1, CLOCAL: local connection, no modem contol, CREAD: enable receiving characters
	tty_opt.c_iflag = 0;
	tty_opt.c_oflag = 0;
	tty_opt.c_lflag = 0;     // non-canonical mode
	tty_opt.c_cc[VMIN] = 1;  // blocking read until 1 character arrives
	tty_opt.c_cc[VTIME] = 0; // inter-character timer unused
	cfsetospeed(&tty_opt, B115200);
	cfsetispeed(&tty_opt, B115200);
	tcsetattr(tty_fd, TCSANOW, &tty_opt);

	if (wiringPiSetup () == -1) {
		throw "Could not set up wiring Pi. Might need to run as sudo.";
	}
  
	pinMode (1, PWM_OUTPUT);

	updateMotorPWM();
	
	worker = new std::thread(Xv11::run,this);
}

void Xv11::updateMotorPWM() {
	if (motorDrive > 500) motorDrive = 500;
	pwmWrite (1, motorDrive);
	//fprintf(stderr,"motorDrive = %d\n",motorDrive);
}

void Xv11::raw2data(unsigned char *buf) {
	currentRPM = rpm(buf);
	motorDrive = motorDrive + (int)round((desiredRPM - currentRPM) * loopRPMgain);
	updateMotorPWM();
	bool dataAvailable = false;
	for (int p=0; p<90; p++) { // for all 90 packets
		for (int i=0; i<4; i++) { // process 4 chunks per packet
			unsigned char *data = buf + p*22 + 4 + i*4; // current chunk pointer
			bool invalid = invalid_data_flag(data);
			if (!invalid) {
				int j = (p*4+i);
				double angle = (double)j / 360.0 * M_PI * 2 - M_PI;
				double dist = dist_mm(data);
				if (dist > 0) {
					//fprintf(stderr,"%d,phi=%f,r=%f\n",j,angle,dist);
					xv11data[currentBufIdx][j].phi = angle;
					xv11data[currentBufIdx][j].r = dist;
					xv11data[currentBufIdx][j].x = cos(angle) * dist;
					xv11data[currentBufIdx][j].y = sin(angle) * dist;
					xv11data[currentBufIdx][j].valid = true;
					dataAvailable = true;
				} else {
					xv11data[currentBufIdx][j].valid = false;
				}
			}
		}
	}
	if ( (dataAvailable) && (nullptr != dataInterface) ) {
		dataInterface->newScanAvail(xv11data[currentBufIdx]);
	}
	currentBufIdx = !currentBufIdx;
}

void Xv11::run(Xv11* xv11) {
	unsigned char buf[1980];
	while (xv11->running) {
		if (1==read(xv11->tty_fd, buf, 1) &&
		    0xFA==buf[0] &&
		    1==read(xv11->tty_fd, buf+1, 1) &&
		    0xA0==buf[1]) {
			// find the header 0xFA 0xA0
			for (int idx=2; idx<1980; idx++)
				// register all the 360 readings (90 packets, 22 bytesh each)
				if (1!=read(xv11->tty_fd, buf+idx, 1)) break;
			if (!(xv11->count_errors(buf))) { // if no errors during the transmission
				xv11->raw2data(buf);  // then print the data to the screen
			}
		}
	}
	xv11->motorDrive = 0;
	xv11->updateMotorPWM();
	close(xv11->tty_fd);
}
