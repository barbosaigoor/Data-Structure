#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "graph_i.h"

Graph_i * bfs(const uint32_t);
uint32_t get_repeated_vertices(Graph_i *, Graph_i *);

int main()
{
	int n_station, n_query, a_src, a_dst, b_src, b_dst;
	puts("Number of Stations- Query quantity");
	scanf("%d %d", &n_station, &n_query);
	Graph_i * graph = graph_i_create(n_station + 1),
			* graph_a, 
			* graph_b;

	for(uint32_t i = 1; i < n_station; ++i)
	{
		scanf("%d %d", &a_src, &a_dst);
		graph_i_push(graph, a_src, a_dst);	
	}
	puts("Query");
	for(uint32_t i = 1; i < n_query; ++i)
	{
		scanf("%d %d %d %d", &a_src, &a_dst, &b_src, &b_dst);
		graph_a = bfs(graph, a_src, a_dst);
		graph_b = bfs(graph, b_src, b_dst);
		printf("%d\n", get_repeated_vertices(graph_a, graph_b));
	}

	graph_i_print(graph);
	graph_i_free(graph);
	return 0;
}

Graph_i * bfs(const uint32_t)
{
	Graph_i * graph;
	return graph;
}

uint32_t get_repeated_vertices(Graph_i * graph_a, Graph_i * graph_b)
{
	uint32_t n_vertices = 0;
	Linked_list_Node * node;
	for(uint32_t i = 0; i < graph_a->n_vertice; ++i)
	{
		node = graph_b->G[i];
		for(uint32_t j = 0; j < graph_a->G[i]->size; ++j, node = node->next)
			if(linked_list_find(graph_a->G[i], node))
				++n_vertices;
	}
	return n_vertices / 2;
}
