/* This file has been generated from /Users/tony-yi/git/paparazzi_local/conf/airframes/quadrotor_lisa_m_2_pwm_YI_Edward_transparent.xml */
/* Please DO NOT EDIT */

#ifndef AIRFRAME_H
#define AIRFRAME_H

#define AIRFRAME_NAME "MYAC"
#define AC_ID 1
#define MD5SUM ((uint8_t*)"\007\026\205\132\325\204\001\310\214\225\377\027\233\073\341\101")

#define SERVOS_PWM_NB 4
#include "subsystems/actuators/actuators_pwm.h"

#define SERVO_NE 0
#define SERVO_NE_NEUTRAL 1000
#define SERVO_NE_TRAVEL_UP 0.09375
#define SERVO_NE_TRAVEL_UP_NUM 3
#define SERVO_NE_TRAVEL_UP_DEN 32
#define SERVO_NE_TRAVEL_DOWN 0
#define SERVO_NE_TRAVEL_DOWN_NUM 0
#define SERVO_NE_TRAVEL_DOWN_DEN 1
#define SERVO_NE_MAX 1900
#define SERVO_NE_MIN 1000

#define SERVO_SE 1
#define SERVO_SE_NEUTRAL 1000
#define SERVO_SE_TRAVEL_UP 0.09375
#define SERVO_SE_TRAVEL_UP_NUM 3
#define SERVO_SE_TRAVEL_UP_DEN 32
#define SERVO_SE_TRAVEL_DOWN 0
#define SERVO_SE_TRAVEL_DOWN_NUM 0
#define SERVO_SE_TRAVEL_DOWN_DEN 1
#define SERVO_SE_MAX 1900
#define SERVO_SE_MIN 1000

#define SERVO_SW 2
#define SERVO_SW_NEUTRAL 1000
#define SERVO_SW_TRAVEL_UP 0.09375
#define SERVO_SW_TRAVEL_UP_NUM 3
#define SERVO_SW_TRAVEL_UP_DEN 32
#define SERVO_SW_TRAVEL_DOWN 0
#define SERVO_SW_TRAVEL_DOWN_NUM 0
#define SERVO_SW_TRAVEL_DOWN_DEN 1
#define SERVO_SW_MAX 1900
#define SERVO_SW_MIN 1000

#define SERVO_NW 3
#define SERVO_NW_NEUTRAL 1000
#define SERVO_NW_TRAVEL_UP 0.09375
#define SERVO_NW_TRAVEL_UP_NUM 3
#define SERVO_NW_TRAVEL_UP_DEN 32
#define SERVO_NW_TRAVEL_DOWN 0
#define SERVO_NW_TRAVEL_DOWN_NUM 0
#define SERVO_NW_TRAVEL_DOWN_DEN 1
#define SERVO_NW_MAX 1900
#define SERVO_NW_MIN 1000


#define COMMAND_ROLL 0
#define COMMAND_PITCH 1
#define COMMAND_YAW 2
#define COMMAND_THRUST 3
#define COMMANDS_NB 4
#define COMMANDS_FAILSAFE {0,0,0,0}


#define SECTION_MIXING 1
#define MOTOR_MIXING_TRIM_ROLL 0
#define MOTOR_MIXING_TRIM_PITCH 0
#define MOTOR_MIXING_TRIM_YAW 0
#define MOTOR_MIXING_NB_MOTOR 4
#define MOTOR_MIXING_SCALE 256
#define MOTOR_MIXING_ROLL_COEF { -256, -256,  256,  256 }
#define MOTOR_MIXING_PITCH_COEF {  256, -256, -256,  256 }
#define MOTOR_MIXING_YAW_COEF {  -256, 256,  -256, 256 }
#define MOTOR_MIXING_THRUST_COEF {  256,  256,  256,  256 }

#define SERVO_SE_IDX 0
#define Set_SE_Servo(_v) { \
  actuators[SERVO_SE_IDX] = Chop(_v, SERVO_SE_MIN, SERVO_SE_MAX); \
  ActuatorPwmSet(SERVO_SE, actuators[SERVO_SE_IDX]); \
}

#define SERVO_NW_IDX 1
#define Set_NW_Servo(_v) { \
  actuators[SERVO_NW_IDX] = Chop(_v, SERVO_NW_MIN, SERVO_NW_MAX); \
  ActuatorPwmSet(SERVO_NW, actuators[SERVO_NW_IDX]); \
}

#define SERVO_SW_IDX 2
#define Set_SW_Servo(_v) { \
  actuators[SERVO_SW_IDX] = Chop(_v, SERVO_SW_MIN, SERVO_SW_MAX); \
  ActuatorPwmSet(SERVO_SW, actuators[SERVO_SW_IDX]); \
}

