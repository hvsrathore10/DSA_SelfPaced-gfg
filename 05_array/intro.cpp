#include<iostream>
#include<vector>
using namespace std;

int insertAtEnd(int *arr,int n,int key,int cap){
    if(n>cap){
        return n;
    }
    arr[n] = key;
    return n+1;
}
int insert(int *arr,int n,int key,int pos,int cap){
    if(n>cap){
        return n;
    }
    int idx = pos - 1;
    for(int i = n-1;i>=idx;i--){
        arr[i+1] = arr[i];
    }
    arr[idx] = key;
    return n+1;
}
int main(){
/*//Fixed Array
    int arr1[5];                  //---> Stack memory_allocation
    int arr2[] = {25,20,15,10,5}; //---> Stack memory_allocation
    int *arr3 = new int[5];       //---> Heap memory_allocation
*/   
/*//Dynamic Array 
    vector<int> vr1;
    vector<int> vr2(5);
*/
    int arr[10];
    int cap = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<5;i++){
        arr[i] = i+1;
    }
    int n = 5;
    n = insertAtEnd(arr,n,6,cap);
    cout<<"Array after insertion at the end : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    n = insert(arr,n,10,5,cap);
    cout<<"Array after insertion at position 5 : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}