#include "Motor.h"

uint8_t Motor_Enable(){
    digitalWrite(MOT_EN,LOW);

    return 0;
}

uint8_t Motor_Disable(){
    digitalWrite(MOT_EN,HIGH); // HIGH pour désactiver

    return 0;
}

uint8_t Motor_Init(Stepper* motor_D, Stepper* motor_G){

    // Désactivation des moteurs
    pinMode(MOT_EN,OUTPUT);
    Motor_Disable();

    // Initialisation du moteur droit
    motor_D->setMaxSpeed(MAX_SPEED);
    motor_D->setAcceleration(ACC);
    //motor.setStepPinPolarity(HIGH);
    //motor.setInverseRotation(LOW);
    motor_D->setPosition(0);

    // Initialisation du moteur gauche
    motor_G->setMaxSpeed(MAX_SPEED);
    motor_G->setAcceleration(ACC);
    //motor.setStepPinPolarity(HIGH);
    //motor.setInverseRotation(LOW);
    motor_G->setPosition(0);

    return 0;
}