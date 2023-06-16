#include<iostream>
using namespace std;
//Naive Method :- Time complexity :O(n^2)
int getLargestNaive(int *arr,int n){
    if(n==0){
        return -1;
    }
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<n;j++){
            if(arr[j]>arr[i]){
                flag = false;
            }
        }
        if(flag){
            return i;
        }
    }
    return -1;
}
//Efficient Method :- Time complexity :ϴ(n)
int getLargest(int *arr,int n){
    int indexOfMax = 0;
    if(n==0){
        return -1;
    }
    for(int i=1;i<n;i++){
        if(arr[i]>arr[indexOfMax]){
            indexOfMax = i;
        }
    }
    return indexOfMax;
}
//Naive Approach :- Time complexity :O(n)  ==>for-loop will be rum two times
int getSecondLargest2(int *arr,int n){
    int iOL = getLargest(arr,n);
    int iOSL = -1;
    for(int i=0;i<n;i++){
        if(arr[i] != arr[iOL]){
            if(iOSL==-1){
                iOSL = i;
            }
            else if(arr[i]>arr[iOSL]){
                iOSL = i;
            }
        }
    }
    return iOSL;
}
//Efficient Approach :- Time complexity :O(n) ==>But only single loop will be run.
int getSecondLargest(int *arr,int n){
    int iOL=0;
    int iOSL=-1;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[iOL]){
            iOSL = iOL;
            iOL = i;
        }
        else if(arr[i]<arr[iOL]){
            if(iOSL == -1){
                iOSL = i;
            }
            else if(arr[i]>arr[iOSL]){
                iOSL = i;
            }
        }
    }
    return iOSL;
}
int main(){
    int arr[] = {10,50,30,80};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<"Largest Element is at INDEX : "<<getLargestNaive(arr,n)<<endl;
    cout<<"INDEX of Largest Element is : "<<getLargest(arr,n)<<endl;
    // cout<<"INDEX of Second Largest Element is : "<<getSecondLargest2(arr,n)<<endl;
    cout<<"INDEX of Second Largest Element is : "<<getSecondLargest(arr,n)<<endl;
    return 0;
}