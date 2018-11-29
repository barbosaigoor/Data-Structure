#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

#define i32_for(size) for(uint32_t _i_ = 0; _i_ < size; ++_i_)

Linked_list * linked_list_create(const uint8_t type)
{
    Linked_list * ll = malloc(sizeof(Linked_list));
    ll->node = NULL;
    ll->size = 0;
    ll->type = type;
    return ll;
}

Linked_list_Node * linked_list_create_node(const uint8_t type, const void * key)
{
    Linked_list_Node * node = malloc(sizeof(Linked_list_Node));
    node->key = malloc(sizeof(type));
    memcpy(node->key, key, type);
    node->next = NULL;
    return node;
}

uint8_t linked_list_is_empty(Linked_list * llist)
{
    return llist->size == 0;
}

void linked_list_node_free(Linked_list_Node * node)
{
    free(node->key);
    free(node);
}

void linked_list_delete(Linked_list * llist, const void * key)
{
    if(!memcmp(llist->node->key, key, llist->type))
    {
        linked_list_pop(llist);
        return;
    }
    else if(llist->size <= 1)
        return;
    Linked_list_Node * node = llist->node->next;
    Linked_list_Node * prev_node = llist->node;
    i32_for(llist->size - 1)
    {
        if(!memcmp(node->key, key, llist->type))
        {
            linked_list_node_free(node);
            prev_node->next = node->next;
            --llist->size;
            return;
        }
        node = node->next;
        prev_node = prev_node->next;
    }
}

uint32_t linked_list_length(Linked_list * llist)
{
    return llist->size;
}

void linked_list_push(Linked_list * llist, const void * key)
{
    Linked_list_Node * node = llist->node;
    llist->node = linked_list_create_node(llist->type, key);
    llist->node->next = node;
    ++llist->size;
}

void linked_list_pop(Linked_list * llist)
{
    if(!linked_list_is_empty(llist))
    {
        Linked_list_Node * node = llist->node;
        llist->node = llist->node->next;
        free(node);
        --llist->size;
    }
}

void linked_list_free(Linked_list * llist)
{
    Linked_list_Node * node = llist->node;
    i32_for(llist->size)
    {
        llist->node = llist->node->next;
        free(node);
        node = llist->node;
    }
    free(llist);
}

void linked_list_print(Linked_list * llist, void (*print)(const void *))
{
    Linked_list_Node * node = llist->node;
    printf("\n");
    i32_for(llist->size)
    {
        print(node->key);
        node = node->next;
    }
    printf("\n");
}

Linked_list_Node * linked_list_find(Linked_list * llist, const void * key)
{
    Linked_list_Node * node = llist->node;
    i32_for(llist->size)
    {
        if(!memcmp(node->key, key, llist->type))
            return node->key;
        node = node->next;
    }
    return NULL;
}