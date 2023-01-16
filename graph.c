#include "nodes.h"

void build_graph_cmd(pnode *head){
   char c;
   int numNodes;
   printf("If you wish to create a new graph enter 'A' and the number of vertices in the graph");
   scanf("%c %d", &c, &numNodes);

   if(c=='A') {

    *head = newNode(0,NULL);
    for(int i=1; i<numNodes; i++){
        insert_node_cmd(head);
    } 

    int weight, sourceNode, destNode;
    char h;
    printf("Enter the char n followed by the vertic number you wish to start working on followed by the the vertic destination of the new edge followed by its weight ");
    
    while(scanf("%c", &h) != EOF){
        if(h=='n'){
            scanf("%d", &sourceNode);
            while(scanf("%d %d", &destNode, &weight) != EOF){
                pnode currNode = findNode(*head,sourceNode);
                insertLastEdge(weight,findNode(*head,destNode),&(currNode->edges));
            }
        }
    }
   }
}   

pnode findNode(pnode head,int node_num){
    if(head->node_num == node_num){
        return head;
    }
    pnode n = head;
    while(n->node_num != node_num){
        n = n->next;
    }
    return n;
}

void deleteGraph_cmd(pnode* head){
    
}

void printGraph_cmd(pnode head){

}

