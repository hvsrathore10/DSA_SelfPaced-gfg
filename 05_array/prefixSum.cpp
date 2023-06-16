//Important Interview Question : 
#include<iostream>
using namespace std;

int arr[] = {2,3,4,5,6,8,10};
int n = sizeof(arr)/sizeof(arr[0]);
//Naive Method :- Time Complexity :O(n) or ϴ(r-l+1)
int getSumNaive(int l,int r){
    int sum = 0;
    for(int i=l;i<=r;i++){
        sum += arr[i];
    }
    return sum;
}
// ***----------------------------------------***
int pSum[7];
void prefixSumArray(){
    pSum[0] = arr[0];
    for(int i=1;i<n;i++){
        pSum[i] = pSum[i-1] + arr[i];
    }
}
//Efficient Method :- Time complexity :O(1)
int getSum(int l,int r){
    if(l==0){
        return pSum[r];
    }
    return pSum[r] - pSum[l-1];
}
int main(){
    cout<<"Sum from index 1 to 5 : "<<getSumNaive(1,5)<<endl;
    prefixSumArray();
    cout<<"*Sum from index 1 to 5 : "<<getSum(1,5)<<endl;
    return 0;
}