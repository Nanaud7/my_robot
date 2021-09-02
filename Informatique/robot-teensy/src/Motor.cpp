#include "Motor.h"

uint8_t Motor_Init(Stepper motor){

    // Désactivation des moteurs
    pinMode(MOT_EN,OUTPUT);
    digitalWrite(MOT_EN,HIGH);           // HIGH

    motor.setMaxSpeed(800);             // 800 par défaut
    motor.setAcceleration(2500);        // 2500 par défaut
    //motor.setStepPinPolarity(HIGH);
    //motor.setInverseRotation(LOW);

    return 0;
}