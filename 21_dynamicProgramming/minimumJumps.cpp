/*
Problem Statement :Given an array arr[] where each element represents the max 
number of steps that can be made forward from that index. The task is to find 
the minimum number of jumps to reach the end of the array starting from index 0. 
If the end isn’t reachable, return -1.
*/
#include<iostream>
using namespace std;
//Recursion Solution ::Time complexity :O(2^n) and Auxiliary space :O(1)
int minJumps(int arr[],int n){
    if(n==1)
        return 0;

    int res = INT_MAX;
    for(int i=0;i<n-1;i++){
        if(arr[i]+i >= n-1){
            int sub_res = minJumps(arr,i+1);
            if(sub_res != INT_MAX)
                res = min(res,sub_res+1);
        }
    }
    return res;
}
//Dynmaic Programming Solution ::Time complexity :O(n) and Auxiliary space :O(n)
int minJumps_T(int arr[],int n){
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i] = INT_MAX;
    
    dp[0] = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]+j >= i){
                if(dp[j] != INT_MAX)
                    dp[i] = min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n-1];
}
//Time complexity :O(n) and Auxiliary space :O(1)
int minimumJumps(int arr[], int n){
    if(n<=1)
        return 0;
            
    if(arr[0] == 0)
        return -1;
        
    int currLongestDist = 0;
    int curr = 0;
    int jumps = 0;
    for(int i=0;i<n-1;i++){
        currLongestDist = max(currLongestDist,arr[i]+i);
        if(curr == i){
            curr = currLongestDist;
            jumps++;
        }
    }
    return (curr<n-1)? -1 : jumps;
}
int main(){
    int arr[] = {3,4,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Minimum jumbs required to reach end(n-1) index : ";
    int check_pos = minJumps_T(arr,n);
    if(check_pos == INT_MAX)
        cout<<" -1 (Not Possible)"<<endl;
    else
        cout<<check_pos<<endl;
    return 0;
}