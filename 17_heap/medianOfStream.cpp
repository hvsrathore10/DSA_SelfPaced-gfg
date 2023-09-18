#include<iostream>
#include<queue>
using namespace std;
 
//Naive Approach :- Time complexity :O(N²) and Auxiliary space :O(N)
void findMedianNaive(int arr[],int n){
    int temp[n];
    int size = 0;
    for(int i=0;i<n;i++){
        temp[i] = arr[i];
        size++;
        int j = i;
        while(j>0 && temp[j]<temp[j-1]){
            swap(temp[j],temp[j-1]);
            j--;
        }
        if(size%2!=0)
            cout<<(float)(temp[size/2])<<" ";
        else 
            cout<<(float)(temp[size/2]+temp[(size-1)/2])/2<<" ";   
    }
    cout<<endl;
}
//Efficient Approach :- Time complexity :O(N.logN) and Auxiliary space :O(N)
void findMedian(int arr[],int n){
    //Create maxheap to store half smallers number and
    //minheap to store half greater number
    priority_queue<int> s;
    priority_queue< int,vector<int>,greater<int> > g;

    s.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++){
        if(s.size()>g.size()){
            if(s.top()>arr[i]){
                g.push(s.top());
                s.pop();
                s.push(arr[i]);
            }
            else
                g.push(arr[i]);
            cout<<((float)(s.top()+g.top())/2)<<" ";
        }
        else{
            if(g.top()<arr[i]){
                g.push(arr[i]);
                s.push(g.top());
                g.pop();
            }
            else 
                s.push(arr[i]);
            cout<<s.top()<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int arr[] = {12,10,7,8,15,18,20,25,30};
    int n = sizeof(arr)/sizeof(arr[0]);

    findMedian(arr,n);
    findMedianNaive(arr,n);
    return 0;
}