#define SERVO_NE_IDX 3
#define Set_NE_Servo(_v) { \
  actuators[SERVO_NE_IDX] = Chop(_v, SERVO_NE_MIN, SERVO_NE_MAX); \
  ActuatorPwmSet(SERVO_NE, actuators[SERVO_NE_IDX]); \
}

#define ACTUATORS_NB 4

#define SetActuatorsFromCommands(values, AP_MODE) { \
  int32_t servo_value;\
  int32_t command_value;\
\
  motor_mixing_run(autopilot_motors_on,FALSE,values); \
\
  command_value = motor_mixing.commands[SERVO_NE]; \
  command_value *= command_value>0 ? SERVO_NE_TRAVEL_UP_NUM : SERVO_NE_TRAVEL_DOWN_NUM; \
  command_value /= command_value>0 ? SERVO_NE_TRAVEL_UP_DEN : SERVO_NE_TRAVEL_DOWN_DEN; \
  servo_value = SERVO_NE_NEUTRAL + command_value; \
  Set_NE_Servo(servo_value); \
\
  command_value = motor_mixing.commands[SERVO_SE]; \
  command_value *= command_value>0 ? SERVO_SE_TRAVEL_UP_NUM : SERVO_SE_TRAVEL_DOWN_NUM; \
  command_value /= command_value>0 ? SERVO_SE_TRAVEL_UP_DEN : SERVO_SE_TRAVEL_DOWN_DEN; \
  servo_value = SERVO_SE_NEUTRAL + command_value; \
  Set_SE_Servo(servo_value); \
\
  command_value = motor_mixing.commands[SERVO_SW]; \
  command_value *= command_value>0 ? SERVO_SW_TRAVEL_UP_NUM : SERVO_SW_TRAVEL_DOWN_NUM; \
  command_value /= command_value>0 ? SERVO_SW_TRAVEL_UP_DEN : SERVO_SW_TRAVEL_DOWN_DEN; \
  servo_value = SERVO_SW_NEUTRAL + command_value; \
  Set_SW_Servo(servo_value); \
\
  command_value = motor_mixing.commands[SERVO_NW]; \
  command_value *= command_value>0 ? SERVO_NW_TRAVEL_UP_NUM : SERVO_NW_TRAVEL_DOWN_NUM; \
  command_value /= command_value>0 ? SERVO_NW_TRAVEL_UP_DEN : SERVO_NW_TRAVEL_DOWN_DEN; \
  servo_value = SERVO_NW_NEUTRAL + command_value; \
  Set_NW_Servo(servo_value); \
\
  ActuatorsPwmCommit();\
}

#define AllActuatorsInit() { \
  ActuatorsPwmInit();\
}

#define SECTION_IMU 1
#define IMU_ACCEL_X_NEUTRAL 11
#define IMU_ACCEL_Y_NEUTRAL 11
#define IMU_ACCEL_Z_NEUTRAL -25
#define IMU_MAG_X_NEUTRAL -116
#define IMU_MAG_Y_NEUTRAL -31
#define IMU_MAG_Z_NEUTRAL -53
#define IMU_MAG_X_SENS 4.36471037878
#define IMU_MAG_X_SENS_NUM 11453
#define IMU_MAG_X_SENS_DEN 2624
#define IMU_MAG_Y_SENS 4.31112493039
#define IMU_MAG_Y_SENS_NUM 55454
#define IMU_MAG_Y_SENS_DEN 12863
#define IMU_MAG_Z_SENS 4.64394687888
#define IMU_MAG_Z_SENS_NUM 42311
#define IMU_MAG_Z_SENS_DEN 9111
#define IMU_BODY_TO_IMU_PHI 0.
#define IMU_BODY_TO_IMU_THETA 0.
#define IMU_BODY_TO_IMU_PSI 3.14159265

#define SECTION_AHRS 1
#define AHRS_PROPAGATE_FREQUENCY 512
#define AHRS_H_X 0.8402567
#define AHRS_H_Y -0.0374568
#define AHRS_H_Z 0.5408934

#define SECTION_INS 1
#define INS_BARO_SENS 22.3
#define INS_BARO_SENS_NUM 223
#define INS_BARO_SENS_DEN 10

#define SECTION_STABILIZATION_RATE 1
#define STABILIZATION_RATE_SP_MAX_P 10000
#define STABILIZATION_RATE_SP_MAX_Q 10000
#define STABILIZATION_RATE_SP_MAX_R 10000
#define STABILIZATION_RATE_DEADBAND_P 50
#define STABILIZATION_RATE_DEADBAND_Q 50
#define STABILIZATION_RATE_DEADBAND_R 200
#define STABILIZATION_RATE_REF_TAU 4
#define STABILIZATION_RATE_GAIN_P 320
#define STABILIZATION_RATE_GAIN_Q 320
#define STABILIZATION_RATE_GAIN_R 350
#define STABILIZATION_RATE_IGAIN_P 300
#define STABILIZATION_RATE_IGAIN_Q 300
#define STABILIZATION_RATE_IGAIN_R 300
#define STABILIZATION_RATE_DDGAIN_P 6
#define STABILIZATION_RATE_DDGAIN_Q 6
#define STABILIZATION_RATE_DDGAIN_R 10

