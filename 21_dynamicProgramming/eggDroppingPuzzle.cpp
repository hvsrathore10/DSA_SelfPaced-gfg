/*
Problem Statement: You are given N identical eggs and you have access to a 
K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped from a floor 
higher than f will break, and any egg dropped from or below floor f will not 
break.

There are few rules given below : 
-An egg that survives a fall can be used again.
-A broken egg must be discarded.
-The effect of a fall is the same for all eggs.
-If the egg doesn't break at a certain floor, it will not break at any floor below.
-If the eggs breaks at a certain floor, it will break at any floor above.

Return the minimum number of moves that you need to determine with certainty what 
the value of f is.
*/
#include<iostream>
using namespace std;

//Naive Recursive Solution :-Time complexity:O(2^f²) 
int eggDrop(int f,int e){
    //base case's :: 
    if(f==1 || f==0)
        return f;
    if(e == 1)
        return f;
    
    int res = INT_MAX;
    for(int x = 1;x<=f;x++)
        res = min(res,max(eggDrop(x-1,e-1),eggDrop(f-x,e)));
    
    return res + 1;
}
//Dynamic Programming Solution :-Time complexity:O(f².e) & Space :O(f.e)
int eggDrop_DP(int f,int e){
    int dp[f+1][e+1];
    //Base case :
    //if(f=1 || f=0) dp[0|1][j] = 0|1
    for(int j=1;j<=e;j++){ 
        dp[0][j] = 0;
        dp[1][j] = 1;
    }
    // if(e==1) dp[i][1] = i;
    for(int i=1;i<=f;i++) 
        dp[i][1] = i;
    
    for(int i=2;i<=f;i++){
        for(int j=2;j<=e;j++){
            dp[i][j] = INT_MAX;
            for(int x=1;x<=i;x++)
                dp[i][j] = min(dp[i][j],1 + max(dp[x-1][j-1],dp[i-x][j]));
        }
    }
    return dp[f][e];
}
int main(){
    int f = 10; // f - no. of floor
    int e = 2; // e - no. of given eggs

    cout << "Minimum number of trials in worst case with "<< 
        e << " eggs and " << f << " floors is "<< eggDrop(f, e) << endl;
    cout << "Minimum number of trials in worst case with "<< 
        e << " eggs and " << f << " floors is "<< eggDrop_DP(f, e) << endl;
    return 0;
}