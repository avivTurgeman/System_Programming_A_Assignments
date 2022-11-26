#include<stdio.h>
#include "my_mat.h"


int matrix[10][10];

int main(){

    char selection;
    int flag = 1;
    int executed = 1;
    while(1){
        scanf("%c", &selection);
        if(selection == 'A'){
            A(matrix);
        }
        if(selection == 'B'){
            B(matrix, executed);
            executed = 0;
        }
        if(selection == 'C'){
            C(matrix,executed);
            executed = 0;
        }
        if(selection == 'D'){
            break;
        }
        else{
            flag = 0;
            break;
        }
    }
    if(flag){
        return 0;
    }
    return -1;
}