#ifndef GRAPH_I_H
#define GRAPH_I_H

#include <stdint.h>
#include "linked_list.h"

typedef struct {
    Linked_list ** G;
    uint32_t n_vertice;
    uint32_t n_edge;
}Graph_i;

Graph_i * graph_i_create(const uint32_t);
Linked_list * graph_i_find_vertice(Graph_i *, const uint32_t);
void graph_i_push(Graph_i *, const uint32_t, const uint32_t);
void graph_i_free(Graph_i *);
void graph_i_print(Graph_i *);

#endif // ! GRAPH_I_H
