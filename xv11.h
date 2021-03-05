#ifndef XV11_H
#define XV11_H

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <wiringPi.h>
#include <thread>

class AngleDistData {
public:
	double r;
	double phi;
	bool valid = false;
};


class XYData {
public:
	double x;
	double y;
	bool valid = false;
};
		

class Xv11 {
public:
	static const int n = 360;
	const double desiredRPM = 250;
	const double loopRPMgain = 0.05;
	AngleDistData (&getAngleDistData())[n] { return angleDistData; }
	XYData (&getXYData())[n] { return xyData; }
	float getRPM() { return currentRPM; }
	void start(const char *serial_port = "/dev/serial0");
	void stop();
	~Xv11() {
		stop();
	}
	virtual void newScanAvail() {};
private:
	float rpm(unsigned char *packet);
	bool verify_packet_checksum(unsigned char *packet);
	int count_errors(unsigned char *buf);
	bool invalid_data_flag(unsigned char *data);
	bool strength_warning_flag(unsigned char *data);
	int dist_mm(unsigned char *data);
	int signal_strength(unsigned char *data);
	void translate_data(unsigned char *buf);
	void updateMotorPWM();
	static void run(Xv11* xv11);
	int tty_fd = 0;
	int running = 1;
	int motorDrive = 250;
	AngleDistData angleDistData[n];
	XYData xyData[n];
	std::thread* worker;
	float currentRPM = 0;
};

#endif
