#include<stdio.h>
//recursion method == Time complexity :O(n) , Auxitiary space :O(n)
long long factorial1(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*factorial1(n-1);
}
//iterative method == Time complexity :O(n) , Auxitiary space :O(1)
long long factorial2(int n){
    if(n==0 || n==1){
        return 1;
    }
    long long res=1;
    for(int i=2;i<=n;i++){
        res = res*i;
    }
    return res;
}

//counting number trailing zeroes
//naive method :
int countzeroes(int n){
    long long fact = factorial1(n);
    int res=0;
    while(fact%10==0){
        ++res;
        fact = fact/10;
    }
    return res;
}
// efficiency method :
int countzero(int n){
    //Edge case
    if(n<0){
        return -1;
    }
    int res=0;
    for(int i=5;n/i>=1;i*=5){    //or for(int i=5;i<=n;i*=5)
        res = res + n/i;
    }
    return res;
}
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    printf("Factorial of %d is : %lld\n",n,factorial1(n));
    printf("Factorial of %d is : %lld\n",n,factorial2(n));
    printf("Number of TRAILING ZEROES is factorial of %d : %d\n",n,countzeroes(n));
    printf("Number of TRAILING ZEROES is factorial of %d : %d\n",n,countzero(n));
    return 0;
}