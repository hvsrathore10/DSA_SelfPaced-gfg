#include<iostream>
#include<deque>
using namespace std;

//Naive Approach :- Time complexity :O(n²) and Auxiliary space :O(1)
void printAllMax(int *arr,int n,int k){
    for(int i=0;i<=n-k;i++){
        int curr_max = INT_MIN;
        for(int j=i;j<i+k;j++){
            if(curr_max<arr[j])
                curr_max = arr[j];
        }
        cout<<curr_max<<" ";
    }
}

//Efficent Approach :- Time complexity :O(n) and Auxiliary space :O(n)--for deque
void maxInWindowOfSizeK(int *arr,int n,int k){
    //Create an empty DEQUE 
    deque<int> dq;
    
    //Run a loop and insert the first K elements in the deque. 
    for(int i=0;i<k;i++){
        // Before inserting the element, check if the element at the back of 
        // the queue is smaller than the current element, if it is so remove the 
        // element from the back of the deque until all elements left in the 
        // deque are greater than the current element. Then insert the current 
        // element, at the back of the deque.
        while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    // Now, run a loop from K to the end of the array.
    for(int i=k;i<n;i++){
        // Print the front element of the deque.
        cout<<arr[dq.front()]<<" ";
        // Insert the next element in the deque. Before inserting the element, 
        // check if the element at the back of the queue is smaller than the 
        // current element, if it is so remove the element from the back of the 
        // deque until all elements left in the deque are greater than the current 
        // element. Then insert the current element, at the back of the deque.
        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
        while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();
        
        // Print the maximum element of the last window.
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<endl;
}
int main(){
    int arr[] = {10,8,5,12,15,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // printAllMax(arr,n,3);
    maxInWindowOfSizeK(arr,n,3);
    return 0;
}