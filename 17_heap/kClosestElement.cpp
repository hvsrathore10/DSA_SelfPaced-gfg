//Problem : Given a sorted array arr[] and a value X, find the k closest elements to X in arr[]. 
#include<iostream>
#include<queue>
using namespace std;

//Naive Method :- Time complexity :O(n*k)
void printClosest1(int arr[],int n,int k,int x){
    //used to check already visited elements
    bool visited[n];
    fill(visited,visited+n,false); //<--- O(n)

    for(int i=0;i<k;i++){
        int min_diff = INT_MAX;
        int min_diff_index;
        for(int j=0;j<n;j++){
            if(visited[j]==false && abs(arr[j]-x)<=min_diff){
                min_diff = abs(arr[j] - x);
                min_diff_index = j;
            }
        }
        cout<<arr[min_diff_index]<<" ";
        visited[min_diff_index] = true;
    }
    cout<<endl;
}
void printClosest2(int arr[],int n,int k,int x){
    //Using Max-Heap :- first = difference b/w X and element 
    //                  second = index of element 
    priority_queue< pair<int,int> > pq;
    
    //Push starting k element from array --> O(K.logK)
    for(int i=0;i<k;i++)
        pq.push(make_pair(abs(arr[i]-x),i));
    
    //check weather there is any element with less difference the top of binary heap 
    //if present pop topmost element from heap and push new element
    //else ignore it 
    for(int i=k;i<n;i++){
        if(abs(arr[i]-x) < pq.top().first){
            pq.pop();
            pq.push(make_pair(abs(arr[i]-x),i));
        }
    }

    while(!pq.empty()){
        cout<<arr[pq.top().second]<<" ";
        pq.pop();
    }
    cout<<endl;
}
int main(){
    int arr[] = {30,40,33,35,26,36,37};
    int n = sizeof(arr)/sizeof(arr[0]);

    int x = 38;
    int k = 3;
    
    printClosest1(arr,n,k,x);
    printClosest2(arr,n,k,x);

    return 0;
}