#include "nodes.h"

void insert_node_cmd(pnode *head){
    node **p = head;
    int nodeNum = 1;
    while(*p){
        p = &(*(p)->next);
        nodeNum++;
    }

    *p = newNode(nodeNum, NULL);
}

pnode newNode(int nodeNum, pnode nextNode){
    pnode p = (pnode) malloc(sizeof(node));
    p->node_num = nodeNum;
    // p->edges = ADD HERE!!!!!!    
    p->next = nextNode;
    return p;
}

void delete_node_cmd(pnode *head){
    
}
