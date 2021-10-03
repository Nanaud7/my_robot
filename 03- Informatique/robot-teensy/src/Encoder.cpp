#include "Encoder.h"

long L_Cpt = 0;
long R_Cpt = 0;

uint8_t Encoder_Init(void){
    L_Cpt = 0;
    R_Cpt = 0;

    // Initialization Left Encoder
    pinMode(L_ENCODER_A, INPUT);
    pinMode(L_ENCODER_B, INPUT);
    attachInterrupt(L_ENCODER_A, L_Encoder, RISING);

    // Initialization Right Encoder
    pinMode(R_ENCODER_A, INPUT);
    pinMode(R_ENCODER_B, INPUT);
    attachInterrupt(R_ENCODER_A, R_Encoder, RISING);

    return 0;
}

void L_Encoder(void){
    if (digitalRead(L_ENCODER_B) == HIGH){
        L_Cpt--;
    }
    else{
        L_Cpt++;
    }
}

void R_Encoder(void){
    if (digitalRead(R_ENCODER_B) == HIGH){
        R_Cpt--;
    }
    else{
        R_Cpt++;
    }
}

long getLeftTicks(void){
    long LeftTicks = L_Cpt;
    L_Cpt = 0;

    return LeftTicks;
}

long getRightTicks(void){
    long RightTicks = R_Cpt;
    R_Cpt = 0;

    return RightTicks;
}
