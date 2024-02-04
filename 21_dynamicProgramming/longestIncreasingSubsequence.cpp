/*
Problem Statement ::The Longest Increasing Subsequence (LIS) problem is to find 
the length of the longest subsequence of a given sequence such that all elements 
of the subsequence are sorted in increasing order. 
For example, the length of LIS for {3,4,2,8,10} is 4 and LIS is {3,4,8,10}.
*/
#include<iostream>
using namespace std;

//Recursion Based Solution ::
// Time complexity :O(2^n)
int utility_LIS(int arr[],int n,int* max_ref){
    //base case :
    if(n == 1)
        return 1;
    //res -> store number of smaller number present before n-1 index for nth number 
    //max_ending_here -> store maximum possible smaller number present before 
    // n-1 index for nth number
    int res,max_ending_here = 1;
    
    //count all smaller number before n-1 index 
    for(int i=1;i<n;i++){
        res = utility_LIS(arr,i,max_ref);
        if(arr[i-1] < arr[n-1] && res+1 > max_ending_here)
            max_ending_here = res + 1;
    }
    //max_ref -> store count of LIS size (globle solution)
    if(*max_ref < max_ending_here)
        *max_ref = max_ending_here;
    
    return max_ending_here;
}
int lis(int arr[],int n){
    int max = 1;
    
    utility_LIS(arr,n,&max);
    return max;
}
//Dynamic Programming Based Solution -> Tabulation (Bottom-Up Approach)
//Time complexity :ϴ(n²) and Auxiliary space :ϴ(n)
int LIS(int arr[],int n){
    //lis[] -> store possible LIS at every index
    int lis[n];
    //base case :
    lis[0] = 1;
    
    //outer loop -> count all smaller number present before ith index
    for(int i=1;i<n;i++){
        lis[i] = 1;
        //inner loop -> check weather jth index number is smaller than ith number
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i])
                lis[i] = max(lis[i],lis[j]+1);
        }
    }
    int res = lis[0];
    for(int i=0;i<n;i++)
        res = max(res,lis[i]);
    
    return res;
}

//Binary Search Approach :: (Best possible solution)
//Time complexity :O(n.㏒n) and Auxiliary space :O(n)
int ceiling(vector<int> tail,int l,int r,int X){
    while(r > l){
        int m = l + (r-l)/2;
        if(tail[m] >= X)
            r = m;
        else
            l = m+1;
    }
    return r;
}
int LIS_O(int arr[],int n){
    vector<int> tail;
    int len = 1;
    tail.push_back(arr[0]);

    for(int i=1;i<n;i++){
        if(arr[i] > tail[len - 1]){
            tail.push_back(arr[i]);
            len++;
        }
        else{
            int c = ceiling(tail,0,len-1,arr[i]);
            tail[c] = arr[i];
        }
    }
    return len;
}

int main(){
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Longest Increasing Subsequence possible for array : {";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"} is : "<<lis(arr,n)<<endl;
    cout<<"(DP algorithm result) : "<<LIS(arr,n)<<endl;
    cout<<"(Optimal Solution) : "<<LIS_O(arr,n)<<endl;
    return 0;
}