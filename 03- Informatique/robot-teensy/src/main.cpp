#include "main.h"

IntervalTimer OdoTimer;

float vbat = 0;

void setup() {
  // Serial initialization
  Serial.begin(115200);

  // Steppers initialization
  Motor_Init();
  //Motor_Enable();
  //Motor_Disable();

  // Encoders initialization
  Encoder_Init();

  // nRF initialization
  nRF_Init();

  // Odometry initialization
  Odometry_Init();
  OdoTimer.begin(robotControl, 15000);

  // Strategy initialization
  pinMode(LED_Y, OUTPUT);
  digitalWrite(LED_Y, HIGH);

  // Battery voltage check
  analogReadResolution(10);
  vbat = analogRead(V_BAT) * (3.3/1024.0) * ((100000.0+390000.0)/100000.0);
}

void loop() {
  char buffer[32] = "";

  /*
  nRF_DeQ(myQueue, buffer);
  if (buffer != ""){
    nRF_Write(buffer);
  }
  */

  //sprintf(buffer, "L:%ld  R:%ld", L_Cpt, R_Cpt);
  //sprintf(buffer,"x:%.2f  y:%.2f  o:%.2f id:%d", g_x, g_y, g_angle, indexStrategy);
  //sprintf(buffer, "id:%d X:%.2f Y:%.2f", indexStrategy, blueStrategy[indexStrategy].x, blueStrategy[indexStrategy].y);
  //nRF_Write(buffer);
  //sprintf(buffer,"idStrat: %d", indexStrategy);
  //nRF_Write(buffer);
  //Serial.println(buffer);
} 