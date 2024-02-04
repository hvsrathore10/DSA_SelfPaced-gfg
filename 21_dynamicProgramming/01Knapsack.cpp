#include<iostream>
using namespace std;
//Recursion Solution ::Time complexity :O(2^n) and Space :O(1)
int knapsack(int val[],int wt[],int W,int n){
    //Base case ::
    if(n == 0 || W==0)
        return 0;

    if(wt[n-1] > W)
        return knapsack(val,wt,W,n-1);
    else
        return max(val[n-1] + knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1));

}
//Dynamic Programming Solution ::(Bottom-Up approach)
//Time complexity :O(W*n) and Space :O(W*n)
int knapsack_T(int val[],int wt[],int W,int n){
    int dp[n+1][W+1];
    //Base case ::
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int j=0;j<=W;j++)
        dp[0][j] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
        }
    }
    return dp[n][W];
}
//This is a NP_Hard problem type and time complexity is pseudo_polynomial ∵ if value of
// W>>>n than time complexity will be greater than exponential time
int main(){
    int val[] = {10,40,30,50};
    int wt[] = {5,4,6,3};
    int W = 10;

    cout<<knapsack(val,wt,W,4);
    cout<<knapsack_T(val,wt,W,4);

    return 0;
}