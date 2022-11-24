#include "NumClass.h"

int isPrime(int x){
    if(x == 1){
        return 1;
    }
    
    if(x == 0){
        return 0;
    }

    for(int i = 2; i < x; i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}

int isStrong(int x){
    int t = x;
    int sum = 0;
    while(t != 0){
        int tempSum = 1;
        for(int i = t%10; i >0; i--){
            tempSum *= i;
        }
        sum += tempSum;
        t/=10;
    }

    if(sum == x){
        return 1;
    }
    return 0;
}

