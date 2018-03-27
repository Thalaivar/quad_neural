/**************************************************
                imu library
***************************************************/

#ifndef IMU_H
#define IMU_H

#include <roboticscape.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include <termios.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>	// for uint8_t types etc
#include <sys/stat.h>
#include <time.h>		// usleep, nanosleep
#include <math.h>		// atan2 and fabs
#include <signal.h>		// capture ctrl-c
#include <pthread.h>	// multi-threading
#include <linux/input.h>// buttons
#include <poll.h> 		// interrupt events
#include <sys/mman.h>	// mmap for accessing eQep
#include <sys/socket.h>	// udp socket
#include <netinet/in.h>	// udp socket
#include <sys/time.h>
#include <arpa/inet.h>	// udp socket
#include <ctype.h>		// for isprint()
#include <sys/select.h>	// for read timeout
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

#define RAD_TO_DEG 57.295
#define DEG_TO_RAD 0.01745

#define ROLL 0
#define PITCH 1
#define YAW 2

class IMU{
  public:
    rc_imu_config_t config;
    rc_imu_data_t   data;

    // angle rates in euler frames in DPS
    float euler_rates[3];

    // euler angles in radians
    float euler_angles[3];

    // body rates in DPS
    float body_rates[3];

	  IMU();

	  int init_imu();

    // call this to get latest euler angles
    void update();

	  // to get the initial yaw heading
	  void set_initialYaw();

	  // get yaw calibrated to initial yaw
	  float get_calYaw(float rawYaw);

	  float initialYaw;

    bool is_initialized;
    bool is_calibrated;
};
#endif
