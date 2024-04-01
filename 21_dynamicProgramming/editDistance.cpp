/* Problem Statement :: Given two strings str1 and str2 and below operations 
that can be performed on str1. Find minimum number of edits (operations) required
 to convert 'str1' into 'str2'.  
    1.Insert
    2.Remove
    3.Replace
*/
#include<iostream>
#include<vector>
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
//Space Optimized of DP Approach(Tabulation Solution) ->Time :O(m*n) and Space :O(2*m)
int eD_O(string s1,string s2){
    int m = s1.length();
    int n = s2.length();
    // Create a DP array to memoize result
    // of previous computations
    vector<vector<int>> dp(2,vector<int>(m+1,0));

    for(int j=0;j<=m;j++)
        dp[0][j] = j;
    
    // Start filling the DP ::
    // This loop run for every character in second string
    for(int i=1;i<=n;i++){
         //This loop compares the char from s2 with s1 
        for(int j=0;j<=m;j++){
            // if first string is empty then
            // we have to perform add character
            // operation to get second string
            if(j == 0){
                dp[i%2][j] = i;
            }
            // if character from both string
            // is same then we do not perform any
            // operation . here i % 2 is for bound
            // the row number.
            else if(s1[j-1] == s2[i-1]){
                dp[i%2][j] = dp[(i-1)%2][j-1];
            }
            // if character from both string is
            // not same then we take the minimum
            // from three specified operation
            else
                dp[i%2][j] = 1 + min(dp[(i-1)%2][j],min(dp[i%2][j-1],dp[(i-1)%2][j-1]));
        }
    }
    return dp[n%2][m];
}
//Memoization Approach ::
// Time complexity :O(m*n) & Auxiliary Space: O( m *n) + O(m+n)  
// (m*n) extra array space and  (m+n) recursive stack space.
int utility_ED(string s1,string s2,int m,int n,vector<vector<int>>& dp){
    if(m == 0) return n;
    if(n == 0) return m;

    if(dp[m][n] != -1)
        return dp[m][n];

    if(s1[m-1] == s2[n-1]){
        dp[m][n] = utility_ED(s1,s2,m-1,n-1,dp);
        return dp[m][n];
    }
    else{
        int insert = utility_ED(s1,s2,m,n-1,dp); //-> Insert operation
        int remove = utility_ED(s1,s2,m-1,n,dp); //-> Remove operation
        int replace = utility_ED(s1,s2,m-1,n-1,dp); //-> Replace operation 
        dp[m][n] = 1 + min(insert,min(remove,replace));
        return dp[m][n];
    }
}
int eD_M(string s1,string s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

    return utility_ED(s1,s2,m,n,dp);
}
int main(){
    string s1 = "CAT";
    string s2 = "CUT";
    int m = s1.length();
    int n = s2.length();

    cout<<"Minimum operation required to convert "<<s1<<" into "<<s2<<endl;;
    cout<<eD(s1,s2,m,n)<<endl;
    cout<<eD_T(s1,s2,m,n)<<endl;
    cout<<eD_O(s1,s2)<<endl;
    cout<<eD_M(s1,s2)<<endl;
    return 0;
}