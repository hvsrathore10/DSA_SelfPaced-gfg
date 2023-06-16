//Important INTERVIEW Question ---->
//Equilibrium Point : A element is said to be equilibrim point if sum of element in lift side is equal to sum 
// of element in right side of the element.
#include<iostream>
using namespace std;
//Naive Method :- Time complexity :O(n^2)
bool isEquilibrium1(int *arr,int n){
    for(int i=0;i<n;i++){
        int l_sum = 0;
        for(int j=i-1;j>=0;j--){
            l_sum += arr[j]; 
        }
        int r_sum = 0;
        for(int j=i+1;j<n;j++){
            r_sum += arr[j];
        }
        if(l_sum == r_sum){
            return true;
        }
    }
    return false;
}
//Efficient Method : 
// -->Time Complexity :O(n) -->Auxiliary space :O(2n)
bool isEquilibrium2(int *arr,int n){
    int l_sum[n],r_sum[n];
    l_sum[0] = arr[0];
    for(int i=1;i<n;i++){
        l_sum[i] = l_sum[i-1] + arr[i];
    }
    r_sum[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        r_sum[i] = r_sum[i+1] + arr[i];
    }
    for(int i=0;i<n;i++){
        if(i==0 && r_sum[i]==0){
            return true;
        }
        else if(l_sum[i-1] == r_sum[i+1]){
            return true;
        }
        else if(i==n-1 && l_sum[i]==0){
            return true;
        }
    }
    return false;
}
// -->Time Complexity :O(n) -->Auxiliary space :O(1)
bool isEquilibrium3(int *arr,int n){
    int r_sum = 0;
    for(int i=0;i<n;i++){
        r_sum += arr[i];
    }
    int l_sum = 0;
    for(int i=0;i<n;i++){
        r_sum -= arr[i];
        if(l_sum == r_sum){
            return true;
        }
        l_sum += arr[i];
    }
    return false;
}
int main(){
    int arr[] = {4,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<(isEquilibrium1(arr,n)? "True" : "False")<<endl;
    cout<<(isEquilibrium2(arr,n)? "True" : "False")<<endl;
    cout<<(isEquilibrium3(arr,n)? "True" : "False")<<endl;
    return 0;
}