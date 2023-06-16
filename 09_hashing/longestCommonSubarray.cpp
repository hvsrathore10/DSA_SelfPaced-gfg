#include<iostream>
#include<unordered_map>
using namespace std;
//Naive Approach :- Time complexity :ϴ(n²)
int commonSub(int arr1[],int arr2[],int n){
    int len = 0;
    for(int i=0;i<n;i++){
        int sum1=0,sum2=0;
        for(int j=i;j<n;j++){
            sum1 += arr1[j];
            sum2 += arr2[j];
            if(sum1 == sum2)
                len = max(len,j-i+1);
        }
    }
    return len;
}
//Efficient Approach :- Time complexity :ϴ(n) Auxiliary space :ϴ(n)
int commonSubarray(int arr1[],int arr2[],int n){
    int temp[n];
    //time for this for-loop ϴ(n)
    for(int i=0;i<n;i++)
        temp[i] = arr1[i] - arr2[i];
    //here we use the same approach that we used in finding longest subarray with ZERO sum
    int len=0,sum = 0;
    unordered_map<int,int> mp;
    //Time :O(n)
    for(int i=0;i<n;i++){
        sum += temp[i];
        if(sum==0)
            len = i+1;
        if(mp.find(sum) != mp.end())
            len = max(len,(i-mp[sum]));
        else
            mp[sum] = i;
    }
    return len;
}
int main(){
    int arr1[] = {0,1,0,0,0,0};
    int arr2[] = {1,0,1,0,0,1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Lenght of longest comman subarray : "<<commonSub(arr1,arr2,n)<<endl;
    cout<<"Lenght of longest comman subarray : "<<commonSubarray(arr1,arr2,n)<<endl;
    return 0;
}