#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/queuecore.h"

#define DEFAULT_MAX_SIZE 2048

Queue init_queue(int QUEUE_MAX_SIZE)
{
    if(QUEUE_MAX_SIZE < 0)
    {
        printf("Invalid queue size: %d. Exiting...\n", QUEUE_MAX_SIZE);
        exit(1);
    }
    
    Queue new_queue;

    new_queue.MAX_SIZE = QUEUE_MAX_SIZE
                         ? QUEUE_MAX_SIZE
                         : DEFAULT_MAX_SIZE;

    new_queue.used_size = 0;
    new_queue.base_pointer = malloc(sizeof(BYTE) * new_queue.MAX_SIZE);

    if(!new_queue.base_pointer)
    {
        printf("Error: Initializing queue failed. Exiting...\n");
        exit(1);
    }

    new_queue.head_pointer = new_queue.base_pointer;

    return new_queue;
}


int delete_queue(Queue* queue)
{
    if(!queue)
        return 0;

    free(queue->base_pointer);
    return 1;
}


void* push(Queue* queue, BYTE* data_pointer, int data_length)
{
    int new_size = queue->used_size + data_length;
    
    if(!queue || !data_pointer || new_size > queue->MAX_SIZE)
        return NULL;

    // Offset existing data:
    
    // Declare a new head pointer data_length offset from
    // current head_pointer.
    BYTE* new_head_pointer = queue->head_pointer + data_length;

    // Move the byte value in head_pointer by data_length offset to the
    // right and decrease head_pointer each time until it's smaller than
    // base_pointer.
    while((queue->head_pointer) >= (queue->base_pointer))
    {
        *(queue->head_pointer + data_length) = *(queue->head_pointer);
        queue->head_pointer--;
    }

    // Make head_pointer equal to base_pointer.
    queue->head_pointer++;

    // Copy data to queue.
    for(int i = 0; i < data_length; i++)
    {
        *queue->head_pointer = *data_pointer;
        queue->head_pointer++;
        data_pointer++;
    }

    queue->head_pointer = new_head_pointer;
    queue->used_size = new_size;

    return NULL;
}


void* pop(Queue* queue, int data_length)
{
    BYTE* data;
    if(!queue || !(data = malloc(sizeof(BYTE)*data_length)))
        return NULL;

    memcpy(data, queue->head_pointer-data_length, data_length);

    queue->head_pointer -= data_length;
    queue->used_size -= data_length;

    return data;
}

