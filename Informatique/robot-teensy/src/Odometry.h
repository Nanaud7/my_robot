#include <Arduino.h>
#include <math.h>
#include "Encoder.h"

// Variables
extern float g_x, g_y, g_angle;

// Prototypes
uint8_t Odometry_Init(void);
uint8_t Odometry(void);