#include "NumClass.h"
#include <math.h>
#include<stdio.h>

int isPalindrome(int x){
    int p = 0;
    for(int i =x; i!=0; i/=10){
        p*=10;
        p += i%10;
    } 

    if(x==p){
        return 1;
    }
    return 0;
}

int isArmstrong(int x){
    int t = x;
    double len = 0, sum = 0;

    while(t != 0){
        t/=10;
        len++;
    }
    t = x;

    while(t != 0){
        sum += pow((double)(t%10),len);
        t/=10;
    }
    
    if((int)sum == (int)x){
        return 1;
    }
    return 0;
}
