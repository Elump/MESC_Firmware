/*
 * IHM08.h
 *
 */

#ifndef INC_IHM08_H_
#define INC_IHM08_H_
//Pick a motor for default
//#define Max30	// Smops Test Motor, motor details are defined in MESC_MOTOR_DEFAULTS.h
#define M5010

#define PWM_FREQUENCY 20000
#define CUSTOM_DEADTIME 800 //ns

#define SHUNT_POLARITY 1.0f         //changed for IHM08

#define ABS_MAX_PHASE_CURRENT 15.0f //changed for IHM08
#define ABS_MAX_BUS_VOLTAGE 45.0f
#define ABS_MIN_BUS_VOLTAGE 9.0f   //changed for IHM08
#define R_SHUNT 0.01f               //changed for IHM08
#define OPGAIN 4.7f                 //changed for IHM08

#define DAC_REF						          //added for F405RG

#define R_VBUS_BOTTOM 9310.0f //Phase and Vbus voltage sensors
#define R_VBUS_TOP 169000.0f

//SMOPS: added separate BEMF gain for the BEMF divider (used with HAS_DIFF_PHASE_RESISTORS_TO_VB)
#define HAS_DIFF_PHASE_RESISTORS_TO_VB

#ifdef HAS_DIFF_PHASE_RESISTORS_TO_VB
	#define R_VEMF_BOTTOM 2200.0f
	#define R_VEMF_TOP 10000.0f
#endif

#define MAX_ID_REQUEST 2.0f
#define MAX_IQ_REQUEST 15.0f       //changed for IHM08
#define MIN_IQ_REQUEST -10.0f		   //added for F405RG

//#define DEFAULT_CONTROL_MODE MOTOR_CONTROL_MODE_TORQUE  //added for F405RG
#define DEFAULT_CONTROL_MODE MOTOR_CONTROL_MODE_DUTY

#define ADC1OOR 4094              //added for F405RG

#define SEVEN_SECTOR		//Normal SVPWM implemented as midpoint clamp. If not defined, you will get 5 sector, bottom clamp
#define DEADTIME_COMP		//This injects extra PWM duty onto the timer which effectively removes the dead time.
#define DEADTIME_COMP_V 10
//#define MAX_MODULATION 1.10f //Use this with 5 sector modulation if you want extra speed

//Inputs
//#define GET_THROTTLE_INPUT _motor->Raw.ADC_in_ext1 = ADC_buffer[3]  // Throttle
#define GET_THROTTLE_INPUT 	_motor->Raw.ADC_in_ext1 = 0.9f * _motor->Raw.ADC_in_ext1 + 0.1f * hadc1.Instance->JDR3;  // Throttle for MP2 with F405 pill
#define GET_THROTTLE_INPUT2 	0 //There is no second throttle input
#define GET_FETU_T 	_motor->Raw.MOSu_T = 	0.9f * _motor->Raw.MOSu_T + 0.1f * ADC2_buffer[3] //Temperature on PB1
#define GET_MOTOR_T _motor->Raw.Motor_T = 0.9f * _motor->Raw.Motor_T + 0.1f * ADC1_buffer[4]

//#define USE_FIELD_WEAKENING
#define USE_FIELD_WEAKENINGV2
//#define USE_HIGHHOPES_PHASE_BALANCING
#define FIELD_WEAKENING_EHZ 16000 //This sets the max field weakening speed
#define FIELD_WEAKENING_THRESHOLD 0.8f

//#define USE_LR_OBSERVER

/////////////////////Related to ANGLE ESTIMATION////////////////////////////////////////
#define INTERPOLATE_V7_ANGLE
#define DEFAULT_SENSOR_MODE MOTOR_SENSOR_MODE_SENSORLESS
//#define DEFAULT_SENSOR_MODE MOTOR_SENSOR_MODE_HALL
//#define DEFAULT_SENSOR_MODE MOTOR_SENSOR_MODE_OPENLOOP
//#define DEFAULT_SENSOR_MODE MOTOR_SENSOR_MODE_ENCODER
//#define DEFAULT_SENSOR_MODE MOTOR_SENSOR_MODE_HFI

#define USE_HFI
#define DEFAULT_STARTUP_SENSOR STARTUP_SENSOR_HFI
//#define DEFAULT_STARTUP_SENSOR STARTUP_SENSOR_OPENLOOP
//#define DEFAULT_STARTUP_SENSOR STARTUP_SENSOR_HALL
//#define DEFAULT_STARTUP_SENSOR STARTUP_SENSOR_PWM_ENCODER

#define HFI_VOLTAGE 1.5f
#define HFI_TEST_CURRENT 0.0f
#define HFI_THRESHOLD 0.0f //Defaults to 0.05Vbus if set to 0
#define HFI45
//#define DEFAULT_HFI_TYPE HFI_TYPE_NONE
#define DEFAULT_HFI_TYPE HFI_TYPE_45
//#define DEFAULT_HFI_TYPE HFI_TYPE_D
//#define DEFAULT_HFI_TYPE HFI_TYPE_SPECIAL

//#define USE_HALL_START
#define HALL_VOLTAGE_THRESHOLD 1.5f

//#define USE_SPI_ENCODER //Only supports TLE5012B in SSC mode using onewire SPI on SPI3 F405...
#define POLE_PAIRS 7
#define ENCODER_E_OFFSET 14500
#define POLE_ANGLE (65536/POLE_PAIRS)

#define FASTLED GPIOB
#define FASTLEDIO GPIO_PIN_7
#define FASTLEDIONO 7
#define SLOWLED GPIOB
#define SLOWLEDIO GPIO_PIN_5
#define SLOWLEDIONO 5

//#define SAFE_START_DEFAULT 0

//#define LOGGING
//#define LOGLENGTH 1500

//#define USE_SALIENT_OBSERVER //If not defined, it assumes that Ld and Lq are equal, which is fine usually.

//GPIO for IC timer //These actually have to be timer compatible pins and
//you must have done something (anything) with the timer in CUBEMX to make it generate the config files
#define IC_TIM_GPIO GPIOB
#define IC_TIM_PIN GPIO_PIN_6
#define IC_TIM_IONO 6
//#define IC_TIMER htim4 //This must be TIM2-TIM5. Untested with other timers
//Assign a use for the input capture timer
#define IC_TIMER_RCPWM
//#define IC_TIMER_ENCODER

//#define KILLSWITCH_GPIO GPIOB
//#define KILLSWITCH_PIN GPIO_PIN_3
//#define KILLSWITCH_IONO 3

//#define REVERSE_GPIO GPIOB
//#define REVERSE_GPIO_PIN GPIO_PIN_11
//#define REVERSE_IONO 11

//#define SIDESTAND_GPIO GPIOB
//#define SIDESTAND_GPIO_PIN GPIO_PIN_10
//#define SIDESTAND_IONO 10

//#define BRAKE_GPIO GPIOA
//#define BRAKE_GPIO_PIN GPIO_PIN_5
//#define BRAKE_IONO 5

#endif /* INC_IHM08_H_ */
