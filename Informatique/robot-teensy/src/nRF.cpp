#include "nRF.h"

RF24 radio(nRF_CE,nRF_CSN);
Queue* myQueue;

const byte adresse[6] = tunnel;

uint8_t nRF_Init(void){
    SPI.setSCK(nRF_SCK);
    SPI.setCS(nRF_CSN);

    radio.begin();
    radio.openWritingPipe(adresse);
    radio.setChannel(125);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();

    myQueue = nRF_QueueInit();

    return 0;
}

uint8_t nRF_Write(const char message[]){
    radio.write(message,32);
    return 0;
}



struct Element
{
    char buffer[32];
    Element *next;
};

struct Queue
{
    Element *first;
};

Queue* nRF_QueueInit()
{
    Queue *queue = malloc(sizeof(*queue));
    queue->first = NULL;

    return queue;
}

void nRF_EnQ(Queue *queue, const char buffer[])
{
    Element *newElement = malloc(sizeof(*newElement));
    if (queue == NULL || newElement == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(newElement->buffer, buffer);
    newElement->next = NULL;

    if (queue->first != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *currentElement = queue->first;
        while (currentElement->next != NULL)
        {
            currentElement = currentElement->next;
        }
        currentElement->next = newElement;
    }
    else /* La file est vide, notre élément est le premier */
    {
        queue->first = newElement;
    }
}

void nRF_DeQ(Queue *queue, char buffer[])
{
    if (queue == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /* On vérifie s'il y a quelque chose à défiler */
    if (queue->first != NULL)
    {
        Element *elementFromQueue = queue->first;

        strcpy(buffer, elementFromQueue->buffer);
        queue->first = elementFromQueue->next;
        free(elementFromQueue);
    }
}

/*
void nRF_displayQueue(Queue *queue)
{
    if (queue == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Element *current = queue->first;

    while (current != NULL)
    {
        printf("%s\n", current->buffer);
        current = current->next;
    }

    printf("\n");
}
*/
