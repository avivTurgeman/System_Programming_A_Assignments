#include "nodes.h"

int graphLen = 0;

// A
void build_graph_cmd(pnode* head){
   if(head != NULL){
        deleteGraph_cmd(head);
   }
   
   int numNodes;
   scanf("%d", &numNodes);
   graphLen = numNodes;

    *head = newNode(0,NULL);
    for(int i=1; i<numNodes; i++){
        insert_node(head,i);
    } 

    int weight, sourceNode, destNode;
    char h;

    //Enter the char n followed by the vertic number you wish to start working 
    //on followed by the the vertic destination of the new edge followed by its weight
    while(scanf("%c", &h) != EOF){
        if(h=='n'){
            scanf("%d", &sourceNode);
            while(scanf("%d %d", &destNode, &weight) != EOF){
                pnode currNode = findNode(*head, sourceNode);
                insertLastEdge(weight, findNode(*head, destNode), &(currNode->edges));
            }
        }
    }
}   

void deleteGraph_cmd(pnode* head){
    while((*head)){
        delete_node(head, (*head)->node_num);
    }
}

void printGraph_cmd(pnode head)
{
    printf("Graph representation [src]---(weight)--->[dest]\n");
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

