#include <Arduino.h>
#include <math.h>
#include "Encoder.h"
#include "Strategy.h"

// Variables
extern double g_x, g_y, g_angle;

// Prototypes
uint8_t Odometry_Init(void);
uint8_t Odometry(void);