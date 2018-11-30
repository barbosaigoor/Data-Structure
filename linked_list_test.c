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

    linked_list_push_back(ll, &d);
    d = 30;
    linked_list_push_back(ll, &d);
    d = 100;
    linked_list_push_back(ll, &d);
    d = 400;
    linked_list_push_back(ll, &d);
    linked_list_print(ll, p);
    puts("######");
    
    for(int i = 0; i < 1000; ++i)
        linked_list_pop(ll);
    
    d = 10;
    linked_list_push(ll, &d);
    d = 30;
    linked_list_push(ll, &d);
    d = 100;
    linked_list_push(ll, &d);
    d = 400;
    linked_list_push(ll, &d);
    linked_list_print(ll, p);
    puts("######");

    d = 10;
    printf("%p\n", linked_list_find(ll, &d));
    d = 3012;
    printf("%p\n", linked_list_find(ll, &d));
    d = 3012;
    printf("Index: 3012 -> %d\n", linked_list_find_index(ll, &d));
    d = 10;
    printf("Index: 10 -> %d\n", linked_list_find_index(ll, &d));
    d = 400;
    printf("Index: 400 -> %d\n", linked_list_find_index(ll, &d));

    d = 1001;
    linked_list_delete(ll, &d);
    d = 10;
    linked_list_delete(ll, &d);
    d = 400;
    linked_list_delete(ll, &d);
    linked_list_print(ll, p);

    linked_list_free(ll);
    return 0;
}