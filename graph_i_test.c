#include "graph_i.h"

int main()
{
	Graph_i * g = graph_i_create(10);
	graph_i_push(g, 1, 0);
	graph_i_push(g, 1, 2);
	graph_i_push(g, 1, 3);
	graph_i_push(g, 3, 2);
	graph_i_push(g, 3, 5);
	graph_i_push(g, 5, 8);
	graph_i_print(g);
	graph_i_free(g);
	return 0;
}