#define SECTION_STABILIZATION_ATTITUDE 1
#define STABILIZATION_ATTITUDE_SP_MAX_PHI 0.523598775
#define STABILIZATION_ATTITUDE_SP_MAX_THETA 0.523598775
#define STABILIZATION_ATTITUDE_SP_MAX_R 0.7853981625
#define STABILIZATION_ATTITUDE_DEADBAND_A 100
#define STABILIZATION_ATTITUDE_DEADBAND_E 100
#define STABILIZATION_ATTITUDE_DEADBAND_R 500
#define STABILIZATION_ATTITUDE_REF_OMEGA_P 13.962634
#define STABILIZATION_ATTITUDE_REF_ZETA_P 0.85
#define STABILIZATION_ATTITUDE_REF_MAX_P 6.981317
#define STABILIZATION_ATTITUDE_REF_MAX_PDOT RadOfDeg(8000.)
#define STABILIZATION_ATTITUDE_REF_OMEGA_Q 13.962634
#define STABILIZATION_ATTITUDE_REF_ZETA_Q 0.85
#define STABILIZATION_ATTITUDE_REF_MAX_Q 6.981317
#define STABILIZATION_ATTITUDE_REF_MAX_QDOT RadOfDeg(8000.)
#define STABILIZATION_ATTITUDE_REF_OMEGA_R 8.72664625
#define STABILIZATION_ATTITUDE_REF_ZETA_R 0.85
#define STABILIZATION_ATTITUDE_REF_MAX_R 3.14159265
#define STABILIZATION_ATTITUDE_REF_MAX_RDOT RadOfDeg(1800.)
#define STABILIZATION_ATTITUDE_PHI_PGAIN 530
#define STABILIZATION_ATTITUDE_PHI_DGAIN 165
#define STABILIZATION_ATTITUDE_PHI_IGAIN 40
#define STABILIZATION_ATTITUDE_THETA_PGAIN 530
#define STABILIZATION_ATTITUDE_THETA_DGAIN 165
#define STABILIZATION_ATTITUDE_THETA_IGAIN 40
#define STABILIZATION_ATTITUDE_PSI_PGAIN 530
#define STABILIZATION_ATTITUDE_PSI_DGAIN 320
#define STABILIZATION_ATTITUDE_PSI_IGAIN 40
#define STABILIZATION_ATTITUDE_PHI_DDGAIN 300
#define STABILIZATION_ATTITUDE_THETA_DDGAIN 300
#define STABILIZATION_ATTITUDE_PSI_DDGAIN 280

#define SECTION_GUIDANCE_V 1
#define GUIDANCE_V_MIN_ERR_Z POS_BFP_OF_REAL(-10.)
#define GUIDANCE_V_MAX_ERR_Z POS_BFP_OF_REAL( 10.)
#define GUIDANCE_V_MIN_ERR_ZD SPEED_BFP_OF_REAL(-10.)
#define GUIDANCE_V_MAX_ERR_ZD SPEED_BFP_OF_REAL( 10.)
#define GUIDANCE_V_MAX_SUM_ERR 2000000
#define GUIDANCE_V_HOVER_KP 130
#define GUIDANCE_V_HOVER_KD 75
#define GUIDANCE_V_HOVER_KI 30
#define GUIDANCE_V_RC_CLIMB_COEF 163
#define GUIDANCE_V_RC_CLIMB_DEAD_BAND 160000

#define SECTION_GUIDANCE_H 1
#define GUIDANCE_H_USE_REF 1
#define GUIDANCE_H_MAX_BANK 0.2617993875
#define GUIDANCE_H_PGAIN 30
#define GUIDANCE_H_DGAIN 90
#define GUIDANCE_H_AGAIN 0
#define GUIDANCE_H_IGAIN 40

#define SECTION_SIMULATOR 1
#define NPS_ACTUATOR_NAMES {"ne_motor", "se_motor", "sw_motor", "se_motor"}
#define NPS_INITIAL_CONDITITONS "reset00"
#define NPS_SENSORS_PARAMS "nps_sensors_params_default.h"

#define SECTION_AUTOPILOT 1
#define MODE_MANUAL AP_MODE_ATTITUDE_DIRECT
#define MODE_AUTO1 AP_MODE_HOVER_Z_HOLD
#define MODE_AUTO2 AP_MODE_NAV

#define SECTION_BAT 1
#define CATASTROPHIC_BAT_LEVEL 9.3
#define CRITIC_BAT_LEVEL 9.6
#define LOW_BAT_LEVEL 9.7
#define MAX_BAT_LEVEL 12.4


#endif // AIRFRAME_H
