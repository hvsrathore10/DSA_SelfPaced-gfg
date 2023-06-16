#include<iostream>
using namespace std;
 
int search_rotated(int *arr,int n,int X){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==X){
            return mid;
        }
        //check which half is sorted
        if(arr[low]<arr[mid]){        //-->If left half is sorted 
            //check weather X lies in the range of low-to-mid
            if(arr[low]<=X && arr[mid]>X)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{    //-->If right half is sorted 
            ////check weather X lies in the range of mid-to-high
            if(arr[mid]<X && arr[high]>=X)
                low = mid - 1;
            else
                high = mid + 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {100,200,300,400,10,20,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X;
    cout<<"Enter a number : ";
    cin>>X;
    cout<<"Element is at index : "<<search_rotated(arr,n,X)<<endl;
    return 0;
}
