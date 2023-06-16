//Inversion : A pair (arr[i],arr[j]) is said inversion if i<j and arr[i]>arr[j];
#include<iostream>
using namespace std;
//Naive method :- *Time : O(n²) and *Auxiliary space : O(1)
int countInversionNaive(int arr[],int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<" ";
                count++;
            }
        }
    }
    return count;
}
//Efficient Method :- *Time :O(n.logn) and *Auxiliary space : O(n)
int countAndMerge(int arr[],int low,int mid,int high){
    int n1=mid-low+1,n2=high-mid;
    int left[n1],right[n2];
    int i,j,k;
    for(i=0;i<n1;i++)
        left[i] = arr[low+i];
    for(i=0;i<n2;i++)
        right[i] = arr[mid+i+1];

    int res = 0;
    i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            arr[k++] = left[i++];
        else{
            arr[k++] = right[j++];
            res = res + (n1-i);
        }
    }
    while(i<n1)
        arr[k++] = left[i++];
        
    while(j<n2)
        arr[k++] = right[j++];
    return res;
}
int countInversion(int arr[],int low,int high){
    int res = 0;
    if(low<high){
        int mid = low + (high-low)/2;

        res += countInversion(arr,low,mid);
        res += countInversion(arr,mid+1,high);
        res += countAndMerge(arr,low,mid,high);
    }
    return res;
}
int main(){
    int arr[] = {1,20,6,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = countInversionNaive(arr,n);
    cout<<"\nNumber of inversion Present : "<<count<<endl;

    cout<<"\nNumber of inversion Present : "<<countInversion(arr,0,n-1)<<endl;
    return 0;
}