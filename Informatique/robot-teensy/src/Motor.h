#include <TeensyStep.h>
#include "Pins.h"
#include "math.h"

#define FORWARD 0
#define BACKWARD 1

#define ENTRAXE_MOT         124.5   // en mm
#define DIAMETRE_ROUE_MOT   71      // en mm
#define PERIMETRE_ROUE_MOT  (DIAMETRE_ROUE_MOT*M_PI)
#define PERIMETRE_REV       (ENTRAXE_MOT*M_PI)

#define ACC             3500    // 800 par défaut
#define MAX_SPEED       3000    // 2500 par défaut
#define STEPS_MOT       200     // 1.8 degré/step
#define MICROSTEP       32
#define STEPS_PER_REV   (STEPS_MOT*MICROSTEP)
#define DIST_PER_STEP   (PERIMETRE_ROUE_MOT/STEPS_PER_REV)
#define ROBOT_REV_STEPS (PERIMETRE_REV/DIST_PER_STEP)    

uint8_t Motor_Enable();
uint8_t Motor_Disable();
uint8_t Motor_Init(Stepper* motor_D, Stepper* motor_G);