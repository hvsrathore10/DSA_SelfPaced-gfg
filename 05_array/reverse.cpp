#include<iostream>
using namespace std;
//Time complexity : ϴ(n)
void reverseArray(int *arr,int n){
    int temp;
    int i=0,j=n-1;
    while(i<j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
int main(){
    int arr[] = {10,20,30,40,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Array Before Reverse function : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Array After Reverse function : "<<endl;
    reverseArray(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}