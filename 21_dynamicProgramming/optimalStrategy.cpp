/*
Problem Statement :-
Consider a row of n coins of values v1 . . . vn, where -n is even-. 
We play a game against an opponent by alternating turns. In each turn, a 
player selects either the first or last coin from the row, removes it from 
the row permanently, and receives the value of the coin. Determine the maximum 
possible amount of money we can definitely win if we move first.
Note: The opponent is as clever as the user.
*/

#include<iostream>
using namespace std;

//Recursive Approach 🥇:- Time complexity :O(2^n) & Space :O(1)
int optS(int arr[],int i,int j,int sum){
    if(i+1 == j)
        return max(arr[i],arr[j]);

    return max(sum - optS(arr,i+1,j,sum-arr[i]),
                sum - optS(arr,i,j-1,sum-arr[j]));
}
int optimalStrategy1(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];

    //DP Solution for this Recursive Approach become inefficient (space wise) 
    //when value for SUM is too large
    return optS(arr,0,n-1,sum);
}

//Recursive Approach 🥈:- Time complxity :O(2^n) & Space :O(1)
int optimalStr(int arr[],int i,int j){    
    if(i+1 == j)
        return max(arr[i],arr[j]);
    
    return max(arr[i] + min(optimalStr(arr,i+2,j),optimalStr(arr,i+1,j-1)),
                arr[j] + min(optimalStr(arr,i+1,j-1),optimalStr(arr,i,j-2)));
}

//Dynamic Programming Approach :- Time complexity :O(n²) and Space :O(n²)
int optimalStrategy_dp(int arr[],int n){
    int dp[n][n];
    //base case :
    for(int i=0;i<n-1;i++)
        dp[i][i+1] = max(arr[i],arr[i+1]);
    
    for(int gap=3;gap<n;gap+=2){
        for(int i=0;i+gap<n;i++){
            int j = i+gap;
            
            dp[i][j] = max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),
                            arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
        }
    }
    return dp[0][n-1];
}
int main(){
    int arr[] = {20,5,4,6,8,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Money you collect : "<<optimalStrategy1(arr,n)<<endl;
    cout<<"Money you collect : "<<optimalStr(arr,0,n-1)<<endl;
    cout<<"Money you collect : "<<optimalStrategy_dp(arr,n)<<endl;
    return 0;
}