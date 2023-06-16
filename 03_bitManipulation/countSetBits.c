#include<stdio.h>
//Naive Method :- Time Complexity :O(x)   x--> no. of teams/bits in b/w least_significant_bit(LSB) to most_significant_bit(MSB)
int countSetBits1(int n){
    int cnt=0;
    while(n!=0){
        //n%2!=0 and (n&1)!=0 work same but bitwise operator is much faster than mod(%) operator
        if((n&1) != 0){       
            cnt++;        //if condition can be replace by [cnt = cnt + (n&1)]
        }
        n = n>>1;
    }
    return cnt;
}
//Brian and Kerningham Algorithm :- Time complexity : O(y)    y--> no. of set bits
int countSetBits2(int n){
    int cnt=0;
    while(n!=0){
        n = n&(n-1);
        cnt++;
    }
    return cnt;
}
//Most Efficient Method :- Time complexity : O(1) [Lookup Table Solution]

int main()
{
    int n;
    printf("Enter a number : n--> ");
    scanf("%d",&n);
    printf("Set bits in %d integer : %d\n",n,countSetBits1(n));
    printf("Set bits in %d integer : %d\n",n,countSetBits2(n));
    return 0;
}