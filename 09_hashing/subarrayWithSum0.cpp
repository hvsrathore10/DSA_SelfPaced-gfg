//Problem Description : Give a array,we have to check is there any subarray which give sum = 0.
//arr[] = {4,-3,2,1} Subarray :{4},{4,-3},{4,-3,2},{4,-3,2,1},{-3},{-3,2},{-3,2,1},{2},{2,1},{1} 
#include<iostream>
#include<unordered_set>
using namespace std;
 
//Naive Method :O(n²)
bool checkSum0_(int arr[],int n){
    for(int i=0;i<n;i++){
        int curr_sum = 0;
        for(int j=i;j<n;j++){
            curr_sum += arr[j];
            if(curr_sum == 0)
                return true;
        }
    }
    return false;
}
//Efficient Approach : O(n)
bool checkSum0(int arr[],int n){
    int prefix_sum = 0;
    unordered_set<int> h;
    for(int i=0;i<n;i++){
        prefix_sum += arr[i];
        if(h.find(prefix_sum)!=h.end())
            return true;
        if(prefix_sum == 0)
            return true;
        h.insert(prefix_sum);
    }
    return false;
}
int main(){
    int arr[] = {4,-3,2,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%s \n",checkSum0(arr,n)? "True" : "False");
    return 0;
}