/*This video discusses a famous interview problem in which you need to segregate an array of elements containing two types of elements. The types are:

1.Segregate negative and positive elements.
2.Segregate even and odd elements.
3.Sort a binary array.*/
#include<iostream>
using namespace std;
//Three Traverse Required for this method....
//Naive Method :- Time complexity : O(n) *Auxiliary Space :O(n)
void sortTwoTypeEle(int arr[],int n){
    int temp[n],i=0;
    for(int j=0;j<n;j++){
        if(arr[i]<0){
            temp[i] = arr[j];
            i++;
        } 
    }
    for(int j=0;j<n;j++){
        if(arr[j]>=0){
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++){
        arr[j] = temp[j];
    }
}
//Efficient Naive :- Time complexity : ϴ(n) *Auxiliary Space :O(1)
void sortTwoType(int arr[],int n){
    int i=-1;
    for(int j=0;j<n;j++){
        if(arr[j]<0){
            i++;
            swap(arr[i],arr[j]);
        }
    }
}
int main(){
    int arr[] = {15,-3,-2,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    // sortTwoTypeEle(arr,n);
    sortTwoType(arr,n);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}