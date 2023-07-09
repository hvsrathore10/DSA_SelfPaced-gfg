// Description : Given an array of distinct integers, find the closest (position wise) greater 
// on left of every element. If there is no greater element on left, then print -1.
#include<iostream>
#include<stack>
using namespace std;

//Naive Approach :- Time complexity:O(n²) & Auxiliary space :O(1)
void prevGreaterNaive(int *arr,int n){
    for(int i=0;i<n;i++){
        int j;
        for(j=i-1;j>=0;j--){
            if(arr[j] > arr[i]){
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j == -1)
            cout<<"-1 ";
    }
}
//Efficent Approach :- Time complexity:ϴ(n) & Auxiliary space :O(n)
void prevGreater(int *arr,int n){
    stack<int> st;
    //process first element 
    st.push(arr[0]);
    cout<<"-1 ";
    //check for rest of the elements
    for(int i=1;i<n;i++){
        while(!st.empty() && st.top()<=arr[i])
            st.pop();

        cout<<(st.empty()? -1 : st.top())<<" ";
        st.push(arr[i]);
    }cout<<endl;
}
int main(){
    int arr[] = {15,10,18,12,4,6,2,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    prevGreater(arr,n);
    return 0;
}