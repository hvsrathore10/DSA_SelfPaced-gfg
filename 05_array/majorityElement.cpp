//Majority Element : Majority element is an element that appears more than n/2 times in an array of size n.
#include<iostream>
using namespace std;
//Naive Method :- Time complexity :O(n^2)  
int getIndexOfMajorityElement1(int *arr,int n){
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > n/2){
            return i;
        }
    }
    return -1;    
}
//Efficient Method :- *Moore's Voting Algorithm* -->Time Complexity : O(n)
int getIndexOfMajorityElement(int *arr,int n){
    int res = 0,count = 1;
    for(int i=1;i<n;i++){           //Selectes the candidate 
        if(arr[res] == arr[i])
            count++;
        else
            count--;

        if(count == 0){
            res = i;
            count = 1;
        }
    }
    count = 0;
    for(int i=0;i<n;i++){           //Check weather the seleacted candidate is majority element or not
        if(arr[res] == arr[i]){
            count++;
        }
    }
    if(count <= n/2){
        return -1;
    }
    return res;
}
int main(){
    int arr[] = {6,7,8,8,6,6,7,6,6,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Index of Majority Element : "<<getIndexOfMajorityElement1(arr,n)<<endl;
    cout<<"Index of Majority Element : "<<getIndexOfMajorityElement(arr,n)<<endl;
    return 0;
}