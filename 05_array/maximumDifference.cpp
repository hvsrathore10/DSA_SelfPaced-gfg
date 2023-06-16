#include<iostream>
using namespace std;
//Naive Mathod :- Time Complexity : O(n^2) 
int getMaxDiffNaive(int *arr,int n){
    int res = INT_MIN;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(res<(arr[j]-arr[i])){
                res = arr[j]-arr[i];
            }
        }
    }
    return res;
} 
//Efficient Mathod :- Time Complexity : ϴ(n)
int getMaxDiff(int *arr,int n){
    int res = INT_MIN;
    int minValue = arr[0];
    for(int j=1;j<n;j++){
        res = max(res,arr[j]-minValue);
        minValue = min(minValue,arr[j]);
    }
    return res;
}
int main(){
    int arr[] = {2,3,10,6,4,8,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum Difference : "<<getMaxDiffNaive(arr,n)<<endl;
    cout<<"Maximum Difference : "<<getMaxDiff(arr,n)<<endl;
    return 0;
}
