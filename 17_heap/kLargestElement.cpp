#include<iostream>
#include<queue>
using namespace std;

//Using Max Heap :- Time complexity :O(N + K.㏒N) and Auxiliary space :O(N)
void printKLargest1(int arr[],int n,int k){
    priority_queue<int> pq(arr,arr+n);  //<-- O(n)

    for(int i=0;i<k;i++){  //<-- O(K.logN)
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}
 
//Using Min Heap :- Time complexity :O(K + (N-K).㏒K) and Auxiliary space :O(K)
void printKLargest2(int arr[],int n,int k){
    priority_queue< int,vector<int>,greater<int> > pq(arr,arr+k);  //<-- O(K)
    
    for(int i=k;i<n;i++){ //<-- O(N-K.logK)
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    //Height of Min Heap will *logK*
    while(pq.empty()==false){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}
int main(){
    int arr[] = {8,6,7,10,9,90,15,28,5};
    int n = sizeof(arr)/sizeof(arr[0]);
     
    int k = 5;
    cout<<"Array : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    //Naive Approach :- Time complexity :O(N㏒N)
    /*
    sort(arr,arr+n);
    cout<<k<<" largest element in Array : ";
    for(int i=k-1;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    */

    //Efficient Approach :- 
    //Using Max Heap
    printKLargest1(arr,n,k);
    //Using Min Heap
    printKLargest2(arr,n,k);

    return 0;
}