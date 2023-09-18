//Problem : We have give an array which is k-sorted array.Target is to sort the array
// K-sorted array means it is nearly sorted i.e., An element at index i will be present in b/w i-k to i+k in sorted array.
#include<iostream>
#include<queue>
using namespace std;
 
void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
//Time complexity :O(N.㏒K) and Auxiliary space :O(K)
void sortArray(int arr[],int n,int k){ 
    priority_queue< int,vector<int>,greater<int> > pq(arr,arr+k+1);

    int index = 0;
    for(int i=k+1;i<n;i++){
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(pq.empty()==false){
        arr[index++] = pq.top();
        pq.pop();
    }
}
int main(){
    int arr[] = {10,9,7,8,4,70,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout<<"Before Sort : ";
    printArray(arr,n);
    //Naive Approach :-Time complexity :O(N.㏒N)
    // sort(arr,arr+n);

    sortArray(arr,n,k);

    cout<<"After sorting : ";
    printArray(arr,n);
    return 0;
}