//Problem Statement :Given N, Find the total number of unique BSTs that can be 
//made using values from 1 to N. 
#include<iostream>
using namespace std;
 
//No. of unique BSTs = (1/n+1) * (2nCn)
//DP Solution :-Time complexity :O(n²) & Space complexity :O(n)
int countBST(int n){
    int dp[n+1];
    //base case :
    dp[0] = 1;

    for(int i=1;i<=n;i++){
        dp[i] = 0;
        for(int j=0;j<i;j++)
            dp[i] += dp[j]*dp[i-j-1];
    }
    return dp[n];
}
int main(){
    int n = 5;
    cout<<"No. of Unique BSTs : "<<countBST(n)<<endl;
    return 0;
}