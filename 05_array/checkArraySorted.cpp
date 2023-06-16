#include<iostream>
using namespace std;
//Naive Metod :- Time Complexity :O(n^2)
bool isSorted(int *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                return false;
            }
        }
    }
    return true;
}
//Efficent Method :- Time complexity :O(n)
bool isArraySorted(int *arr,int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    int arr[] = {10,20,30,40,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<((isSorted(arr,n))? "True" : "False")<<endl;
    cout<<((isArraySorted(arr,n))? "True" : "False")<<endl;
    return 0;
}