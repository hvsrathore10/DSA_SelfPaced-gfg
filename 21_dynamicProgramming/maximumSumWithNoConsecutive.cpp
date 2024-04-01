/*
Problem : Given an array arr[] of positive numbers, The task is to find the 
maximum sum of a subsequence such that no 2 numbers in the sequence should be 
adjacent in the array.
*/
#include<iostream>
using namespace std;
 
// Naive Recursion Solution :- Time complexity :O(2^n) & Space :O(n) ->function call Stack
int maxSum(int arr[],int n){
    //BASE CASE :
    if(n==1)
        return arr[0];
    else if(n==2)
        return max(arr[0],arr[1]);
    
    return max(maxSum(arr,n-1),maxSum(arr,n-2)+arr[n-1]);
}

// Dynamic Programming Solution :- Time complexity :O(n) & Space :O(n)
int maxSum_DP(int arr[],int n){
    int dp[n+1];

    //base case :
    dp[1] = arr[0];
    dp[2] = max(arr[0],arr[1]);

    for(int i=3;i<=n;i++)
        dp[i] = max(dp[i-1],dp[i-2]+arr[i-1]);
    
    return dp[n];
}
//Space Optimized Approach :- Time complexity :O(n) & Space :O(1)
int maxSum_DPO(int arr[],int n){
    int pre_pre,pre,res;
    pre_pre = arr[0];
    pre = max(arr[0],arr[1]);

    for(int i=3;i<=n;i++){
        res = max(pre,pre_pre + arr[i-1]);
        pre_pre = pre;
        pre = res;
    }
    return res;
}
int main(){
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Maximum Sum : "<<maxSum(arr,n)<<endl;
    cout<<"Maximum Sum : "<<maxSum_DP(arr,n)<<endl;
    cout<<"Maximum Sum : "<<maxSum_DPO(arr,n)<<endl;
    return 0;
}