//Leader :-> An element is said to be a leader if all element in right of it are smaller than that element. 
#include<iostream>
using namespace std;
//Naive Mathod :- Time Complexity : O(n^2) 
void getLeaders(int *arr,int n){
    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=i+1;j<n;j++){
            if(arr[i]<=arr[j]){
                flag = false;
            }
        }
        if(flag){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
} 
//Efficient Mathod :- Time Complexity : ϴ(n)
void getLeader(int *arr,int n){
    int curr_lead = arr[n-1];
    cout<<curr_lead<<" ";
    //Right to left traversal of ARRAY
    for(int i=n-2;i>=0;i--){
        if(curr_lead<arr[i]){
            curr_lead = arr[i];
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
} //--->Drawback : print leaders in opposite direction.
int main(){
    int arr[] = {7,10,4,10,6,12,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    getLeaders(arr,n);
    getLeader(arr,n);
    return 0;
}