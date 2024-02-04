/*Problem Statement ::
Given a value V, if we want to make a change for V cents, and we have an 
infinite supply of each of C = { C1, C2, .., Cm} valued coins, what is the 
minimum number of coins to make the change? If it's not possible to make a 
change, print -1.
*/
#include<iostream>
using namespace std;
 
// Recursion Solution :-Time complexity :O(2^(n*val)) and Auxiliary spcae :O(1)
int getMin(int coins[],int n,int val){
    if(val == 0)
        return 0;
    int res = INT_MAX;
    for(int i=0;i<n;i++){
        if(coins[i] <= val){
            int sub_res = getMin(coins,n,val - coins[i]);
            if(sub_res != INT_MAX)
                res = min(res,sub_res + 1);
        }
    }
    return res;
}
//Dynamic Programming Solution ::-
//Tabulation (Bottom-Up approach)=> Time complexity :O(n*val)
int getMin_T(int coins[],int n,int val){
    int dp[val + 1];
    for(int i=0;i<=val;i++)
        dp[i] = INT_MAX;
    
    dp[0] = 0;
    for(int i=1;i<=val;i++){
        for(int j=0;j<n;j++){
            if(coins[j] <= i){
                int sub_res = dp[i-coins[j]];
                if(sub_res != INT_MAX)
                    dp[i] = min(dp[i],sub_res + 1);
            }
        }
    }
    return dp[val];
}
int main(){
    int coins[] = {25,10,5};
    int n = sizeof(coins)/sizeof(coins[0]);
    int value = 30;

    cout<<"Minimum Coins required to generate value "<<value<<" is : ";
    int check_pos = getMin_T(coins,n,value);
    if(check_pos == INT_MAX)
        cout<<"-1 (Not possible)"<<endl;
    else    
        cout<<check_pos<<endl;

    return 0;
}