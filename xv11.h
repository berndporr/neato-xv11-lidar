#ifndef XV11_H
#define XV11_H

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <wiringPi.h>
#include <thread>
#include <mutex>

/**
 * One of the 360 distance datapoints
 **/
class XV11Data {
public:
	/**
	 * Distance in mm
	 **/
	double r;
	
	/**
	 * Angle in rad with phi=0 in front of the robot
	 **/
	double phi;

	/**
	 * X position where positive values are in front
	 * of the robot and negative behind.
	 **/
	double x;

	/**
	* Y position where positive values are left in front of the
	* robot and negative right in front of the robot.
	**/
	double y;

	/**
	 * Signal strength as a value between 0 and 1.
	 **/
	double signal_strength = 0;

	/**
	 * Flag if the object is too close.
	 **/
	bool too_close = false;

	/**
	 * Flag if the reading is valid
	 **/
	bool valid = false;
};


/**
 * Class to continously acquire data from the LIDAR
 **/
class Xv11 {
public:
	/**
	 * Number of distance readings during one 360 degree
	 * rotation. So we get one reading per degree.
	 **/
	static const unsigned nDistance = 360;

	/**
	 * Starts the data acquisition by spinning up the
	 * motor and then saving the data in the current
	 * buffer and providing the data via the callback.
	 * The default RPM of the motor is 250 but can be
	 * roughly betweeen 200 and 300. The serial port
	 * is the one which talks to the XV11.
	 **/
	void start(const char *serial_port = "/dev/serial0",
		   const unsigned rpm = 250);
		   
	/**
	 * Stops the data acquisition
	 **/
	void stop();

	/**
	 * Destructor which stops the motor and the data acquisition thread.
	 **/
	~Xv11() {
		stop();
	}

	/**
	 * Callback interface which needs to be implemented by the user.
	 **/
	struct DataInterface {
		virtual void newScanAvail(XV11Data (&)[Xv11::nDistance]) = 0;
	};

	/**
	 * Register the callback interface here to receive data.
	 **/
	void registerInterface(DataInterface* di) {
		dataInterface = di;
	}

	/**
	 * Returns the current databuffer which is not being written to.
	 **/
	inline XV11Data (&getCurrentData())[nDistance]  {
		readoutMtx.lock();
		return xv11data[!currentBufIdx];
		readoutMtx.unlock();
	}

	/**
	 * Returns the current RPM
	 **/
	double getRPM() { return (double)currentRPM; }

private:
	static const int maxPWM = 500;
	float desiredRPM = 250;
	const float loopRPMgain = 0.02f;
	static const int nPackets = 90;
	DataInterface* dataInterface = nullptr;
	float rpm(unsigned char *packet);
	bool verify_packet_checksum(unsigned char *packet);
	unsigned count_errors(unsigned char *buf);
	bool invalid_data_flag(unsigned char *data);
	bool strength_warning_flag(unsigned char *data);
	unsigned dist_mm(unsigned char *data);
	unsigned signal_strength(unsigned char *data);
	void raw2data(unsigned char *buf);
	void updateMotorPWM();
	static void run(Xv11* xv11);
	int tty_fd = 0;
	bool running = true;
        unsigned motorDrive = 250;
	XV11Data xv11data[2][nDistance];
	std::thread* worker = nullptr;
	float currentRPM = 0;
	unsigned currentBufIdx = 0;
	std::mutex readoutMtx;
};

#endif
