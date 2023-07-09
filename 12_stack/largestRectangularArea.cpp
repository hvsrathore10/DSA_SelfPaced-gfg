// Description : Find the largest rectangular area possible in a given histogram where the 
// largest rectangle can be made of a number of contiguous bars whose heights are given in 
// an array. For simplicity, assume that all bars have the same width and the width is 1 unit. 
#include<iostream>
#include<stack>
using namespace std;

// Main Idea : For every bar 'x', we calculate the area with 'x' as the smallest bar in the rectangle. 
// If we calculate the such area for every bar 'x' and find the maximum of all areas, our task is done. 

//Naive Solution :- Time complexity :O(n²) & Auxiliary space :O(1)
int getMaxArea1(int arr[],int n){
    int res = 0;
    for(int i=0;i<n;i++){
        int count = arr[i];
        //find left greater or equal bar
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i]) count += arr[i];
            else break;
        }
        //find right greater or equal bar
        for(int j=i+1;j<n;j++){
            if(arr[j]>=arr[i]) count += arr[i];
            else break;
        }
        res = max(res,count);
    }
    return res;
}
//Better Solution :- Time complexity :O(n) & Auxiliary space :O(n)
//=====>But required three traversal of array and use two auxiliary array(prev[] & next[])
int getMaxArea2(int arr[],int n){
    int res = 0;
    stack<int> st;

    //creating previour array
    int prev[n];
    st.push(0);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
        prev[i] = (st.empty()? -1 : st.top());
        st.push(i);
    }
    while(!st.empty())
        st.pop();

    //creating next array
    int next[n];
    st.push(n-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
        next[i] = (st.empty()? n : st.top());
        st.push(i);
    }

    for(int i=0;i<n;i++){
        int curr = arr[i];
        curr += (i-prev[i]-1)*arr[i];  
        curr += (next[i]-i-1)*arr[i];  
        res = max(res,curr);
    }
    return res;
}
//Efficient Solution :- Time complexity :O(n) and Auxiliary space :O(n) -->But with single stack only
int getMaxArea(int arr[],int n){
    int res = 0;
    stack<int> st;
    int curr,tp;
    st.push(0);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            tp = st.top();
            st.pop();
            curr = arr[tp]*(st.empty()? i : i-st.top()-1);
            res = max(res,curr);
        }
        st.push(i);
    }
    while(!st.empty()){
        tp = st.top();
        st.pop();
        curr = arr[tp]*(st.empty()? n : n-st.top()-1);
        res = max(res,curr);
    }
    return res;
}
int main(){
    int arr[] = {60,20,50,40,10,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Largest Rectangular Area : "<<getMaxArea1(arr,n)<<endl;
    cout<<"Largest Rectangular Area : "<<getMaxArea2(arr,n)<<endl;
    cout<<"Largest Rectangular Area : "<<getMaxArea(arr,n)<<endl;
    return 0;
}