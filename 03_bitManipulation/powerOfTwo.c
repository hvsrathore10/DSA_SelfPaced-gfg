#include<stdio.h>
//Naive method :- Time complexity : O(k)  k-->no. of bits
int isPowerOfTwo1(int n){
    if(n==0){
        return 0;
    }
    while(n!=1){
        if(n%2!=0){
            return 0;
        }
        n = n/2;
    }
    return 1;
}
//Efficiect Method :- Time complexity :O(1)   *if we assume bitwise operator take constant TIME
int isPowerOfTwo2(int n){
    if(n==0){
        return 0;
    }
    return ((n&(n-1))==0);   //or return (n && ((n&(n-1))==0));
}

int main()
{
    int n;
    printf("Enter a number : n--> ");
    scanf("%d",&n);

    printf("%s\n",(isPowerOfTwo1(n))? "true" : "false");
    printf("%s\n",(isPowerOfTwo2(n))? "true" : "false");
    return 0;
}