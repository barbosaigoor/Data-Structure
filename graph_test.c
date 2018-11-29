#include <stdio.h>
#include "graph.h"

#if MAIN
void p(const void * key)
{ printf(" -- %c", *((char *) key)); }
#else
void p(const void * key)
{ printf(" -- %d", *((int *) key)); }
#endif

int main()
{
    #if 0
    graph_t vertice[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    Graph * g = graph_create(10);
    Graph_Pair pair[] = {
        {'1', '4'},
        {'8', '0'},
        {'4', '5'},
        {'4', '3'},
        {'3', '2'},
        {'3', '7'},
        {'7', '6'},
        {'7', '8'},
        {'8', '9'},
    };
    graph_push_batch(g, pair, 9);
    graph_print(g, p);
    array_print(g->vertice, p);
    graph_free(g);
    #endif
    Graph * g = graph_create(10, sizeof(int));
    int src, dst, type = sizeof(int);
    Graph_Pair * pair = graph_pair_create(&src, &dst, 0,type);

    src = 0;
    pair->src = &src;
    dst = 3;
    pair->dst = &dst;
    graph_push(g, pair);

    src = 7;
    pair->src = &src;
    dst = 9;
    pair->dst = &dst;
    graph_push(g, pair);

    src = 3;
    pair->src = &src;
    dst = 4;
    pair->dst = &dst;
    graph_push(g, pair);

    src = 3;
    pair->src = &src;
    dst = 2;
    pair->dst = &dst;
    graph_push(g, pair);

    src = 2;
    pair->src = &src;
    dst = 1;
    pair->dst = &dst;
    graph_push(g, pair);

    src = 2;
    pair->src = &src;
    dst = 6;
    pair->dst = &dst;
    graph_push(g, pair);

    src = 6;
    pair->src = &src;
    dst = 5;
    pair->dst = &dst;
    graph_push(g, pair);

    src = 6;
    pair->src = &src;
    dst = 7;
    pair->dst = &dst;
    graph_push(g, pair);

    src = 7;
    pair->src = &src;
    dst = 8;
    pair->dst = &dst;
    graph_push(g, pair);
    // {
    //     {0, 3},
    //     {7, 9},
    //     {3, 4},
    //     {3, 2},
    //     {2, 1},
    //     {2, 6},
    //     {6, 5},
    //     {6, 7},
    //     {7, 8},
    // };
    graph_print(g, p);
    array_print(g->vertice, p);
    graph_free(g);
    return 0;
}