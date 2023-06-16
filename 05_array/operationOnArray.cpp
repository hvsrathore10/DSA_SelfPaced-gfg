#include<iostream>
using namespace std;

int insert(int *arr,int key,int pos,int n,int cap){
    if(n==cap){
        return n;
    }
    int index = pos - 1;
    for(int i=n-1;i>=index;i--){
        arr[i+1] = arr[i];
    }
    arr[index] = key;
    return n+1;
}
int search(int *arr,int n,int key){
    if(n==0){
        return -1;
    }
    for(int i=0;i<n;i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}
int del(int *arr,int n,int key){
    if(n==0){
        cout<<"Array is Empty!!"<<endl;
        return 0;
    }
    int i;
    for(i=0;i<n;i++){
        if(arr[i] == key){
            break;
        }
    }
    if(i==n){
        return n;
    }
    for(int j=i;j<n-1;j++){
        arr[j] = arr[j+1];
    }
    return n-1;
}
int main(){
    int arr[7];
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 5;
    arr[3] = 6;
    int cap = 7,n = 4;
    int x,pos;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nEnter value to be Insert : ";
    cin>>x;
    cout<<"Enter position : ";
    cin>>pos;
    n = insert(arr,x,pos,n,cap);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nEnter key to be Search : ";
    cin>>x;
    cout<<x<<" is present at index : "<<search(arr,n,x)<<endl;

    cout<<"Enter element to delete : ";
    cin>>x;
    n=del(arr,n,x);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}