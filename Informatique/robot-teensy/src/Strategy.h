#ifndef STRATEGY_H_
#define STRATEGY_H_

#include "Motor.h"

// Variables
typedef struct {
    double x;
	double y;
	bool dir;
} Strategy;

extern int numberOfPoints;
extern int indexStrategy;
extern Strategy blueStrategy[];

#endif // STRATEGY_H_