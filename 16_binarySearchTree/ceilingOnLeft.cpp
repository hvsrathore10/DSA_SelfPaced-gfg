#include<iostream>
#include<set>
using namespace std;
 
//Naive Approach :- Time complexity :O(n²) and Auxiliary space :O(1)
void findCeiling(int arr[],int n){
    cout<<-1<<" ";
    for(int i=1;i<n;i++){
        int diff = INT_MAX;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i])
                diff = min(diff,arr[j]-arr[i]);
        }
        if(diff == INT_MAX)
            cout<<-1<<" ";
        else    
            cout<<diff+arr[i]<<" ";
    }
    cout<<endl;
}
//Efficient Approach :- Time complexity :O(n.㏒n) and Auxiliary space :O(n)
void printCeiling(int arr[],int n){
    cout<<-1<<" ";

    set<int> s;
    s.insert(arr[0]);
    for(int i=1;i<n;i++){
        set<int>::iterator it = s.lower_bound(arr[i]);
        if(it!=s.end())
            cout<<*(it)<<" ";
        else
            cout<<-1<<" ";
        s.insert(arr[i]);
    }
    cout<<endl;
}
int main(){
    int arr[] = {2,8,30,15,25,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    findCeiling(arr,n);
    printCeiling(arr,n);
    return 0;
}