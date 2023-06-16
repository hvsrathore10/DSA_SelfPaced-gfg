#include<iostream>
#include<unordered_set>
using namespace std;
 
//Naive Approach : Time : O(n²) Auxiliary space : ϴ(1)
int countDistinct1(int arr[],int n){
    int res = 0;
    for(int i=0;i<n;i++){
        bool flag = false;
        int j = i-1;
        while(j>=0){
            if(arr[i]==arr[j]){
                flag = true;
                break;
            }
            --j;
        }
        if(!flag)
            res++;
    }
    return res;
}
//Efficient approach : Time : ϴ(n) Auxiliary space :O(n)
int countDistinct2(int arr[],int n){
    unordered_set<int> set;
    for(int i=0;i<n;i++)
        set.insert(arr[i]);
    
    return set.size();
}
//Improved Efficient method : Time : ϴ(n) Auxiliary space :O(n)
int countDistinct3(int arr[],int n){
    unordered_set<int> set(arr,arr+n);
    return set.size();
}
int main(){
    int arr[] = {15,12,13,14,12,13,13,13,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Number of distinct elements : "<<countDistinct1(arr,n)<<endl;
    cout<<"Number of distinct elements : "<<countDistinct2(arr,n)<<endl;
    cout<<"Number of distinct elements : "<<countDistinct3(arr,n)<<endl;
    return 0;
}


