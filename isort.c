#include<stdio.h>
#define ARRAY_LENGTH 50


int shift_element(int *arr, int i){
    int temp1 , temp2;
    temp1 = *(arr + 1);

    for(int j = 1; j <= i; j++){
        temp2 = *(arr + j+1);
        *(arr + j + 1) = temp1;
        temp1 = temp2;
    }
    return temp1;
}

void insertion_sort(int *arr, int len) {

    for(int i = 1; i < len; i++){
        int value = *(arr + i);
        int j = i - 1;

        while((j >= 0) && (*(arr + j) > value)){
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr +j +1) = value;
    }
}

int main(){

    int array[ARRAY_LENGTH];
    int num = 0;

    for(int i = 0; i < ARRAY_LENGTH; i++){
        scanf("%d", &num);

        *(array + i) = num;
    }

    insertion_sort(array, ARRAY_LENGTH);
    
    for(int i = 0; i < ARRAY_LENGTH - 1; i++){
        printf("%d,", *(array + i));
    }
    printf("%d\n", *(array + ARRAY_LENGTH - 1));

    return 0;
}
