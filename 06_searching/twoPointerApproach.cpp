#include<iostream>
using namespace std;
//Naive Method :*Time complexity :O(n^2)
bool checkForSumNaive(int *arr,int n,int X){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==X)
                return true;
        }
    }
    return false;
}
//Efficient Method :*Time complexity :O(n)--->BY TWO_POINTER APPROACH
bool checkForSum(int *arr,int n,int X){
    int i=0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==X){
            return true;
        }
        else if(arr[i]+arr[j]>X){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}                           //---->For unsorted array Hashing will be used
int main(){
    int arr[] = {2,5,8,12,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<(checkForSum(arr,n,17)? "True" : "False")<<endl;
    return 0;
}