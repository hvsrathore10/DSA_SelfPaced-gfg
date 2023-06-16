#include<iostream>
using namespace std;
//Naive Method :- Time complexity : O(n^2)
int maxSumCir(int *arr,int n){
    int res = arr[0];
    for(int i=0;i<n;i++){
        int curr_max = arr[i];
        int curr_sum = arr[i];
        for(int j=1;j<n;j++){
            int index = (i+j)%n;
            curr_sum += arr[index];
            curr_max = max(curr_max,curr_sum); 
        }
        res = max(res,curr_max);
    }
    return res;
}
int normalMaxSum(int *arr,int n){                  //--->Normal Kadane Algo.
    int res = arr[0];
    int maxEnding = arr[0];
    for(int i=1;i<n;i++){
        maxEnding = max(maxEnding+arr[i],arr[i]);
        res = max(res,maxEnding);
    }
    return res;
}
//Efficient Method :- Time Complexity :O(n)
int getMaxSumCir(int *arr,int n){
    int normal_MaxSum = normalMaxSum(arr,n);
    if(normal_MaxSum < 0){
        return normal_MaxSum;
    }
    int arr_sum = 0;
    for(int i=0;i<n;i++){
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int circuler_MaxSum = arr_sum + normalMaxSum(arr,n);
    return max(circuler_MaxSum,normal_MaxSum);
}
int main(){
    int arr[] = {8,-4,3,-5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum sum of circuler subarray : "<<maxSumCir(arr,n)<<endl;
    cout<<"Maximum sum of circuler subarray : "<<getMaxSumCir(arr,n)<<endl;
    return 0;
}