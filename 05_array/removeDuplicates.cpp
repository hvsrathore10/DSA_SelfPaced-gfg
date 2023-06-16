#include<iostream>
using namespace std;
//Naive Method 
// *Time complexity :O(n)
// *Auxiliary space :O(n)
int removeDuplicate(int *arr,int n){
    int temp[n];
    temp[0] = arr[0];
    int res = 1;
    for(int i=1;i<n;i++){
        if(temp[res-1] != arr[i]){
            temp[res] = arr[i];
            res++;
        }
    }
    for(int i=0;i<res;i++){
        arr[i] = temp[i];
    }
    return res;
} 
//Efficent Method 
// *Time complexity :O(n)
// *Auxiliary space :O(1)
int removeDuplicates(int *arr,int n){
    int res = 1;
    for(int i=1;i<n;i++){
        if(arr[res-1] != arr[i]){
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}
int main(){
    int arr[] = {10,20,20,30,30,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Array after removing Duplicates :"<<endl;
    n = removeDuplicates(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
