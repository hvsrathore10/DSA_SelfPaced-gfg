#include<iostream>
using namespace std;
//Naive Method :- *Time Complexity :O(n^2) *Auxiliary space :O(1)
int maxSumNaive(int *arr,int n){
    int res = arr[0];
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=i;j<n;j++){
            count = count + arr[j];
            res = max(res,count);
        }
    }
    return res;
} 
//Efficient Method :- -->Kadane Algorithm<-- *Time Complexity :O(n) *Auxiliary space :O(1)
int maxSum(int *arr,int n){
    int res = arr[0];
    int maxEnding = arr[0];
    for(int i=1;i<n;i++){
        maxEnding = max(maxEnding+arr[i],arr[i]);
        res = max(res,maxEnding);
    }
    return res;
}
int main(){
    int arr[]={2,3,-8,7,-1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum Sum of Subarray : "<<maxSumNaive(arr,n)<<endl;
    cout<<"Maximum Sum of Subarray : "<<maxSum(arr,n)<<endl;
    return 0;
}