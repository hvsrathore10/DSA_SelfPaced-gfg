/* Problem Statement :: Given two strings str1 and str2 and below operations 
that can be performed on str1. Find minimum number of edits (operations) required
 to convert 'str1' into 'str2'.  
    1.Insert
    2.Remove
    3.Replace
*/
#include<iostream>
using namespace std;
//Recursion Based Solution :: Time complexity :O(3^m)
int eD(string s1,string s2,int m,int n){
    if(m == 0) return n;
    if(n == 0) return m;

    if(s1[m-1] == s2[n-1]){
        //NO Operation
        return eD(s1,s2,m-1,n-1);
    }
    else{
        //eD(m,n-1) -> Insert operation
        //eD(m-1,n) -> Remove operation
        //eD(m-1,n-1) -> Replace operation 
        return 1 + min(eD(s1,s2,m,n-1),min(eD(s1,s2,m-1,n),eD(s1,s2,m-1,n-1)));
    }
}
//Dynamic Programming :: -->Tabulation (Bottom-Up Approach) 
//Time complexity :O(m*n) and Auxiliary space :O(m*n)
int eD_T(string s1,string s2,int m,int n){
    vector< vector<int> > dp(m+1,vector<int>(n+1,-1));
    for(int i=0;i<=m;i++)
        dp[i][0] = i;
    for(int j=0;j<=n;j++)
        dp[0][j] = j;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            //NO Operation
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                //eD(m,n-1) -> Insert operation
                //eD(m-1,n) -> Remove operation
                //eD(m-1,n-1) -> Replace operation 
                dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
    }
    return dp[m][n];
}
int main(){
    string s1 = "CAT";
    string s2 = "CUT";
    int m = s1.length();
    int n = s2.length();

    cout<<"Minimum operation required to convert "<<s1<<" into "<<s2<<endl;;
    cout<<eD(s1,s2,m,n)<<endl;
    cout<<eD(s1,s2,m,n)<<endl;
    return 0;
}