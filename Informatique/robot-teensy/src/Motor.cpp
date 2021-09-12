#include "Motor.h"

uint8_t Motor_Init(){
    // mOTORS DISABLED
    pinMode(MOT_EN,OUTPUT);
    Motor_Disable();

    analogWriteResolution(16);

    // RIGHT STEPPER INITIALIZATION
    pinMode(R_STEP, OUTPUT);
    analogWrite(R_STEP, 128);
    pinMode(R_DIR, OUTPUT);
    digitalWrite(R_DIR, FORWARD);

    // LEFT STEPPER INITIALIZATION
    pinMode(L_STEP, OUTPUT);
    analogWrite(L_STEP, 128);
    pinMode(L_DIR, OUTPUT);
    digitalWrite(L_DIR, FORWARD);

    // SET DEFAULT SPEED
    Motor_setSpeed(0);

    return 0;
}

uint8_t Motor_Enable(){
    digitalWrite(MOT_EN,LOW);
    return 0;
}

uint8_t Motor_Disable(){
    digitalWrite(MOT_EN,HIGH); // HIGH pour désactiver
    return 0;
}

uint8_t Motor_setSpeed(float RPM){
    if (RPM > RPM_MAX){
        RPM = RPM_MAX;
    }
    else if(RPM < 0){
        RPM = 0;
    }

    float frequency = (RPM / 60) * STEPS_PER_REV * MICROSTEPS;

    analogWriteFrequency(R_STEP, frequency);
    analogWriteFrequency(L_STEP, frequency);
    return 0;
}

uint8_t Motor_robotForward(){
    digitalWrite(R_DIR, BACKWARD);
    digitalWrite(L_DIR, FORWARD);
    return 0;
}

uint8_t Motor_robotBackward(){
    digitalWrite(R_DIR, FORWARD);
    digitalWrite(L_DIR, BACKWARD);
    return 0;
}

uint8_t Motor_robotRotLeft(){
    digitalWrite(R_DIR, BACKWARD);
    digitalWrite(L_DIR, BACKWARD);
    return 0;
}

uint8_t Motor_robotRotRight(){
    digitalWrite(R_DIR, FORWARD);
    digitalWrite(L_DIR, FORWARD);
    return 0;
}
