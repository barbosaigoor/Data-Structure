#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "graph_i.h"
#include "linked_list.h"
#include "queue.h"

// Expected a pointer
#define UINT32(x) (*((uint32_t *) x))

Linked_list * bfs(Graph_i *, const uint32_t, const uint32_t);
uint32_t get_repeated_vertices(Linked_list *, Linked_list *);

int main()
{
	int n_station, n_query, a_src, a_dst, b_src, b_dst;
	puts("Number of Stations- Query quantity");
	scanf("%d %d", &n_station, &n_query);
	Graph_i * graph = graph_i_create(n_station + 1);
	Linked_list * ll_a, 
				* ll_b;

	for(uint32_t i = 1; i < n_station; ++i)
	{
		scanf("%d %d", &a_src, &a_dst);
		graph_i_push(graph, a_src, a_dst);	
	}
	puts("Query");
	for(uint32_t i = 0; i < n_query; ++i)
	{
		puts("A B C D");
		scanf("%d %d %d %d", &a_src, &a_dst, &b_src, &b_dst);
		ll_a = bfs(graph, a_src, a_dst);
		ll_b = bfs(graph, b_src, b_dst);
		printf("%d\n", get_repeated_vertices(ll_a, ll_b));
		linked_list_free(ll_a);
		linked_list_free(ll_b);
	}

	graph_i_print(graph);
	graph_i_free(graph);
	return 0;
}

static void print(void * key)
{
	printf("%d - ", UINT32(key));
}

Linked_list * bfs(Graph_i * graph, const uint32_t src, const uint32_t dst)
{
	Queue * queue = queue_create(sizeof(Linked_list *));
	Linked_list * path = linked_list_create(sizeof(uint32_t));
	Linked_list_Node * adjacents;
	uint32_t current, adjacent;
	char visited[graph->n_vertice];

	for(uint32_t i = 0; i < graph->n_vertice; ++i)
		visited[i] = 0;

	visited[src] = 1;

	linked_list_push(path, &src);

	queue_push(queue, &src);
	
	// While not dst
	while(!queue_is_empty(queue))
	{
		current = UINT32(queue_pop(queue)->node->key);
		// Get sucessors
		adjacents = graph->G[current]->node;
		while(adjacents)
		{
			adjacent = UINT32(adjacents->key);
			if(adjacent == dst)
			{
				linked_list_push(path, &adjacent);
				return path;
			}
			// If not in visited
			if(!visited[adjacent])
			{
				visited[adjacent] = 1;
				queue_push(queue, &adjacent);
			}
			adjacents = adjacents->next;
		}
	}

	queue_free(queue);
	return NULL;
}

uint32_t get_repeated_vertices(Linked_list * ll_a, Linked_list * ll_b)
{
	if(!ll_a || !ll_b)
		return 0;
	uint32_t n_vertices = 0;
	Linked_list_Node * node = ll_b->node;
	for(uint32_t i = 0; i < linked_list_length(ll_a); ++i, node = ll_b->node)
		for(uint32_t j = 0; j < linked_list_length(ll_b); ++j, node = node->next)
			if(linked_list_find(ll_a, node->key))
				++n_vertices;
	return n_vertices;
}
