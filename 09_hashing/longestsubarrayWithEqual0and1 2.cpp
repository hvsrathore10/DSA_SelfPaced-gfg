// Given an array containing only 0s and 1s, find the largest subarray which contains equal no of 0s and 1s.
// The expected time complexity is O(n). 

#include<iostream>
#include<unordered_map>
using namespace std;

//Naive Approach :- Time complexity :ϴ(n²) Auxiliary Space :O(1)
int maxlenSubarray(int arr[],int n){
    int len = 0;
    for(int i=0;i<n;i++){
        int count0 = 0,count1 = 0;
        for(int j=i;j<n;j++){
            if(arr[j]==0)
                count0++;
            else
                count1++;
            //if count of 0's and 1's become equal check for lenght of subarray
            if(count0==count1)
                len = max(len,(j-i+1));
        }
    }
    return len;
}
//Efficient Approach :- Time complexity :O(n)
int longestSubarray(int arr[],int n){
    unordered_map<int,int> m;
    int len = 0,sum = 0;
    //replace all zero with -1
    for(int i=0;i<n;i++)
        if(arr[i]==0)
            arr[i] = -1;
    //apply the concept of longest subarray with given sum
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum == 0)
            len = i+1;
            
        if(m.find(sum+n) != m.end())
            len = max(len,(i-m[sum+n]));
        else
            m[sum+n] = i;
    }
    return len;
}
int main(){
    int arr[] = {0,0,1,1,1,1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of longest subarray with equal 0's and 1's : "<<maxlenSubarray(arr,n)<<endl;     
    cout<<"Length of longest subarray with equal 0's and 1's : "<<longestSubarray(arr,n)<<endl;     
    return 0;
}