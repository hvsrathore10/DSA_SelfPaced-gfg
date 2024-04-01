/* 
Problem Statement :: Given a value sum, if we want to make change for sum 
cents, and we have an infinite supply of each of coins[] = { coins1, coins2, 
.. , coinsn} valued coins, how many ways can we make the change? The order of 
coins doesn't matter.
*/
//This is NP_Hard type problem


#include<iostream>
#include<vector>
using namespace std;
//Recursion Based Solution ::
//Time complexity :O(2^sum) and Space :O(1) 
int countWays(int coins[],int n,int sum){
    //base case : when ith is coin is part of solution
    // or user give sum as zero only
    if(sum == 0)
        return 1;
    //if ith coin lead the sum into negative 
    //(i.e. no solution exist) or zero no. of coins are present
    if(sum < 0 || n==0)
        return 0;
    
    return (countWays(coins,n-1,sum) + countWays(coins,n,(sum - coins[n-1])));
}

//Dynamic Programming Based Solution :
// Tabulation Based Solution : ->Time complexity :O(n*sum) & Space :O(n*sum)
int countWays_T(int coins[],int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=sum;j++)
            dp[i][j] = -1;
        
    //if sum == 0 then dp[i][j] = 1
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    //if sum > 0 && n == 0 then dp[i][j] = 0
    for(int j=1;j<=sum;j++)
        dp[0][j] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= coins[i-1])
                dp[i][j] += dp[i][j-coins[i-1]];
        }
    }
    return dp[n][sum];
}
//Optimization over DP solution
//Time complexity :O(n*sum) but space :O(sum)
int count(int coins[], int n, int sum){
    // table[i] will be storing the number of solutions for
    // value i. We need sum+1 rows as the table is constructed
    // in bottom up manner using the base case (sum = 0)
    int table[sum + 1];
  
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
  
    // Base case (If given sum is 0)
    table[0] = 1;
  
    // Pick all coins one by one and update the table[]
    // values after the index greater than or equal to the
    // value of the picked coin
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            table[j] += table[j - coins[i]];
    
    return table[sum];
}

//Memoization Based Solution :: Time complexity :O(n*sum) and Space :O(n*sum)
int utilityFun(int coins[],int n,int sum,vector<vector<int>>& dp){
    if(sum == 0)
        dp[n][sum] = 1;
    
    if(n==0)
        return 0;
    if(dp[n][sum] != -1)
        return dp[n][sum];
    else if(coins[n-1] <= sum){
        dp[n][sum] = utilityFun(coins,n,sum-coins[n-1],dp) + 
                        utilityFun(coins,n-1,sum,dp);
        return dp[n][sum];
    }
    else{
        dp[n][sum] = utilityFun(coins,n-1,sum,dp);
        return dp[n][sum];
    }
}
int countWays_M(int coins[],int n,int sum){
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    
    return utilityFun(coins,n,sum,dp);
}
int main(){
    int coins[] = {1,6,2,4};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 8;

    cout<<"Recursion : "<<countWays(coins,n,sum)<<endl;
    cout<<"Tabulation : "<<countWays_T(coins,n,sum)<<endl;
    cout<<"Memoization : "<<countWays_M(coins,n,sum)<<endl;
    return 0;
}