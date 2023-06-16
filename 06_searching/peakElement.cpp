// Peak element : An element is said peak element if it is not smaller than its neighbors. 
#include<iostream>
using namespace std;
//Naive Approach : Time complexity : O(N)
int getPeakEleNaive(int *arr,int n){
    if(n==1)
        return arr[0];
    if(arr[0]>=arr[1]){
        return arr[0];
    }
    if(arr[n-1]>=arr[n-2]){
        return arr[n-1];
    }
    for(int i=1;i<n-1;i++){
        if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1])
            return arr[i];
    }
    return -1;
}
//EfficientApproach : Time complexity : O(logN)
int getPeakEle(int *arr,int n){
    int low=0,high=n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid])){
            return arr[mid];
        }
        else if(arr[mid-1]>=arr[mid]){  //-->if element if left is greater than mid than for sure there will be a peak element is left-half of array.
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {5,10,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Peak element : "<<getPeakEleNaive(arr,n)<<endl;
    cout<<"Peak element : "<<getPeakEle(arr,n)<<endl;
    return 0;
}

//Note : It is clear from the above examples that there is always a peak element in the input array.