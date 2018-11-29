#include <stdio.h>
#include "queue.h"

void p(void * key)
{
    printf("-- %d\n", *((int *) key));
}

int main()
{
    Queue * q = queue_create(sizeof(int));
    int d = 10;
    queue_push(q, &d);
    d = 20;
    queue_push(q, &d);
    d = 30;
    queue_push(q, &d);
    d = 340;
    queue_push(q, &d);
    d = 340;
    queue_push(q, &d);
    d = 340;
    queue_push(q, &d);
    d = 340;
    queue_push(q, &d);
    queue_print(q, p);

    queue_pop(q);
    queue_pop(q);
    queue_pop(q);
    queue_pop(q);
    queue_pop(q);
    queue_pop(q);
    queue_print(q, p);
    d = 1;
    queue_push(q, &d);
    d = 2;
    queue_push(q, &d);
    d = 3;
    queue_push(q, &d);
    queue_print(q, p);
    printf("\n~~ HEAD: %d \tTAIL: %d\n", q->head, q->tail);
    printf("\n>> SIZE: %d \tLENGTH: %d\n", q->size, q->length);
    queue_free(q);
    return 0;
}