#include<iostream>
using namespace std;
//Time Complexity :ϴ(n)
void freqCount(int *arr,int n){
    int freq = 1 , i=1;
    while(i<n){
        while(i<n && (arr[i] == arr[i-1])){
            freq++;
            i++;
        }
        cout<<"Frequency of "<<arr[i-1]<<" is : "<<freq<<endl;
        i++;
        freq = 1;
    }
    if(n==1 || (arr[n-1] != arr[n-2])){
        cout<<"Frequency of "<<arr[n-1]<<" is : "<<"1"<<endl;
    }
}
//                  or
void freq(int *arr,int n){
    int freq = 1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            freq++;
        }
        else{
            cout<<arr[i-1]<<" "<<freq<<endl;
            freq = 1;
        }
    }
    
    if(n==1 || (arr[n-1]!=arr[n-2])){
        cout<<arr[n-1]<<" 1"<<endl;
    }
    else{
        cout<<arr[n-1]<<" "<<freq<<endl;
    }
} 

int main(){
    int arr[] = {10,10,10,25,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    freqCount(arr,n);
    // freq(arr,n);
    return 0;
}