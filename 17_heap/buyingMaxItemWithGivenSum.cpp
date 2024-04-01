/*Problem: You are given a array of size n and a SUM,your task is to count maximum
number of element that can be taken such that there sum will be less than or equal
to given SUM.-->With out modify the array
*/
#include<iostream>
#include<queue>
using namespace std;

//Sorting Base Approach :- Time complexity :O(N.logN) and Auxiliary space :O(N)
int buyMaxItem(int arr[],int n,int SUM){
    vector<int> v(arr,arr+n);

    sort(v.begin(),v.end());
    int curr_sum = 0,count = 0;
    for(int i=0;i<v.size();i++){
        curr_sum += v[i];
        if(curr_sum<=SUM){
            count++;
        }
        else   
            break;
    }
    return count;
}
//Priority queue/Heap Base Approach :- Time complexity :O(count.logN) and Auxiliary space :O(N)
int buyMaxItem2(int arr[],int n,int SUM){
    priority_queue< int,vector<int>,greater<int> > pq(arr,arr+n);

    int curr_sum = 0,count = 0;
    while(!pq.empty()){
        curr_sum += pq.top();
        pq.pop();
        if(curr_sum<=SUM)
            count++;
        else 
            break;
    }
    return count;
}
int main(){
    int arr[] = {12,10,5,3,2,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int SUM = 10;

    cout<<"Number of Possible elements : "<<buyMaxItem(arr,n,SUM)<<endl;
    cout<<"Number of Possible elements : "<<buyMaxItem2(arr,n,SUM)<<endl;
    return 0;
}