#include <stdio.h>
#include "array.h"

void p(const void * key)
{
    printf(" -- %d\n", *((int *) key));
}

int main()
{
    Array * array = array_create(4, sizeof(int));
    int data = 10;
    array_push(array, &data);
    data = 20;
    array_push(array, &data);
    data = 30;
    array_push(array, &data);
    data = 40;
    array_push(array, &data);
    data = 100;
    array_push(array, &data);
    array_push(array, &data);
    array_push(array, &data);
    array_push(array, &data);
    array_push(array, &data);

    array_pop(array);
    array_pop(array);
    data = 10;
    printf("%p %d\n\n", array_find(array, &data), *((int *)array_find(array, &data)));

    array_print(array, p);
    array_free(array);
    return 0;
}