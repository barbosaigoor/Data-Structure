#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>

typedef struct {
    void * key;
    void * next;
}Linked_list_Node;

typedef struct {
    Linked_list_Node * node;
    uint32_t size;
    uint8_t type;
    // uint32_t space; // Extra space for optimization
}Linked_list;

Linked_list * linked_list_create(const uint8_t);
Linked_list_Node * linked_list_create_node(const uint8_t, const void *);
uint8_t linked_list_is_empty(Linked_list *);
void linked_list_node_free(Linked_list_Node *);
void linked_list_delete(Linked_list *, const void *);
uint32_t linked_list_length(Linked_list *);
void linked_list_push(Linked_list *, const void *);
void linked_list_pop(Linked_list *);
void linked_list_free(Linked_list *);
void linked_list_print(Linked_list *, void (* print)(const void *));
Linked_list_Node * linked_list_find(Linked_list *, const void *);

#endif // ! LINKED_LIST_H