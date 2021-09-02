#include <SPI.h>
#include <RF24.h>
#include "Pins.h"

#define tunnel "PIPE1"

uint8_t nRF_Init(void);
uint8_t nRF_Write(const char message[]);