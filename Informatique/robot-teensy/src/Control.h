#include <math.h>
#include "Odometry.h"
#include "Motor.h"
#include "nRF.h"

#define STAND_BY    0
#define ROTATION    1
#define MOVE        2

// Prototypes
void robotControl();
double robotControlSpeed(double x, double a);
uint8_t controlRotation(double angleToTarget);
uint8_t controlMove(double distanceToTarget, double angleToTarget);
double angleToZeroTwoPi(double angle);
double angleToPiPi(double angle);