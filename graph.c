#include "nodes.h"

void build_graph_cmd(pnode *head){
    int num;
    char switcher;
    scanf("%d", &num);

    *head = newNode(0, NULL);

    for(int i = 1; i < num; i++){
        insert_node_cmd(head);
    }
    

}   

void deleteGraph_cmd(pnode* head){

}

void printGraph_cmd(pnode head){

}

