#include "nRF.h"

RF24 radio(nRF_CE,nRF_CSN);

const byte adresse[6] = tunnel;

uint8_t nRF_Init(void){
    SPI.setSCK(nRF_SCK);
    SPI.setCS(nRF_CSN);

    radio.begin();
    radio.openWritingPipe(adresse);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();

    return 0;
}

uint8_t nRF_Write(const char message[]){
    radio.write(message,32);
    return 0;
}