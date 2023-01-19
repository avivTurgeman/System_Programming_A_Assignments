#include "nodes.h"

// A
void build_graph_cmd(pnode* head){
   if(head != NULL){
        deleteGraph_cmd(head);
   }

   int graph_size;

   scanf("%d", &graph_size);

    *head = newNode(0,NULL);
    for(int i = 1; i < graph_size; i++){
        insert_node(head,i);
    } 
}

void deleteGraph_cmd(pnode* head){
    while((*head)){
        delete_node(head, (*head)->node_num);
    }
}

void printGraph_cmd(pnode head)
{
    printf("[src]---(weight)--->[dest]\n");
    while (head != NULL)
    {
        pedge current_edge = head->edges;
        if (current_edge == NULL)
        {
            printf("[%d]\n", head->node_num);
        }
        while (current_edge != NULL)
        {
            printf("[%d]---(%d)--->[%d]\n", head->node_num, current_edge->weight, current_edge->endpoint->node_num);
            current_edge = current_edge->next;
        }
        head = head->next;
    }
}

