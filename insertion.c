#include "insertion.h"

int shift_element(int *arr, int i){
    int temp1 , temp2;
    temp1 = *(arr + 1);

    for(int j = 1; j <= i; j++){
        temp2 = *(arr + j+1);
        &(arr + j+1) = temp1;
        temp1 = temp2;
    }
    return temp1;
}

void insertion_sort(int *arr, int len){
    
}