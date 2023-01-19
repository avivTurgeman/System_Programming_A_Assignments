#include "nodes.h"
#include "algo.h"

int main(){
    pnode head = NULL;
    pnode *P_head = &head;
    char choose = '0';
    while(choose != EOF){
        scanf("%c", &choose);

        if(choose == 'A'){
            build_graph_cmd(P_head);
            head = *P_head;
        }
        else if(choose == 'n'){
            insert_node_cmd(P_head);
            head = *P_head;            
        }
        else if(choose == 'B'){
            insert_node_cmd(P_head);
            head = *P_head;
        }
        else if(choose == 'D'){
            delete_node_cmd(P_head);
            head = *P_head; 
        }
        else if(choose == 'P'){
            printGraph_cmd(*P_head);
        }
        else if(choose == 'S'){
            shortestPath_cmd(head);
        }
        else if(choose == 'T'){
            TSP_cmd(head);
        }
    }
}