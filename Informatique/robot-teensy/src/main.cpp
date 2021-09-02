#include "main.h"

Stepper motor_D(STEP_D, DIR_D);
//Stepper motor_G(STEP_G, DIR_G);
StepControl controller;

void setup() {
  // Initialisation de la communication série
  Serial.begin(115200);

  // Initialisation des moteurs pas à pas
  Motor_Init(motor_D);

  // Initialisation de la communication RF
  nRF_Init();
}

void loop() {
  //motor_D.setTargetRel(1000);
  //controller.move(motor_D);

  nRF_Write("lol3");

  delay(1000);
}