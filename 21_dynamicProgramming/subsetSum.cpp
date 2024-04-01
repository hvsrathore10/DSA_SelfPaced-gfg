/*Problem : Given a set of non-negative integers, and a value sum, determine if
there is a subset of the given set with sum equal to given sum. */
#include<iostream>
using namespace std;

//Recursive Solution :- Time complexity :O(2^n) & Space :O(n) ->function call stack
int countSubset(int arr[],int n,int sum){
    if(n==0)
        return (sum==0)? 1:0;
    
    return countSubset(arr,n-1,sum) + countSubset(arr,n-1,sum-arr[n-1]);
}

//Dynamic Programming :- Time complexity :O(n.sum) & Space :O(n.sum) 
int countSubset_DP(int arr[],int n,int sum){
    int dp[n+1][sum+1];

    //base case:
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    for(int j=1;j<=sum;j++)
        dp[0][j] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<arr[i-1])
                dp[i][j] = dp[i-1][j];
            else    
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][sum];
}
int main(){
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 9;

    cout<<"No. of subset which have SUM = "<<sum<<" is : "
        <<countSubset(arr,n,sum)<<endl;
    cout<<"No. of subset which have SUM = "<<sum<<" is : "
        <<countSubset_DP(arr,n,sum)<<endl;
    return 0;
}

/*
i/p : arr[] = {3, 34, 4, 12, 5, 2} & sum = 9;
o/p : 2 =>{{3,4,2} , {4,5}}
❖The problem is in-fact NP-Complete (There is no known polynomial time solution 
for this problem).
*/