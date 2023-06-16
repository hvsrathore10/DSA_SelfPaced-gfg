// #Longest Consecutive Sebsequence 
//Description : Given an array, we need to find the longest subsequence that has consecutive elements. 
// These consecutive elements may appear in any order in the subsequence.

#include<iostream>
#include<unordered_set>
using namespace std;
//Naive Approach(or sorting based approach) :- Time :O(n.㏒n)
int LCSNaive(int arr[],int n){
    int maxLen = 1,currLen=1;
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i] - arr[i-1] == 1)
            currLen++;
        else if(arr[i]!=arr[i-1]){
            maxLen = max(maxLen,currLen);
            currLen = 1;
        }
    }
    return maxLen;
}
//Efficient Approach :- *Time complexity :ϴ(n) *Auxiliary space :O(n)
int LCS(int arr[],int n){
    unordered_set<int> h(arr,arr+n);
    int maxLen=1;
    for(auto x : h){
        if(h.find(x-1) == h.end()){
            int curr = 1;
            while(h.find(x+curr)!=h.end())
                curr++;
            maxLen = max(maxLen,curr);
        }
    }
    return maxLen;
}
int main(){
    int arr[] = {9,3,4,2,20,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Lenght Longest Consecutive Subsequence : "<<LCSNaive(arr,n)<<endl;
    cout<<"Lenght Longest Consecutive Subsequence : "<<LCS(arr,n)<<endl;
    return 0;
}