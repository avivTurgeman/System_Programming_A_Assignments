#include<stdio.h>
#include "my_mat.h"


int matrix[10][10] = {0};

int main(){

    char selection = "0";
    int flag = 1;
    int executed = 1;
    while(1){
        scanf("%c", &selection);
        if(selection == 'A'){
            A(matrix);
            executed = 1;
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