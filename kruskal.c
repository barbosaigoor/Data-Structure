#include "kruskal.h"
#include <stdlib.h>

static int cmpGraph(Array * a, Array * b) 
{
	return 0;
}

Graph * kruskal(Graph * graph)
{
    Graph * min_graph = graph_create(graph->n_vertice, graph->vertice->type);
	qsort(min_graph->vertice, min_graph->n_edge, min_graph->vertice->type, cmpGraph);
    return min_graph;
}
