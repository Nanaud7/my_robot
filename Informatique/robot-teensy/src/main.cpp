#include "main.h"

IntervalTimer OdoTimer;

char buffer[32] = "";

void setup() {
  // Serial initialization
  Serial.begin(115200);

  // Steppers initialization
  Motor_Init();
  Motor_Disable();
  Motor_setSpeed(30);
  Motor_robotRotRight();

  // Encoders initialization
  Encoder_Init();

  // nRF initialization
  //nRF_Init();

  // Odometry initialization
  Odometry_Init();
  OdoTimer.begin(robotControl, 15000);

  // Strategy initialization
  pinMode(STRAT_LED, OUTPUT);
  digitalWrite(STRAT_LED, HIGH);
}

void loop() {
  //sprintf(buffer, "L:%ld  R:%ld", L_Cpt, R_Cpt);
  sprintf(buffer, "x:%f  y:%f  o:%f", g_x, g_y, g_angle);
  //nRF_Write(buffer);
  Serial.println(buffer);
  
  delay(100);
} 