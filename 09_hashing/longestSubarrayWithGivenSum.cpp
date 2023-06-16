#include<iostream>
#include<unordered_map>
using namespace std;
//Naive Approach :- Time complexity :ϴ(n²) Auxiliary space :O(1)
int maxLengNaive(int arr[],int n,int sum){
    int len = 0;
    for(int i=0;i<n;i++){
        int curr_sum = 0;
        for(int j=i;j<n;j++){
            curr_sum += arr[j];
            if(curr_sum == sum){
                len = max(len,(j-i + 1));
            }
        }
    }
    return len;
}
//Efficient Approach :- Time complexity :O(n)
int maxLeng(int arr[],int n,int sum){
    unordered_map<int,int> m;
    int prefix_sum = 0, len=0;
    for(int i=0;i<n;i++){
        prefix_sum += arr[i];
        if(prefix_sum == sum)
            len = i+1;
        if(m.find(prefix_sum) == m.end())
            m[prefix_sum] = i;

        if(m.find(prefix_sum-sum) != m.end())
            len = max(len,i-m[prefix_sum-sum]);
    }
    return len;
}
int main(){
    int arr[] = {3,1,0,1,8,2,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 5;
    cout<<"Lenght of longest subarray : "<<maxLeng(arr,n,sum)<<endl;    
    return 0;
}