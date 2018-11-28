#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>
#include "array.h"
#include "linked_list.h"

typedef struct {
    void * src;
    void * dst;
    int32_t weight;
    uint8_t type;
}Graph_Pair;

typedef struct {
    Linked_list ** G;
    Array * vertice;
    uint32_t n_vertice;
    uint32_t n_edge;
}Graph;

Graph_Pair * graph_pair_create(const uint8_t);
Graph * graph_create(const uint32_t, const uint8_t);
uint32_t graph_get_vertice_index(Graph *, const void *);
Linked_list * graph_find_vertice(Graph *, const void *);
void graph_push(Graph *, const Graph_Pair *);
void graph_push_batch(Graph *, const Graph_Pair *, const uint32_t);
void graph_free(Graph *);
void graph_pair_free(Graph_Pair *);
void graph_print(Graph *, void (*)(const void *));

#endif // ! GRAPH_H