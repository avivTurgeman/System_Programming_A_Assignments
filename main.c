#include "nodes.h"
#include "algo.h"

int main(){
    pnode head = NULL;
    char choose = '';
    while(scanf("%c", &choose) != EOF){
        if(choose == 'A'){
            build_graph_cmd(*head);
        }
    }

}