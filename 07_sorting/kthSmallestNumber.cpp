// Discription : Given an array and a number k where k is smaller than the size of the array, we need to 
// find the k'th smallest element in the given array. It is given that all array elements are distinct.

#include<iostream>
using namespace std;
//Naive method : Time complexity : O(n.logn)
int kthSmallestNum1(int arr[],int n,int k){
    sort(arr,arr+n);
    return arr[k-1];
}
//Efficient Method : Time complexity : O(n)
int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
int kthSmallestNum2(int arr[],int n,int k){
    int low = 0, high = n-1;
    while(low<=high){
        int p = partition(arr,low,high);
        if(p==k-1)
            return arr[p];
        else if(p>k-1)
            high = p-1;
        else
            low = p+1;
    }
    return -1;
}
int main(){
    int arr[] = {25,10,5,50,45,15,35};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"Enter value of k : ";
    cin>>k;
    cout<<k<<" smallest number in array :"<<kthSmallestNum1(arr,n,k)<<endl;
    cout<<k<<" smallest number in array :"<<kthSmallestNum2(arr,n,k)<<endl;
    return 0;
}