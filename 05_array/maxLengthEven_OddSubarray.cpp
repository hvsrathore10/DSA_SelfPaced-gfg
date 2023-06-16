#include<iostream>
using namespace std;
//Naive Method :- *Time complexity :O(n^2)
int maxLengthEONaive(int *arr,int n){
    int res = 1;
    for(int i=0;i<n;i++){
        int count = 1;
        for(int j=i+1;j<n;j++){
            if((arr[j-1]%2==0 && arr[j]%2!=0) || (arr[j-1]%2!=0 && arr[j]%2==0)){
                count++;
                res = max(res,count);
            }
            else
                break;
        }
    }
    return res;
}
 //Efficiant Method :- *Kadane Algorithm* --> Time complexity :O(n)
int maxLengthEO(int *arr,int n){
    int curr = 1,res = 1;
    for(int i=1;i<n;i++){
        if((arr[i-1]%2==0 && arr[i]%2!=0) || (arr[i-1]%2!=0 && arr[i]%2==0)){
            curr++;
            res = max(res,curr);
        }
        else{
            curr = 1;
        }
    }
    return res;
}
int main(){
    int arr[] = {5,10,20,6,3,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum lenght of Ever-Odd Subarray : "<<maxLengthEONaive(arr,n)<<endl;
    cout<<"Maximum lenght of Ever-Odd Subarray : "<<maxLengthEO(arr,n)<<endl;
    return 0;
}