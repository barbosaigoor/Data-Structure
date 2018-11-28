#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

Array * array_create(const uint32_t size, const uint8_t type)
{
    Array * array = malloc(sizeof(Array));
    array->content = malloc(size * type);
    memset(array->content, 0, size * type);
    array->size = size;
    array->length = 0;
    array->type = type;
    return array;
}

uint8_t array_is_empty(Array * array)
{
    return array->length == 0;
}

uint8_t array_is_full(Array * array)
{
    return array->length == array->size;
}

uint32_t array_length(Array * array)
{
    return array->length;
}

void array_push(Array * array, const void * key)
{
    if(array_is_full(array))
        return;
    memcpy(array->content + (array->length * array->type), key, array->type);
    ++array->length;
}

void * array_pop_front(Array * array)
{

}

void * array_pop(Array * array)
{
    if(!array_is_empty(array))
    {
        void * v_ptr = malloc(array->type);
        memcpy(v_ptr, array->content + (array->length - 1), array->type);
        --array->length;
        return v_ptr;
    }
    return NULL;
}

void array_free(Array * array)
{
    free(array->content);
    free(array);
}

void array_print(Array * array, void (*print)(const void *))
{
    if(array_is_empty(array))
    {
        puts("Empty array");
        return;
    }
    void * v_ptr = array->content;
    for(uint32_t i = 0; i < array->length; ++i, v_ptr += array->type)
        print(v_ptr);
    printf("\n");
}

void * array_find(Array * array, const void * key)
{
    void * v_ptr = array->content;
    for(uint32_t i = 0; i < array->length; ++i, v_ptr += array->type)
        if(!memcmp(v_ptr, key, array->type))
            return v_ptr;
    return NULL;
}