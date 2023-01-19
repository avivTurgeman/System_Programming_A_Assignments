#ifndef GRAPH_
#define GRAPH_

#define TRUE 1
#define FALSE 0

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
    int dist;
    pnode prev;
} node, *pnode;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head);
void deleteGraph_cmd(pnode* head);
void shortestPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
