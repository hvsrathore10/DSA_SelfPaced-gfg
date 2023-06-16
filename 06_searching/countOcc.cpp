#include<iostream>
using namespace std;
//Naive Approach is Using Linera Search Algo.(*Time :O(n))
// Efficient Method : Time complexity :O(logN)

//-->Find the index of first Occurrence of element(X) *Time :O(logN)*
int firstOcc(int *arr,int n,int X){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==X){
            if(mid==0 || arr[mid-1]!=X){
                return mid;
            }
            else{
                high = mid - 1; 
            }
        }
        else if(arr[mid]>X)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
//-->Find the index of last Occurrence of element(X) *Time :O(logN)*
int lastOcc(int *arr,int n,int X){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==X){
            if((mid==n-1) || arr[mid+1]!=X){
                return mid;
            }
            else{
                low = mid + 1;
            }
        }
        else if(arr[mid]>X)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
//Time complexity :- O(1) + O(logN) + O(logN) == O(logN)
int countOcc(int *arr,int n,int X){
    int first = firstOcc(arr,n,X);
    if(first==-1){
        return 0;
    }
    else{
        return (lastOcc(arr,n,X) - first + 1);
    }
}
int main(){
    int arr[] = {10,10,10,10,10,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X;
    cout<<"Enter a number : ";
    cin>>X;
    cout<<"Last_Index of X is : "<<countOcc(arr,n,X)<<endl;
    return 0;
}