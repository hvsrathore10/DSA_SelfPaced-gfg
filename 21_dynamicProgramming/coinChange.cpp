/* 
Problem Statement :: Given a value sum, if we want to make change for sum 
cents, and we have an infinite supply of each of coins[] = { coins1, coins2, 
.. , coinsn} valued coins, how many ways can we make the change? The order of 
coins doesn't matter.
*/
//This is NP_Hard type problem
#include<iostream>
using namespace std;
//Recursion Based Solution ::
int countWays(int coins[],int n,int sum){
    //base case : when ith is coin is part of solution
    // or user give sum as zero only
    if(sum == 0)
        return 1;
    //if ith coin lead the sum into negative
    if(sum < 0 || n==0)
        return 0;
    
    return (countWays(coins,n-1,sum) + countWays(coins,n,(sum - coins[n-1])));
}
//Dynamic Programming Based Solution :
// Tabulation Based Solution :
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
int main(){
    int coins[] = {1,6,2,4};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 8;

    cout<<countWays(coins,n,sum);
    cout<<countWays_T(coins,n,sum);
    return 0;
}