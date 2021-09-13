#include <Arduino.h>
#include "Pins.h"
#include "math.h"

#define FORWARD 0
#define BACKWARD 1

// Coeffecients
#define STEPS_PER_REV   200
#define MICROSTEPS      32
#define ROT_RPM_MAX     20
#define MOV_RPM_MAX     30

// Prototypes
uint8_t Motor_Init();
uint8_t Motor_Enable();
uint8_t Motor_Disable();
uint8_t Motor_setSpeedLeft(float RPM);
uint8_t Motor_setSpeedRight(float RPM);
uint8_t Motor_setSpeed(float speed);
uint8_t Motor_robotForward();
uint8_t Motor_robotBackward();
uint8_t Motor_robotRotLeft();
uint8_t Motor_robotRotRight();