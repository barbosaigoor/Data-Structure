#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define MAX_QUEUE 5
#define i32_for(size) for(uint32_t _i_ = 0; _i_ < size; ++_i_)

Queue * queue_create(const uint8_t type)
{
    Queue * queue = malloc(sizeof(Queue));
    queue->content = malloc(MAX_QUEUE * type);
    memset(queue->content, 0, MAX_QUEUE * type);
    queue->size = MAX_QUEUE;
    queue->type = type;
    queue->length = 0;
    queue->head = 0;
    queue->tail = MAX_QUEUE * type - type;
    return queue;
}

uint8_t queue_is_empty(Queue * queue)
{
    return queue->length == 0;
}

uint32_t queue_length(Queue * queue)
{
    return queue->length;
}

void queue_push(Queue * queue, const void * key)
{
    if(queue->length == queue->size)
        return;
    queue->tail = (queue->tail + queue->type) % (queue->type * MAX_QUEUE);
    void * tail = queue->content + queue->tail;
    memcpy(tail, key, queue->type);
    printf("\n~~ HEAD: %d \tTAIL: %d\n", queue->head, queue->tail);
    ++queue->length;
}

void * queue_pop(Queue * queue)
{
    if(!queue_is_empty(queue))
    {
        void * v_ptr = malloc(queue->type);
        memcpy(v_ptr, queue->content + queue->head, queue->type);
        queue->head = (queue->head + queue->type) % (queue->type * MAX_QUEUE);
        printf("\n~~ HEAD: %d \tTAIL: %d\n", queue->head, queue->tail);
        --queue->length;
        return v_ptr;
    }
    return NULL;
}

void queue_free(Queue * queue)
{
    free(queue->content);
    free(queue);
}

void queue_print(Queue * queue, void (*print)(void *))
{
    if(queue_is_empty(queue))
    {
        puts("Empty queue");
        return;
    }
    void * v_ptr = queue->content;
    for(uint32_t i = queue->head; i != queue->tail; i = (i + queue->type) % (queue->type * MAX_QUEUE))
        print(v_ptr + i);
    print(v_ptr + queue->tail);
    printf("\n");
}

void * queue_find(Queue * queue, const void * key)
{
    void * v_ptr = queue->content;
    for(uint32_t i = queue->head; i != queue->tail; i = (i + queue->type) % (queue->type * MAX_QUEUE))
        if(!memcmp(v_ptr, key, queue->type))
            return v_ptr;
    return NULL;
}