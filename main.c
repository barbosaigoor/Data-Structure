#include <stdio.h>
#include "graph.h"

void p(const void * key)
{
    printf("-- %d\n", *((int *) key));
}

Linked_list * breadth_first_search(const Graph *, const uint8_t);

int main()
{
    uint32_t n_stations, n_consults, u, v, a, b, c, d;
    puts("N stations & N consults");
    scanf("%d %d", &n_stations, &n_consults);
    Graph * graph = graph_create(n_stations, sizeof(int));
    Graph_Pair * pair = graph_pair_create(sizeof(int));
    
    for(uint32_t i  = 1; i < n_stations; ++i)
    {
        puts("U & V");
        scanf("%d %d", &u, &v);
        *((int *) pair->src) = u;
        *((int *) pair->dst) = v;
        graph_push(graph, pair);
    }
    graph_print(graph, p);
    for(uint32_t i  = 0; i < n_consults; ++i)
    {
        puts("A B C D");
        scanf("%d %d %d %d", &a, &b, &c, &d);
    }

    graph_pair_free(pair);
    graph_free(graph);
    return 0;
}

Linked_list * breadth_first_search(const Graph * graph, void * src, const uint8_t size)
{
    Linked_list * path = linked_list_create(size);
    (graph_find(graph, src));
    linked_list_free(path);
}