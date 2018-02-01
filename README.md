BeagleCopter
=============

Implementation of sliding mode control on a quadrotor
-----------------------------------------------------

Chosen hardware (obviously):    BeagleBone Blue

Current to-do list: 
* Make the motors library and include arming, output, etc.
* Comms. with GCS, to integrate MAVLink or not?
* Data logging
* pre-arm checks to be made, also failsafes
* AHRS to be set up along with filtering
* **Need to evaluate the real time capabilities of PREEMPT_RT kernel currently on BeagleBone.** Learrning and          implimenting pthreading and priority control?
* Parameter handling???

To be includes in pre-arm checks:
-----------------------------------
* Check if IMU is reading data or not  
* Check if IMU is calibrated
* Check if motors are disarmed
* Check all inits

PPM with PRU
------------

We will use BeagleBone PRU to read PPM signal. Its nearly impossible rn to write code for PRU, so one possiblilty is: https://github.com/ArduPilot/ardupilot/tree/master/Tools/Linux_HAL_Essentials
