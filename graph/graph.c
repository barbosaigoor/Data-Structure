#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

Graph_Pair * graph_pair_create(const uint8_t type)
{
    Graph_Pair * pair = malloc(sizeof(Graph_Pair));
    pair->src = malloc(type);
    pair->dst = malloc(type);
    pair->weight = 0;
    pair->type = type;
    return pair;
}

Graph * graph_create(const uint32_t n_vertice, const uint8_t type)
{
    Graph * graph = malloc(sizeof(Graph));
    graph->G = (Linked_list **) malloc(sizeof(Linked_list *) * n_vertice);
    graph->vertice = array_create(n_vertice, type);
    for(uint32_t i = 0; i < n_vertice; ++i)
        graph->G[i] = linked_list_create(type);
    graph->n_vertice = n_vertice;
    graph->n_edge = 0;
    return graph;
}

uint32_t graph_get_vertice_index(Graph * graph, const void * vertice)
{
    void * v_ptr = graph->vertice->content;
    for(uint32_t i = 0; i < graph->vertice->length; ++i, v_ptr += graph->vertice->type)
        if(!memcmp(v_ptr, vertice, graph->vertice->type))
            return i;
    return UINT32_MAX;
}

Linked_list * graph_find_vertice(Graph * graph, const void * vertice)
{
    uint32_t i = graph_get_vertice_index(graph, vertice);
    return i == UINT32_MAX ? NULL : graph->G[i];
}

void graph_push(Graph * graph, const Graph_Pair * g_pair)
{
    // Append a new vertice if not exists
    Linked_list * vertice_1 = graph_find_vertice(graph, g_pair->src);
    Linked_list * vertice_2 = graph_find_vertice(graph, g_pair->dst);
    if(!vertice_1)
    {
        array_push(graph->vertice, g_pair->src);
        vertice_1 = graph_find_vertice(graph, g_pair->src);
    }
    if(!vertice_2)
    {
        array_push(graph->vertice, g_pair->dst);
        vertice_2 = graph_find_vertice(graph, g_pair->dst);
    }
    linked_list_push(vertice_1, g_pair->dst);    
    linked_list_push(vertice_2, g_pair->src);
}

void graph_push_batch(Graph * graph, const Graph_Pair * g_pair, const uint32_t size)
{
    for(uint32_t i = 0; i < size; ++i)
        graph_push(graph, g_pair + i);
}

void graph_free(Graph * graph)
{
    for(uint32_t i = 0; i < graph->n_vertice; ++i)
        linked_list_free(graph->G[i]);
    free(graph->G);
    array_free(graph->vertice);
    free(graph);
}

void graph_pair_free(Graph_Pair * pair)
{
    free(pair->src);
    free(pair->dst);
    free(pair);
}

void graph_print(Graph * graph, void (* print)(const void *))
{
    printf("~~\n");
    for(uint32_t i = 0; i < graph->n_vertice; ++i) 
    {
        printf("## %d", *((int *) (graph->vertice->content + (graph->vertice->type * i))));
        linked_list_print(graph->G[i], print);
    }
    printf("\n");
}