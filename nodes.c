#include "nodes.h"

// B
void insert_node_cmd(pnode *head){
    int nodeNum, weight, destNode;
    
    scanf("%d", &nodeNum);
    insert_node(head, nodeNum);
    
    while(scanf("%d %d", &destNode, &weight) == 2){
        pnode currNode = findNode(*head, nodeNum);
        insertLastEdge(weight, findNode(*head, destNode), &(currNode->edges));
    }
}

void insert_node(pnode* head, int nodeNum){
    node **p = head;
    while(*p){
        p = &((*p)->next);
    }
    *p = newNode(nodeNum, NULL);
}

pnode newNode(int nodeNum, pnode nextNode){
    pnode p = (pnode) malloc(sizeof(node));
    p->node_num = nodeNum; 
    p->next = nextNode;
    return p;
}

pnode findNode(pnode head, int node_num){
    if(head->node_num == node_num){
        return head;
    }
    pnode n = head;
    while(n->node_num != node_num){
        n = n->next;
    }
    return n;
}

// D
void delete_node_cmd(pnode* head){
    int nodeNumber;
    scanf("%d", &nodeNumber);

    delete_node(head, nodeNumber);
}

void delete_node(pnode* head, int nodeNum){

    pnode *v = head;
    while(1){
        if((*v)->node_num != nodeNum){
            pedge e = (*v)->edges;
            if(e->next != NULL){
            }
            pedge prevEdge = NULL;
            while (e){
                if(e->endpoint->node_num == nodeNum){
                    if(prevEdge){
                        prevEdge->next = e->next;
                        if(prevEdge->next == NULL){
                        }
                    } else {
                        (*v)->edges = e->next;
                    }
                    free(e);
                    goto nextNode;
                }
                prevEdge = e;
                e = e->next;
            }
        }
        nextNode:
        v = &((*v)->next);
        if(!(*v)){
            break;
        }
    }

    pnode *p = head;
    pnode prevNode = NULL;
    while (*p) {
        if ((*p)->node_num == nodeNum) {
            pedge e = (*p)->edges;
            if(e->next != NULL){
            }
            while (e) {
                pedge temp = e;
                e = e->next;
                free(temp);
                if(e){
                    if(e->next != NULL){
                    }
                }
            }
            pnode temp;
            if (prevNode) {
                temp = prevNode->next;
                prevNode->next = (*p)->next;
            } else {
                temp = *head;
                *head = (*p)->next;
            }
            free(temp);
            return;
        }
        prevNode = *p;
        p = &((*p)->next);
        if((*p)){
        }
    }
}
