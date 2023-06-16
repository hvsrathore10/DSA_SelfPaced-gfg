#include<iostream>
using namespace std;
//Time complexity : O(㏒n)
void maxheapify(int arr[],int n,int i){
    int largest = i,left = 2*i+1,right = 2*i+2;
    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    
    if(largest!=i){
        swap(arr[i],arr[largest]);
        maxheapify(arr,n,largest);
    }
}
// Time complexity : O(n)
void buildMaxHeap(int arr[],int n){
    for(int i=(n-2)/2;i>=0;i--){
        maxheapify(arr,n,i);
    }
}
//Time : O(n.㏒n)
void heapSort(int arr[],int n){
    buildMaxHeap(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        maxheapify(arr,i,0);
    }
}

int main(){
    int arr[] = {50,60,70,10,20,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before CycleSort : "<<endl;
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    cout<<"Array After CycleSort : "<<endl;
    heapSort(arr,n);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}

