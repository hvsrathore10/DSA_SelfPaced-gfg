/*Problem #1 : Range Sum Queries using Prefix Sum
Description : We are given an Array of n integers, We are given q queries having indices
    l and r . We have to find out sum between the given range of indices.
*/
/*#include<iostream>
using namespace std;

int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int n = sizeof(arr)/sizeof(arr[0]);

int prefixSum[10];
void setPrefixSum(){
    prefixSum[0] = arr[0];
    for(int i=1;i<n;i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
}

int getQueries(int l,int r){
    if(l==0){
        return prefixSum[r];
    }
    return prefixSum[r] - prefixSum[l-1];
}
int main(){
    int l,r;
    cout<<"Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nEnter left and right index respectively (0<=l < r <= 9) :"<<endl;
    cin>>l;
    cin>>r;
    setPrefixSum();
    cout<<"Sum of elements form index "<<l<<" to "<<r<<" : "<<getQueries(l,r)<<endl;
    return 0;
}*/

// Problem #2 : Equilibrium index of an array
/*#include<iostream>
using namespace std;
 
int checkEquilibrium(int *arr,int n){
    int l_sum=0,r_sum=0;
    for(int i=0;i<n;i++){
        r_sum += arr[i]; 
    }
    for(int i=0;i<n;i++){
        r_sum-=arr[i];
        if(l_sum == r_sum){
            return i;
        }
        l_sum+=arr[i];
    }
    return -1;
}
int main(){
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Equilibrium index of an array : "<<checkEquilibrium(arr,n)<<endl;
    return 0;
}*/

// Problem #3 : Merge two sorted Arrays
#include<iostream>
using namespace std;
 
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void mergeArrays(int *A,int *B,int n,int m){
    int arr[n+m];
    int i,j,k;
    i = j = k = 0;
    while(i<n && j<m){
        if(A[i]<B[j]){
            arr[k] = A[i];
            i++;
            k++;
        }
        else{
            arr[k] = B[j];
            j++;
            k++;
        }
    } 
    while(i<n){
        arr[k] = A[i];
        i++;
        k++;
    }
    while(j<m){
        arr[k] = B[j];
        j++;
        k++;
    }
    cout<<"Marged Array : "<<endl;
    printArray(arr,n+m);
} 
int main(){
    int arr1[] = {2,4,6,8,10};
    int arr2[] = {1,3,5,7,9,11};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Array1 : "<<endl;
    printArray(arr1,n);
    cout<<"Array2 : "<<endl;
    printArray(arr2,m);
    mergeArrays(arr1,arr2,n,m);
    return 0;
}