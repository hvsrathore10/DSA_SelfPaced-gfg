#include<iostream>
using namespace std;

//Utility Function for Palindrome Check ->Time complexity :O(n)
bool isPalindrome(string str,int i,int j){
    while(i<j){
        if(str[i]!=str[j])
            return false;
        
        i++;
        j--;
    }
    return true;
}

//Recursive Solution :- Time complexity :O(2^n) & Space :O(n) ->function call stack
int partition(string str,int i,int j){
    if(isPalindrome(str,i,j))
        return 0;
    
    int res = INT_MAX;
    for(int k=i;k<j;k++){
        res = min(res,1+partition(str,i,k)+partition(str,k+1,j));
    }
    return res;
}

//dynamic Programming Solution :- Time complexity :O(n³) & Space :O(n²)
int partitioning_DP(string str){
    int n = str.length();
    int cuts[n][n];

    //base case :
    for(int i=0;i<n;i++)
        cuts[i][i] = 0;

    for(int gap=1;gap<n;gap++){
        for(int i=0;i+gap<n;i++){
            int j = i + gap;
            if(isPalindrome(str,i,j))
                cuts[i][j] = 0;
            else{
                cuts[i][j] = INT_MAX;
                for(int k=i;k<j;k++)
                    cuts[i][j] = min(cuts[i][j],1+cuts[i][k]+cuts[k+1][j]);
            }
        }
    }
    return cuts[0][n-1];
} 

//Optimization :- Time complexity :O(n²) & Space :O(n²)
int partitioning_Opt(string str){
    int n = str.length();
    //cut[] -> store for for string with i length
    //palindrome[] -> store weather [i][j] is palindrome or not
    int cut[n]; 
    bool palindrome[n][n]; 
    memset(palindrome, false, sizeof(palindrome)); //default


    for (int i = 0; i < n; i++){ 
        int minCut = i;
        for (int j = 0; j <= i; j++){ 
            if (str[i] == str[j] && (i - j < 2 || palindrome[j + 1][i - 1])) { 
                palindrome[j][i] = true; 
                minCut = min(minCut, j == 0 ? 0 : (cut[j - 1] + 1)); 
            }
        }
        cut[i] = minCut; 
    }
    return cut[n - 1]; 
}
int main(){
    string str = "aaaaaa";
    int n = str.length();

    cout<<"Minimum Cut required for Palindrome Partitioning : "<<partition(str,0,n-1)<<endl;
    cout<<"Minimum Cut required for Palindrome Partitioning : "<<partitioning_DP(str)<<endl;
    cout<<"Minimum Cut required for Palindrome Partitioning : "<<partitioning_Opt(str)<<endl;
    return 0;
}