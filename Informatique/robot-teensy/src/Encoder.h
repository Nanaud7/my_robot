#include <Arduino.h>
#include "Pins.h"

// Variables
extern long L_Cpt;
extern long R_Cpt;

// Coefficients
#define ENTRAXE 275
#define L_COEF 0.2662229617
#define R_COEF 0.2676480428

// Prototypes
uint8_t Encoder_Init(void);
void L_Encoder(void);
void R_Encoder(void);
long getLeftTicks(void);
long getRightTicks(void);