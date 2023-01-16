#include "nodes.h"

void insert_node_cmd(pnode *head){
    node **p = head;
    int nodeNum = 1;
    while(*p){
        p = &((*p)->next);
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

void delete_node_cmd(pnode* head){
    char c;
    int nodeNum;
    scanf("%c %d",&c,&nodeNum);

    if (c == 'D') {
        pnode *p = head;
        pnode prevNode = NULL;
        while (*p) {
            if ((*p)->node_num == nodeNum) {
                pedge e = (*p)->edges;
                while (e) {
                    pedge temp = e;
                    e = e->next;
                    free(temp);
                }
                if (prevNode) {
                    prevNode->next = (*p)->next;
                } else {
                    *head = (*p)->next;
                }
                free(*p);
                break;
            }
            prevNode = *p;
            p = &((*p)->next);
        }
    }
}
