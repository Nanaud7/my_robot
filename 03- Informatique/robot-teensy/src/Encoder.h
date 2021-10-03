#include <Arduino.h>
#include "Pins.h"

// Variables
extern long L_Cpt;
extern long R_Cpt;

// Coefficients
#define ENTRAXE 257
#define L_COEF 0.2666666667 // 3000 ticks/80cm
#define R_COEF 0.2666666667 // 2992 ticks/80cm

// Prototypes
uint8_t Encoder_Init(void);
void L_Encoder(void);
void R_Encoder(void);
long getLeftTicks(void);
long getRightTicks(void);