#include<iostream>
using namespace std;
//Naive method :- Time complexity :ϴ(n²)
int _minimumDiff(int arr[],int n){
    int res = INT_MAX;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            res = min(res,abs(arr[i]-arr[j]));
        }
    }
    return res;
}
//Efficient Method :- Time complexity : O(n.logn) 
int minimumDiff(int arr[],int n){
    sort(arr,arr+n);
    int res = INT_MAX;
    for(int i=1;i<n;i++){
        res = min(res,arr[i]-arr[i-1]);
    }
    return res;
}
int main(){
    int arr[] = {1, 19, -4, 31, 38, 25, 100};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Minimum Difference : "<<_minimumDiff(arr,n)<<endl;
    cout<<"Minimum Difference : "<<minimumDiff(arr,n)<<endl;
    return 0;
}