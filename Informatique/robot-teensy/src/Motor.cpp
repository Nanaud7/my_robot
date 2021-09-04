#include "Motor.h"

uint8_t Motor_Init(Stepper motor){

    // Désactivation des moteurs
    pinMode(MOT_EN,OUTPUT);
    digitalWrite(MOT_EN,LOW);           // HIGH

    motor.setMaxSpeed(667);             // 800 par défaut
    motor.setAcceleration(2500);        // 2500 par défaut
    //motor.setStepPinPolarity(HIGH);
    //motor.setInverseRotation(LOW);

    return 0;
}