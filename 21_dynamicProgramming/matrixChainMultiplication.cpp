/*Problem :Given the dimension of a sequence of matrices in an array arr[], 
where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to 
find the most efficient way to multiply these matrices together such that the 
total number of element multiplications is minimum.

Eg :    Input: arr[] = {40, 20, 30, 10, 30}
        Output: 26000 => { (A(BC))D }
*/
#include<iostream>
using namespace std;
 
//Recursive Approach :-Time complexity :O(2^n) & Space :O(1)
int matChain(int arr[],int i,int j){
    //base case :
    if(i+1 == j)
        return 0;

    int res = INT_MAX;
    for(int k=i+1;k<j;k++){
        res = min(res,matChain(arr,i,k)+
                    matChain(arr,k,j)+
                    arr[i]*arr[k]*arr[j]);
    }
    return res;
}

//Dynamic Programming :- Time complexity :O(n³) & Space :O(n²)
//Tabulation Based Approach (Bottom-Up manner)
int matChain_DP(int arr[],int n){
    int dp[n][n];
    //base case :
    for(int i=0;i<n-1;i++)
        dp[i][i+1] = 0;
    
    for(int gap=2;gap<n;gap++){
        for(int i=0;i+gap<n;i++){
            int j = i+gap;
            dp[i][j] = INT_MAX;
            //First Partition ::
            for(int k=i+1;k<j;k++)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
            
        }
    }
    return dp[0][n-1];
}
int main(){
    int arr[] = {40,20,30,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Minimum No. of integer multiplication : "<<matChain(arr,0,n-1)<<endl;
    cout<<"Minimum No. of integer multiplication : "<<matChain_DP(arr,n)<<endl;
    return 0;
}