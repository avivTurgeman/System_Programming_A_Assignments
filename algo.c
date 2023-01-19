#include "algo.h"

void shortestPath_cmd(pnode head){
    int start, dest;
    scanf("%d %d", &start, &dest);
    pnode Pstart = findNode(head, start);
    pnode Pdest = findNode(head, dest);
    pnode *p = &head;
    dijkstra(head, Pstart);
    
    if (Pdest->prev == NULL) {
        printf("Dijsktra shortest path: -1\n");
    } else {
        printf("Dijsktra shortest path: %d\n", Pdest->dist);
    }
}

void TSP_cmd(pnode head){
    int k, node_num, min_path = INT_MAX;
    scanf("%d", &k);
    pnode nodes[k];
    for(int i=0; i<k; i++){
        scanf("%d", &node_num);
        nodes[i] = findNode(head, node_num);
    }
    for(int i = 0; i < k; i++){
        dijkstra(head, nodes[i]);
        int path = 0;
        for(int j=0; j<k; j++){
            if(nodes[j]->prev == NULL){
                path = -1;
                break;
            }
            path += nodes[j]->dist;
        }
        if(path != -1 && path < min_path){
            min_path = path;
        }
    }
    printf("TSP shortest path: %d\n", min_path);
}

void dijkstra(pnode head, pnode start) {
    priority_queue* q = create_queue(get_graph_len());
    pnode curr = head;
    while (curr) {
        curr->dist = INT_MAX;
        curr->prev = NULL;
        if(curr != start){
            push(q,curr->node_num, curr->dist);
        }
        curr = curr->next;
    }
    start->dist = 0;
    printf("pair pushed node_num: %d\n", start->node_num);
    push(q,start->node_num,0);
    while (!is_empty(q)) {
        pair *p = pop(q);
        pnode u = findNode(head, p->node_num);
        printf("q->pop = %d, q->dist = %d\n", p->node_num, p->dist);
        pedge e = u->edges;
        while (e != NULL) {
            relax(u, e);
            e = e->next;
        }
    }
    free_queue(q);
}

void relax(pnode u, pedge e){
    pnode v = e->endpoint;
    if ((v->dist) > (u->dist + e->weight)) {
        v->dist = (u->dist + e->weight);
        v->prev = u;
    }
}