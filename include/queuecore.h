#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

typedef uint8_t BYTE;

typedef struct Queue
{
    int MAX_SIZE;
    int used_size;

    // Points to the tail of the queue.
    BYTE* base_pointer;

    // Points to the head of the queue.
    BYTE* head_pointer;

} Queue;

// Initializes a queue struct with queue size QUEUE_MAX_SIZE.
// Default size is used if 0 is entered.
Queue init_queue(int QUEUE_MAX_SIZE);

// Deletes base_pointer.
int delete_queue(Queue* queue);

// Pushes data_length bytes from data on to queue.
void* push(Queue* queue, BYTE* data, int data_length);

// Pops data_length bytes from head of queue.
void* pop(Queue* queue, int data_length);

#endif

