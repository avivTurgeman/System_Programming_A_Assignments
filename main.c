#include <stdio.h>
#include "NumClass.h"

int main(){
    int x,y,tempX,tempY;
    scanf("%d",&x);
    scanf("%d",&y);
    tempX = x;
    tempY = y;

    printf("The Armstrong numbers are:");
    while(tempX <= tempY){
        if(isArmstrong(tempX) == 1){
            printf(" %d", tempX);
        }
        tempX++;
    }
    tempX = x;

    printf("\nThe Palindromes are:");
    while(tempX <= tempY){
        if(isPalindrome(tempX) == 1){
            printf(" %d", tempX);
        }
        tempX++;
    }
    tempX = x;

    printf("\nThe Prime numbers are:");
    while(tempX <= tempY){
        if(isPrime(tempX) == 1){
            printf(" %d", tempX);
        }
        tempX++;
    }
    tempX = x;
    
    printf("\nThe Strong numbers are:");
    while(tempX <= tempY){
        if(isStrong(tempX) == 1){
            printf(" %d", tempX);
        }
        tempX++;
    }
    printf("\n");
}
