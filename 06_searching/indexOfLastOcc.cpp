#include<iostream>
using namespace std;
//Iterative Solution : Time Complexity :O(logN) 
int getIndexI(int *arr,int n,int X){
    int l=0,h=n-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid]==X){
            if((mid==n-1) || arr[mid+1]!=X){
                return mid;
            }
            else{
                l = mid + 1;
            }
        }
        else if(arr[mid]>X)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
//Recursive Solution : Time Complexity :O(logN) 
int getIndexR(int *arr,int low,int high,int n,int X){

    if(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==X){
            if((mid==n-1) || arr[mid+1]!=X){
                return mid;
            }
            else{
                return getIndexR(arr,mid+1,high,n,X);
            }
        }
        else if(arr[mid]>X)
            return getIndexR(arr,low,mid-1,n,X);
        else
            return getIndexR(arr,mid+1,high,n,X);
    }
    return -1;
}
int main(){
    int arr[] = {10,10,10,10,10,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X;
    cout<<"Enter a number : ";
    cin>>X;
    cout<<"Last_Index of X is : "<<getIndexI(arr,n,X)<<endl;
    return 0;
}