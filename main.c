#include<stdio.h>
#include "my_mat.h"

int main(){

    int matrix[10][10] = {0};

    char selection;
    int executed;
    while(1){
        scanf("%s", &selection);
        if(selection == 'A'){
            A(matrix);
            executed = 0;
        }
        else if(selection == 'B'){
            B(matrix, executed);
            executed = 1;
        }
        else if(selection == 'C'){
            C(matrix,executed);
            executed = 1;
        }
        else if(selection == 'D'){
            break;
        }
        else if(selection != 'A' || selection != 'B' || selection != 'C' || selection != 'D'){
            return 1;
        }
    }
    return 0;
}