#include "NumClass.h"
#include <math.h>

int recursivePalindrome(int x){
    if(x == 0){
        return 0;
    }
    int len = 0;
    int t = x;

    while(t != 0){
        t/=10;
        len++;
    }

    return((x%10) * pow(10.0,(double)(len-1)) + recursivePalindrome(x/10));
}

int isPalindrome(int x){
    if(x == recursivePalindrome(x)){
        return 1;
    }
    return 0;
}

int recursiveArmstrong(int x, int length){
    if( x == 0){
        return 0;
    }

    return(pow((double)(x%10),(double)length) +recursiveArmstrong(x/10,length));
}

int isArmstrong(int x){
    int len = 0;
    int t = x;

    while(t != 0){
        t/=10;
        len++;
    }

    if(x == recursiveArmstrong(x,len)){
        return 1;
    }
    return 0;
}
