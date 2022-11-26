#include "my_mat.h"
#include <stdio.h>

void A(int mat[10][10]){

    int x;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            scanf("%d", &x);
            mat[i][j] = x;
        }
    }
}

int B(int mat[10][10]){
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);
    
    if(n == m){
        printf("False\n");
        return 0;
    }
    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(mat[i][j] != 0 && mat[i][k] != 0 && mat[k][j] != 0){
                    mat[i][j] = MIN(mat[i][j], (mat[i][k] + mat[k][j]));
                }
                else if(mat[i][k] != 0 && mat[k][j] != 0){
                    mat[i][j] = (mat[i][k] + mat[k][j]);
                }
            }
        }
    }


    if(mat[n][m]){
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}

int C(int mat[10][10]){
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);

    if(n == m){
        printf("%d\n", -1);
        return -1;
    }

    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(mat[i][j] != 0 && mat[i][k] != 0 && mat[k][j] != 0){
                    mat[i][j] = MIN(mat[i][j], (mat[i][k] + mat[k][j]));
                }
                else if(mat[i][k] != 0 && mat[k][j] != 0){
                    mat[i][j] = (mat[i][k] + mat[k][j]);
                }
            }
        }
    }
    if(mat[n][m]){
        printf("%d\n", mat[n][m]);
        return 1;
    }
    printf("%d\n", -1);
    return 0;
}

