#include "Strategy.h"

int numberOfPoints = 4;
int indexStrategy = 1;

Strategy blueStrategy[4] = {
    {
        .x = 0, .y = 0, .dir = FORWARD
    }, {
        .x = 100, .y = 0, .dir = FORWARD
    }, {
        .x = 200, .y = 100, .dir = FORWARD
    }, {
        .x = 0, .y = 0, .dir = FORWARD
    }
};