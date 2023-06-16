#include<iostream>
using namespace std;
//Iterative Method for BinarySearch :- *Time complexity :O(logn) *Auxiliary space :O(1) 
int binarySearchI(int *arr,int n,int X){
    int low = 0,high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;      //-->mid = (low + high)/2 *it may create error for larger values of low and high
        if(arr[mid] == X){
            return mid;
        }
        else if(arr[mid]>X){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
} 
//Recursive Method for BinarySearch :- *Time complexity :O(log(n)) *Auxiliary space :O(log(n)) 
int binarySearchR(int *arr,int low,int high,int X){
    if(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == X){
            return mid;
        }
        if(arr[mid]>X){
            return binarySearchR(arr,low,mid-1,X);
        }
        else{
            return binarySearchR(arr,mid+1,high,X);
        }
    }
    return -1;
}
int main(){
    int arr[] = {10,15,20,30,35,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X;
    cout<<"Enter a number : ";
    cin>>X;
    cout<<X<<" is present at index : "<<binarySearchI(arr,n,X)<<endl;
    cout<<X<<" is present at index : "<<binarySearchR(arr,0,n-1,X)<<endl;
    return 0;
}
