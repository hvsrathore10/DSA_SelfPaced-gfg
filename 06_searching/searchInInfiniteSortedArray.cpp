#include<iostream>
using namespace std;
//Naive Method :O(pos) -->pos = position at which X is present or write position for to be present.
int getIndexNaive(int *arr,int X){
    int i = 0;
    while(true){
        if(arr[i]==X){
            return i;
        }
        if(arr[i]>X){
            return -1;
        }
        i++;
    }
    return -1;
}
//Efficient Method :O(Log(pos))
int binarySearch(int *arr,int low,int high,int X){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==X)
            return mid;
        else if(arr[mid]>X)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int getIndex(int *arr,int X){
    if(arr[0]==X){
        return 0;
    }
    int i=1;
    while(arr[i]<X){
        i = i*2;   //-->while make it a monotonically increasing function
    }
    if(arr[i]==X)
        return i;
    return binarySearch(arr,i/2+1,i-1,X);
}

//Find index of first 1 in infiniteSize array.
int firstOcc(int *arr,int low,int high);
int getIndexOfFirst1(int *arr);

int main(){
    int arr[1000] = {10,30,50,70,90,100,200,300};
    int X;
    cout<<"Enter a number : ";
    cin>>X;
    cout<<X<<" is present at index : "<<getIndexNaive(arr,X)<<endl;
    cout<<X<<" is present at index : "<<getIndex(arr,X)<<endl;
    
    //Find index of first 1 in infiniteSize array.
    // int arr[1000] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    // cout<<"First occurrance of 1 is at index : "<<getIndexOfFirst1(arr)<<endl;
    return 0;
}

int firstOcc(int *arr,int low,int high){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==0){
            low = mid + 1;
        }
        else{
            if(mid==0 || arr[mid-1]==0)
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int getIndexOfFirst1(int *arr){
    if(arr[0]==1)
        return 0;
    int i=1;
    while(true){
        if(arr[i]==1){
            return firstOcc(arr,i/2+1,i);
        }
        i = i*2;
    }
    return -1;
}
