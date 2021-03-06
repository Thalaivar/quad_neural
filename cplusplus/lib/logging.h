#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>

class Logging{
  private:
    FILE *attitude_data_file;
    FILE *channel_data_file;
    FILE *error_data_file;
	  FILE *s_data_file;
    FILE *ie_data_file;
    FILE *attitude_error_data_file;
	  FILE *desired_attitude_data_file;
	  FILE *desired_body_rates_data_file;
	  FILE *body_rates_data_file;
    FILE *control_input_data_file;
    FILE *pid_data_file;

  public:

    // to log attitude data
    int log_attitude(float roll, float pitch, float yaw);

	  int log_body_rates(float p, float q, float r);

  	int log_s(float sx, float sy, float sz);

    // to log channel outputs
    int log_channel_vals(int ch1, int ch2, int ch3, int ch4);

    // to log error in body rates
    int log_body_rate_error(float wx, float wy, float wz);

    // to log intergral body rate error
    int log_ie_body_rate_error(float ie_wx, float ie_wy, float ie_wz);

    // to log angle error
    int log_attitude_error(float ex, float ey, float ez);

	  int log_desired_attitude(float roll, float pitch, float yaw);

	  int log_desired_body_rates(float wx_d, float wy_d, float wz_d);

    int log_control_inputs(float u_phi, float u_theta, float u_psi);

    int log_pid_outputs(float p, float i, float d);

    // to keep track of logging fail
    int log_fail_pid = 0;
    int log_fail_attitude = 0;
    int log_fail_channel = 0;
    int log_fail_body_rate_error = 0;
    int log_fail_ie_body_rate_error = 0;
	  int log_fail_s = 0;
    int log_fail_attitude_error = 0;
	  int log_fail_desired_attitude = 0;
	  int log_fail_desired_body_rates = 0;
	  int log_fail_body_rates = 0;
    int log_fail_control_inputs = 0;

    // to check if logging is ready
    bool is_initialised;

    Logging();
    ~Logging();

};
#endif
