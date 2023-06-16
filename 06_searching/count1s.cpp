#include<iostream>
using namespace std;
//It is the first approach came in mu my mind at first-look.
/*
//-->Find the index of first Occurrence of 1. *Time :O(logN)*
int firstOcc(bool *arr,int n,int X){
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
//-->Find the index of last Occurrence of 1. *Time :O(logN)*
int lastOcc(bool *arr,int n,int X){
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
//Time Complexity :O(1) + O(logN) == O(logN)
int getcount(bool *arr,int n){
    int first = firstOcc(arr,n,1);
    if(first==-1){
        return 0;
    }
    else{
        return (lastOcc(arr,n,1) - first + 1);
    }
}
*/
//Time complexity : O(logN)
int getcount(bool *arr,int n){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==0){
            low = mid + 1;
        }
        else{
            if(mid==0 || arr[mid-1]==0){
                return (n-mid);
            }
            else{
                high = mid - 1;
            }
        }
    }
    return 0;
}
int main(){
    bool arr[] = {0,0,0,0,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Number of 1's is array : "<<getcount(arr,n)<<endl;
    return 0;
}