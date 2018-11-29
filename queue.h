#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

typedef struct {
    uint32_t size;
    uint32_t length;
    uint32_t head;
    uint32_t tail;
    void * content;
    uint8_t type;
}Queue;

Queue * queue_create(const uint8_t);
uint8_t queue_is_empty(Queue *);
uint32_t queue_length(Queue *);
void queue_push(Queue *, const void *);
void * queue_pop(Queue *);
void queue_print(Queue *, void (* print)(void *));
void * queue_find(Queue *, const void *);
void queue_free(Queue *);

#endif // ! QUEUE_H