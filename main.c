#include "nodes.h"
#include "algo.h"

int main(){
    pnode head = NULL;
    char choose = '\0';
    while(scanf("%c", &choose) != EOF){
        if(choose == 'A'){
            build_graph_cmd(&head);
        }
        else if(choose == 'B'){
            insert_node_cmd(&head);
        }
        else if(choose == 'D'){
            delete_node_cmd(&head);
        }
        else if(choose == 'P'){
            printGraph_cmd(head);
            return 0;
        }
    }
}