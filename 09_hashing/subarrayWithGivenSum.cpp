//Description : Given a array which may contain positive,negative or zero in any order and a sum.Your 
// tack is to find a subarray whoes sum is equal to the given sum.
#include<iostream>
#include<unordered_set>
using namespace std;
 
// Naive Approach :- Time complexity : O(n²)
bool findSubarrayNaive(int arr[],int n,int sum){
    for(int i=0;i<n;i++){
        int curr_sum = 0;
        for(int j=i;j<n;j++){
            curr_sum += arr[j];
            if(curr_sum == sum)
                return true;
        }
    }
    return false;
}
//Efficient Approach :- Time complexity :O(n) Auxiliary space :O(n) --->Using Hashing(unorderes_set)
bool findSubarray(int arr[],int n,int sum){
    unordered_set<int> h;
    int prefix_sum = 0;
    for(int i=0;i<n;i++){
        prefix_sum += arr[i];
        //if (prefix_sum - sum) is already present in hashTable 
        // ⇒ there is a subarray with sum equal to give 'sum'
        if(h.find(prefix_sum - sum) != h.end())
            return true;
        //If first element is equal to sum i.e.,subarray {arr[0]}
        if(prefix_sum == sum)
            return true;
        h.insert(prefix_sum);
    }
    return false;
}
//Efficient Approach :- Time complexity :O(n) Auxiliary space :O(1) --->Using window sliding technique
bool subarraySum(int arr[],int n,int sum){
    int s = 0,curr_sum = 0;
    for(int i=0;i<n;i++){
        curr_sum += arr[i];
        //if curr_sum become greater then give sum 
        while(curr_sum>sum){
            curr_sum -= arr[s];
            s++;
        }
        if(curr_sum == sum)
            return true;
    }
    return false;
}
int main(){
    int arr[] = {5,8,6,13,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int sum = 22;
    cout<<findSubarrayNaive(arr,n,sum)<<endl;
    cout<<findSubarray(arr,n,sum)<<endl;
    cout<<subarraySum(arr,n,sum)<<endl;
    return 0;
}