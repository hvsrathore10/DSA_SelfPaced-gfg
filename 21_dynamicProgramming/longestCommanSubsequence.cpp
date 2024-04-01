#include<iostream>
#include<vector>
using namespace std;

//Recursion Solution:: Time complexity:O(2^n)
int lcs_R(string& s1,string& s2,int m,int n){
    //base case ::when length of atleast one string is zero
    if(m==0 || n==0)
        return 0;

    //if ith character of s1 & jth character of s2 match
    if(s1[m-1] == s2[n-1])
        return 1 + lcs_R(s1,s2,m-1,n-1);
    //if ith character of s1 & jth character of s2 donot match
    else
        return max(lcs_R(s1,s2,m-1,n),lcs_R(s1,s2,m,n-1));
}
//DP Solution ::
// Memoization Based -->Time complexity :O(m*n)
int utilityLCS(string& s1,string& s2,int m,int n,vector< vector<int> >& dp){
    //base case :when we already calculated the value for m & n
    if(dp[m][n] != -1)
        return dp[m][n];
    
    //base case ::when length of atleast one string is zero
    if(m==0 || n==0)
        return 0;

    //if ith character of s1 & jth character of s2 match
    if(s1[m-1] == s2[n-1])
        dp[m][n] = 1 + utilityLCS(s1,s2,m-1,n-1,dp);
    //if ith character of s1 & jth character of s2 donot match
    else
        dp[m][n] = max(utilityLCS(s1,s2,m-1,n,dp),utilityLCS(s1,s2,m,n-1,dp));
    
    return dp[m][n];
}
int lcs_M(string& s1,string& s2,int m,int n){
    vector< vector<int> > dp(m+1,vector<int>(n+1,-1));

    return utilityLCS(s1,s2,m,n,dp);
}
//Tabulation Approach :-Time complexity :O(m*n) and Space :O(m*n)
int lcs_T(string& s1,string& s2,int m,int n){
    vector< vector<int> > dp(m+1,vector<int>(n+1,-1));

    for(int i=0;i<=m;i++)
        dp[i][0] = 0;
    for(int j=0;j<=n;j++)
        dp[0][j] = 0;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main(){
    string s1 = "AXYZ";
    string s2 = "BAZ";
    int m = s1.length();
    int n = s2.length();

    cout<<"Length of Longest Comman Subsequence :: "<<lcs_R(s1,s2,m,n)<<endl;
    cout<<"Length of Longest Comman Subsequence :: "<<lcs_M(s1,s2,m,n)<<endl;
    cout<<"Length of Longest Comman Subsequence :: "<<lcs_T(s1,s2,m,n)<<endl;
    return 0;
}