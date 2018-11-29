#include <stdio.h>
#include "linked_list.h"

void p(void * key) 
{
    printf("-- %d\n", *((int *) key));
}

int main()
{
    Linked_list * ll = linked_list_create(sizeof(int));
    int d = 10;
    linked_list_push(ll, &d);
    d = 30;
    linked_list_push(ll, &d);
    d = 100;
    linked_list_push(ll, &d);
    d = 400;
    linked_list_push(ll, &d);
    // linked_list_pop(ll);
    linked_list_pop(ll);

    linked_list_print(ll, p);
    d = 10;
    printf("\n%p\n", linked_list_find(ll, &d));
    d = 3012;
    printf("\n%p\n", linked_list_find(ll, &d));

    d = 1001;
    linked_list_delete(ll, &d);
    d = 10;
    linked_list_delete(ll, &d);
    d = 30;
    linked_list_delete(ll, &d);
    linked_list_print(ll, p);

    linked_list_free(ll);
    return 0;
}