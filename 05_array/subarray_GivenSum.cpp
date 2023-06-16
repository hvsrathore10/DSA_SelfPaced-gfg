#include<iostream>
using namespace std;
//Naive Method :- Time complexity :O(n^2)
bool checkNaive(int *arr,int n,int sum){
    for(int i=0;i<n;i++){
        int curr_sum = 0;
        for(int j=i;j<n;j++){
            if(curr_sum == sum){
                return true;
            }
            curr_sum += arr[j];
        }
    }
    return false;
} 
//Efficient Method :- Time complexity :O(n)
bool check(int *arr,int n,int sum){
    int s = 0,curr_sum = 0;
    for(int e=0;e<n;e++){
        curr_sum += arr[e];
        while(curr_sum>sum){
            curr_sum -= arr[s];
            s++;
        }
        if(curr_sum == sum){
            return true;
        }
    }
    return false;
}
int main(){
    int arr[] = {2,4,20,3,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 33;
    cout<<(checkNaive(arr,n,sum)? "True" : "False")<<endl;
    cout<<(check(arr,n,sum)? "True" : "False")<<endl;
    return 0;
}