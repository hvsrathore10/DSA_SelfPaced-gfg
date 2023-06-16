#include<iostream>
using namespace std;
//Recursive Method for TernarySearch :- *Time complexity :O(log(n)) *Auxiliary space :O(log(n)) --->{LOG(base3)N}
int ternarySearch(int *arr,int l,int r,int X){
    if(l<=r){
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        
        if(arr[mid1]==X){    //if ele is at mid1
            return mid1;
        }
        if(arr[mid2]==X){   //if ele is at mid2
            return mid2;
        }

        if(arr[mid1]>X){   //if ele is present in first past of array
            return ternarySearch(arr,l,mid1-1,X);
        }
        else if(arr[mid2]<X){  //if ele is present in last past of array
            return ternarySearch(arr,mid2+1,r,X);
        }
        else{          //if ele is present in between mid1 and mid2 (i.e,in middel past of array)
            return ternarySearch(arr,mid1+1,mid2-1,X);
        }
    }
    return -1;
}
//Iterative Method for TernarySearch :- *Time complexity :O(logn) *Auxiliary space :O(1) 
int ternarySearchI(int *arr,int n,int X){
    int left = 0,right = n-1;
    while(left<=right){
        int mid1 = left + (right-left)/3;
        int mid2 = right - (right-left)/3;

        if(arr[mid1]==X){
            return mid1;
        }
        if(arr[mid2]==X){
            return mid2;
        }
        if(arr[mid1]>X){
            right = mid1 - 1;
        }
        else if(arr[mid2]<X){
            left = mid2 + 1;
        }
        else{
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X;
    cout<<"Enter a number : ";
    cin>>X;
    cout<<"Element is present at index : "<<ternarySearch(arr,0,n-1,X)<<endl;
    cout<<"Element is present at index : "<<ternarySearchI(arr,n,X)<<endl;
    return 0;
}