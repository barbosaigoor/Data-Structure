#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph_i.h"

Graph_i * graph_i_create(const uint32_t n_vertice)
{
    Graph_i * graph = malloc(sizeof(Graph_i));
    graph->G = (Linked_list **) malloc(sizeof(Linked_list *) * n_vertice);
    for(uint32_t i = 0; i < n_vertice; ++i)
        graph->G[i] = linked_list_create(sizeof(uint32_t));
    graph->n_vertice = n_vertice;
    graph->n_edge = 0;
    return graph;
}

static inline char is_valid_vertice(Graph_i * graph, const uint32_t vertice)
{
	return vertice >= 0 && vertice < graph->n_vertice;
}

Linked_list * graph_i_find_vertice(Graph_i * graph, const uint32_t vertice)
{
    return is_valid_vertice(graph, vertice) ? graph->G[vertice] : NULL;
}

void graph_i_push(Graph_i * graph, const uint32_t src, const uint32_t dst)
{
	if(is_valid_vertice(graph, src) && is_valid_vertice(graph, dst))
	{
		linked_list_push(graph->G[src], &dst);    
		linked_list_push(graph->G[dst], &src);    
		++ graph->n_edge;
	}
}

void graph_i_free(Graph_i * graph)
{
    for(uint32_t i = 0; i < graph->n_vertice; ++i)
        linked_list_free(graph->G[i]);
    free(graph->G);
    free(graph);
}

static void print(const void * vertice)
{
	printf("%d, ", *((uint32_t *) vertice));
}

void graph_i_print(Graph_i * graph)
{
    printf("~~\n");
    for(uint32_t i = 0; i < graph->n_vertice; ++i) 
    {
		printf("[%d]", i);
        linked_list_print(graph->G[i], print);
    }
    printf("\n");
}
