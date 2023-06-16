#include<iostream>
using namespace std;
//Naive Method :- *Time cmplexity :O(n)
int getIndexNaive(int *arr,int n,int X){
    for(int i=0;i<n;i++){
        if(arr[i] == X){
            return i;
        }
    }
    return -1;
}
//Efficient Methid :- *Time complexity :O(log(n))
int getIndexR(int *arr,int l,int h,int X){
    if(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid] == X){
            if(mid==0 || arr[mid-1]!=X){
                return mid;
            }
            else{
                return getIndexR(arr,0,mid-1,X);
            }
        }
        else if(arr[mid]>X)
            return getIndexR(arr,l,mid-1,X);
        else
            return getIndexR(arr,mid+1,h,X);
    }
    return -1;
}
int getIndexI(int *arr,int n,int X){
    int l=0,h=n-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid]==X){
            if(mid==0 || arr[mid-1]!=X){
                return mid;
            }
            else{
                h = mid - 1; 
            }
        }
        else if(arr[mid]>X)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main(){
    int arr[] = {20,20,20,20,20,20,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X;
    cout<<"Enter the number : ";
    cin>>X;
    cout<<"Index of X is : "<<getIndexNaive(arr,n,X)<<endl;
    cout<<"Index of X is : "<<getIndexR(arr,0,n-1,X)<<endl;
    cout<<"Index of X is : "<<getIndexI(arr,n,X)<<endl;
    return 0;
}