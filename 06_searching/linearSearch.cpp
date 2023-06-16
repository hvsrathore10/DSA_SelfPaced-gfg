#include<iostream>
using namespace std;
//Time complexity : O(n) 
void linearSearch(int *arr,int n,int element){
    if(n==0){
        cout<<"Array is empty!!"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(arr[i] == element){
            cout<<element<<" is present at index : "<<i<<endl;
            return;
        }
    }
    cout<<element<<" is not present in array[]"<<endl;
}
int main(){
    int arr[] = {10,50,30,70,80,60,20,90,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int element;
    cout<<"Enter element to search : ";
    cin>>element;
    linearSearch(arr,n,element);
    return 0;
}