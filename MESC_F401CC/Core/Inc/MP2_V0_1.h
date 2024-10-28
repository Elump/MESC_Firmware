/*
 * MP2_V0_1.h
 *
 *  Created on: Dec 16, 2022
 *      Author: HPEnvy
 */

#ifndef INC_MP2_V0_1_H_
#define INC_MP2_V0_1_H_
//Pick a motor for default
#define Max30	// Smops Test Motor, motor details are defined in MESC_MOTOR_DEFAULTS.h

#define PWM_FREQUENCY 20000
#define CUSTOM_DEADTIME 800 //ns

#define SHUNT_POLARITY 1.0f  //changed for IHM08

#define ABS_MAX_PHASE_CURRENT 25.0f
#define ABS_MAX_BUS_VOLTAGE 48.0f
#define ABS_MIN_BUS_VOLTAGE 10.0f
#define R_SHUNT 0.010f
#define OPGAIN 4.7f

#define R_VBUS_BOTTOM 9310.0f //changed for IHM08 //Vbus voltage sensors
#define R_VBUS_TOP 169000.0f  //changed for IHM08

#define HAS_DIFF_PHASE_RESISTORS
#ifdef HAS_DIFF_PHASE_RESISTORS
	#define R_VEMF_BOTTOM 2200.0f //changed for IHM08 //SMOPS: added separate BEMF gain
	#define R_VEMF_TOP 10000.0f  //changed for IHM08
#endif


#define MAX_ID_REQUEST 2.0f  //changed for IHM08
#define MAX_IQ_REQUEST 15.0f  //changed for IHM08

#define FIELD_WEAKENING_CURRENT 3.0f //This does not set whether FW is used, just the default current
#define FIELD_WEAKENING_THRESHOLD 0.8f

#define SEVEN_SECTOR		//Normal SVPWM implemented as midpoint clamp. If not defined, you will get 5 sector, bottom clamp
//#define DEADTIME_COMP		//This injects extra PWM duty onto the timer which effectively removes the dead time.
#define DEADTIME_COMP_V 10

//Inputs
#define GET_THROTTLE_INPUT _motor->Raw.ADC_in_ext1 = ADC_buffer[3]  // Throttle

#define USE_FIELD_WEAKENINGV2

//#define USE_LR_OBSERVER

/////////////////////Related to ANGLE ESTIMATION////////////////////////////////////////
//#define INTERPOLATE_V7_ANGLE

#define DEFAULT_SENSOR_MODE MOTOR_SENSOR_MODE_SENSORLESS

#define USE_HFI
#define HFI_VOLTAGE 4.0f
#define HFI_TEST_CURRENT 0.0f
#define HFI_THRESHOLD 2.5f
#define HFI45
#define DEFAULT_HFI_TYPE HFI_TYPE_NONE
//#define DEFAULT_HFI_TYPE HFI_TYPE_45
//#define DEFAULT_HFI_TYPE HFI_TYPE_D
//#define DEFAULT_HFI_TYPE HFI_TYPE_SPECIAL

//#define USE_HALL_START
#define HALL_VOLTAGE_THRESHOLD 1.5f

//#define USE_SPI_ENCODER //Only supports TLE5012B in SSC mode using onewire SPI on SPI3 F405...
#define POLE_PAIRS 7
#define ENCODER_E_OFFSET 14500
#define POLE_ANGLE (65536/POLE_PAIRS)
//#define LOGGING

//#define USE_SALIENT_OBSERVER //If not defined, it assumes that Ld and Lq are equal, which is fine usually.

#endif /* INC_MP2_V0_1_H_ */
