//Description : An array is given which have price of stock of that day,we have to
// find span of the day.
//What is span? --> Span on a day is number of consecutive days include current day and days just 
// before which have the value equal or smaller.
#include<iostream>
#include<stack>
using namespace std;

//Naive Approach :- Time Complexity :O(n²) & Auxiliary space :O(1)
void findSpanNaive(int *arr,int n){
    for(int i=0;i<n;i++){
        int span = 1;
        for(int j=i-1;j>=0 && (arr[j] <= arr[i]);j--)
            span++;

        cout<<span<<" ";    
    }cout<<endl;
}
//Efficent Approach :- Time complexity :ϴ(n) & Auxiliary space :O(n)
void findSpan(int *arr,int n){
    stack<int> st;
    st.push(0);
    cout<<"1 ";
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        cout<<(st.empty()? i+1 : i-st.top())<<" ";
        st.push(i);
    }cout<<endl;
}
int main(){
    int arr[] = {30,20,25,28,27,29};
    int n = sizeof(arr)/sizeof(arr[0]);
    findSpan(arr,n);
    return 0;
}