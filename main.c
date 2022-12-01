#include<stdio.h>
#include "my_mat.h"


int matrix[10][10] = {0};

int main(){

    char selection = '0';
    int executed = 0;
    while(1){
        scanf("%c", &selection);
        if(selection == 'A'){
            A(matrix);
            executed = 0;
        }
        if(selection == 'B'){
            B(matrix, executed);
            executed = 1;
        }
        if(selection == 'C'){
            C(matrix,executed);
            executed = 1;
        }
        if(selection == 'D'){
            break;
        }
    }
    return 0;
}