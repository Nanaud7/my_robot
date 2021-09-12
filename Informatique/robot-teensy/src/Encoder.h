#include <Arduino.h>
#include "Pins.h"

extern long L_Cpt;
extern long R_Cpt;

uint8_t Encoder_Init(void);
void L_Encoder(void);
void R_Encoder(void);