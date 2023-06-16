#include<iostream>
using namespace std;
//Naive Method :- Time Complexity :O(n*k)
int windowSlidingNaive(int *arr,int n,int k){
    int res = INT_MIN;
    for(int i=0;i<n-k;i++){
        int curr_max = 0;
        for(int j=i;j<i+k;j++){
            curr_max += arr[j];
        }
        res = max(res,curr_max);
    }
    return res;
}
//Efficient Method :- Time Complexity :O(n)
int windowSlidingSum(int *arr,int n,int k){
    int curr_sum = 0;
    for(int i=0;i<k;i++){
        curr_sum += arr[i];
    }
    int res = curr_sum;
    for(int i=k;i<n;i++){
        curr_sum = curr_sum + arr[i] - arr[i-k];
        res = max(res,curr_sum);
    }
    return res;
}
/*int WSMultiplication(int *arr,int n,int k){
    int curr_mult = 1;
    for(int i=0;i<k;i++){
        curr_mult *= arr[i];
    }
    int res = curr_mult;
    for(int i=k;i<n;i++){
        curr_mult = (curr_mult * arr[i])/arr[i-k];
        res = max(res,curr_mult);
    }
    return res;
}*/
/*int WSXOR(int *arr,int n,int k){
    int curr_xor = 0;
    for(int i=0;i<k;i++){
        curr_xor ^= arr[i];
    }
    int res = curr_xor;
    for(int i=k;i<n;i++){
        curr_xor = curr_xor^arr[i]^arr[i-k];
        res = max(res,curr_xor);
    }
    return res;
}*/
int main(){
    int arr[] = {1,8,30,-5,20,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<"Maximum possible Sum with subarray(Naive Method) : "<<windowSlidingNaive(arr,n,k)<<endl;
    cout<<"Maximum possible Sum with subarray : "<<windowSlidingSum(arr,n,k)<<endl;
    // cout<<"Maximum possible Multiplication with subarray : "<<WSMultiplication(arr,n,k)<<endl;
    // cout<<"Maximum possible XOR with subarray : "<<WSXOR(arr,n,k)<<endl;
    return 0;
}