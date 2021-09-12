#include "main.h"

Stepper motor_D(STEP_D, DIR_D);
Stepper motor_G(STEP_G, DIR_G);
StepControl controller;

void setup() {
  // Initialisation de la communication série
  Serial.begin(115200);

  // Initialisation des moteurs pas à pas
  Motor_Init(&motor_D, &motor_G);

  // Encoders initialization
  Encoder_Init();

  // Initialisation de la communication RF
  nRF_Init();

}

void loop() {
  Serial.print("Compt G = ");
  Serial.print(L_Cpt);

  Serial.print("   Compt D = ");
  Serial.println(R_Cpt);

  nRF_Write("lol3");
  delay(100);
}