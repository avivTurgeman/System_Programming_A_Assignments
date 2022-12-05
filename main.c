#include<stdio.h>
#include "my_mat.h"


// int matrix[10][10] = {{0, 3, 1, 0, 0, 2, 0, 0, 0, 0}, {3, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 5, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 4, 1, 1}, {2, 0, 0, 0, 0, 0, 2, 0, 0, 0}, {0, 0, 0, 0, 0, 2, 0, 0, 0, 0}, {0, 0, 0, 5, 4, 0, 0, 0, 0, 2}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 2, 0, 0}};
int matrix[10][10] = {0};
int main(){

    char selection = '0';
    int executed = 0;
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
            break;
        }
    }
    return 0;
}