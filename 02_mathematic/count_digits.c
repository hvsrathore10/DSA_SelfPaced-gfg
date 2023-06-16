#include<stdio.h>
//Time complexity : O(d)
int count_digit(long long n){
    //corner contition
    if(n==0){
        return 1;
    }
    int cnt=0;
    while(n!=0){
        cnt++;
        n = n/10;
    }
    return cnt;
}
int main()
{
    long long n; 
    printf("Enter a number : ");
    scanf("%lld",&n);
    int temp = count_digit(n);
    printf("%lld have : %d number of digits\n",n,temp);
    return 0;
}