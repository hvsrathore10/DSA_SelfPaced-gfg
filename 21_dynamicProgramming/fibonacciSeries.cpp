#include<iostream>
using namespace std;
//Recursion Based Solution :: 
//Time complexity :O(2^n) and Auxiliary space :O(1)
int fib_R(int n){
    if(n==0 || n==1)
        return n;
    return fib_R(n-1) + fib_R(n-2);
}
//Dynamic Programming Solution ::
//Memoization Based Solution(Top-Down Approach)::Time complexity :O(n) and Auxiliary space :O(n)
int utilityFib(int n,int memo[]){
    if(memo[n] == -1){
        if(n==0 || n==1)
            memo[n] = n;
        else    
            memo[n] = utilityFib(n-1,memo) + utilityFib(n-2,memo);
    }
    return memo[n];
}
int fib_M(int n){
    int memo[n+1];
    for(int i=0;i<=n;i++)
        memo[i] = -1;
    
    return utilityFib(n,memo);
}
//Tabulation Based Solution(Bottom-Up Approach)::Time complexity :O(n) and Auxiliary space :O(n)
int fib_T(int n){
    int memo[n+1];
    memo[0] = 0;
    memo[1] = 1;
    for(int i=2;i<=n;i++)
        memo[i] = memo[i-1] + memo[i-2];
    
    return memo[n];
}
int main(){
    int n = 10;
    cout<<"nth fibonacci number(Recursion_Solution) : "<<fib_R(n)<<endl;
    cout<<"nth fibonacci number(Memoization_Solution) : "<<fib_M(n)<<endl;
    cout<<"nth fibonacci number(Memoization_Solution) : "<<fib_T(n)<<endl;
    return 0;
}