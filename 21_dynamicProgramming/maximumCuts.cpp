/*Problem Statement : Given a rod of length L, the task is to cut the rod in 
such a way that the total number of segments of length a, b and c is maximized. 
The segments can only be of length a, b, and c. */
#include<iostream>
using namespace std;

//Recursion Solution :: Time complexity :O(3^L)
int maxCuts(int L,int a,int b,int c){
    //Corner case : 
    if(L < 0)
        return -1;
    //base case :
    if(L == 0)  
        return 0;
    
    int res = max(maxCuts(L-a,a,b,c),max(maxCuts(L-b,a,b,c),maxCuts(L-c,a,b,c)));

    if(res == -1)
        return res;
    else
        return res + 1;
}
//Dynamic Programming Solution :
int maxCuts_T(int L,int a,int b,int c){
    int dp[L+1];
    for(int i=0;i<=L;i++)
        dp[i] = -1;
    dp[0] = 0;

    for(int i=1;i<=L;i++){
        if(i-a >= 0) dp[i] = max(dp[i],dp[i-a]);
        if(i-b >= 0) dp[i] = max(dp[i],dp[i-b]);
        if(i-c >= 0) dp[i] = max(dp[i],dp[i-c]);

        if(dp[i] != -1)
            dp[i]++;
    }
    return dp[L];
}
int main(){
    int L = 5;
    int a = 1,b = 2,c = 3;
    printf("Maximum possible cuts of rod of lenght %d with [%d %d %d]\n",L,a,b,c);
    cout<<maxCuts(L,a,b,c);
    cout<<maxCuts_T(L,a,b,c);
    return 0;
}