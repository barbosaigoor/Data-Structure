#ifndef ARRAY_H
#define ARRAY_H

#include <stdint.h>

typedef struct {
    void * content;
    uint32_t size;  // Extra space for optimization
    uint32_t length;
    uint8_t type;
}Array;

Array * array_create(const uint32_t, const uint8_t);
uint8_t array_is_empty(Array *);
void array_delete(Array *, const void *);
uint32_t array_length(Array *);
void array_push(Array *, const void *);
void * array_pop(Array *);
void * array_pop_front(Array *);
void array_free(Array *);
void array_print(Array *, void (* print)(const void *));
void * array_find(Array *, const void *);

#endif // ! ARRAY_H