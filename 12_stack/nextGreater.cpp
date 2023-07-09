#include<iostream>
#include<stack>
using namespace std;

//Naive Approach:- Time complexity:O(n²) & Auxiliary space :O(1)
void nextGreaterNaive(int *arr,int n){

    for(int i=0;i<n;i++){
        int j;
        for(j=i+1;j<n;j++){
            if(arr[j] > arr[i]){
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j == n)
            cout<<"-1 ";
    }cout<<endl;
}
//Efficent Approach :- Time complexity:ϴ(n) & Auxiliary space :O(n)
void nextGreater(int *arr,int n){
    stack<int> st;
    int res[n];
    st.push(arr[n-1]);
    res[n-1] = -1;
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i])
            st.pop();
        res[i] = st.empty()? -1 : st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
}
int main(){
    int arr[] = {5,15,10,8,6,12,9,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextGreater(arr,n);
    return 0;
}