#include<iostream>
using namespace std;
//Naive Method : *Time Complexity : O(n^3)
bool isTripletNaive(int *arr,int n,int X){
    for(int i=0;i<n-2;i++){
        for(int j=i+1;i<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==X)
                    return true;
            }
        }
    }
    return false;
}
//Efficient Method : *Time Complexity : O(n²)
bool isPair(int *arr,int n,int X,int start_index){
    int i=start_index,j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==X)
            return true;
        else if(arr[i]+arr[j]>X)
            j--;
        else  
            i++;
    }
    return false;
}
bool isTriplet(int *arr,int n,int X){
    for(int i=0;i<n-2;i++){
        if(isPair(arr,n,X-arr[i],i+1))
            return true;
    }
    return false;
}
int main(){
    int arr[] = {2,3,5,6,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X = 20;
    cout<<(isTriplet(arr,n,X)? "True" : "False")<<endl;
    return 0;
}