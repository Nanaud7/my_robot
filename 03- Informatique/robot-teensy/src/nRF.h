#include <SPI.h>
#include <RF24.h>
#include "Pins.h"
#include <stdlib.h>
#include <string.h>

#define tunnel "PIPE1"

typedef struct Element Element;
typedef struct Queue Queue;

extern Queue* myQueue;

uint8_t nRF_Init(void);
uint8_t nRF_Write(const char message[]);

Queue* nRF_QueueInit();
void nRF_EnQ(Queue *queue, const char buffer[]);
void nRF_DeQ(Queue *queue, char buffer[]);
//void nRF_displayQueue(Queue *queue);