#include <math.h>
#include "Odometry.h"
#include "Motor.h"

#define STAND_BY    0
#define ROTATION    1
#define TRANSLATION 2

#define COEFF_A     60

// Prototypes
void robotControl();