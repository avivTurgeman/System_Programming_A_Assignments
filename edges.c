#include "edges.h"

pedge newEdge(int weight, pnode endPoint, pedge nextEdge){
    pedge e = (pedge) malloc(sizeof(edge));
    e->endpoint = endPoint;
    e->weight = weight;
    e->next = nextEdge;

    return e;
}

void insurtLastEdge(int weight, pnode endPoint, pedge *firstEdge){
    edge **e = firstEdge;
    while (*e)
    {
        e = &((*e)->next)
    }

    *e = newEdge(weight, endPoint, NULL);
}

