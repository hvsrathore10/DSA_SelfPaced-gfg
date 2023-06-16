//Important : 
#include<iostream>
using namespace std;
//Naive Method : 
int sum(int *arr,int start,int end){
    int sumOfPages=0;
    for(int i=start;i<=end;i++){
        sumOfPages = sumOfPages + arr[i];
    }
    return sumOfPages;
}
int minPage(int *arr,int n,int k){
    if(k==1)
        return sum(arr,0,n-1);
    if(n==1)
        return arr[0];
    int res = INT_MAX;
    for(int i=1;i<n;i++){
        res = min(res,max(minPage(arr,i,k-1),sum(arr,i,n-1)));
    }
    return res;
}
//Efficient method (Binary Search) :- Time Complexity: O(N*log(N))
bool isFeasible(int *arr,int n,int k,int ans){
    int sum=0,req_student=1;
    for(int i=0;i<n;i++){
        if(sum+arr[i]>ans){
            req_student++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    return (req_student<=k);
}
int minPages(int *arr,int n,int k){
    int sum = 0,max_num=INT_MIN;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
        max_num = max(max_num,arr[i]);
    }
    int low = max_num,high = sum,res=0;
    while(low<=high){
        int mid = (low+high)/2;
        if(isFeasible(arr,n,k,mid)){
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}
int main(){
    int arr[] = {10,20,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<"Minimum Number of Pages : "<<minPage(arr,n,k)<<endl;
    cout<<"Minimum Number of Pages : "<<minPages(arr,n,k)<<endl;
    return 0;
}