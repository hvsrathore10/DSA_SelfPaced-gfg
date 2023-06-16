#include<iostream>
using namespace std;
//Method 1 :- Time : O(n*m) Auxiliary Space : ϴ(n+m)
void mergeTwoArray1(int a[],int n,int b[],int m){
    int temp[n+m];
    for(int i=0;i<n;i++)
        temp[i] = a[i];
    int k = n-1;
    for(int i=0;i<m;i++){
        if(b[i]>temp[k])
            temp[++k] = b[i];
        else{
            int j = k;
            while(j>=0 && temp[j]>b[i]){
                temp[j+1] = temp[j];
                j--;
            }
            temp[j+1] = b[i];
            k++;
        }
    }
    for(int x : temp)
        cout<<x<<" ";
    cout<<endl;
}
//Method 2 :- Time : ϴ(n+m) *Auxiliary Space : ϴ(n+m)
void mergeTwoArray2(int a[],int n,int b[],int m){
    int temp[n+m];
    int i,j,k;
    i=j=k=0;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            temp[k] = a[i];
            i++;
        }
        else{
            temp[k] = b[i];
            j++;
        }
        k++;
    }
    while(i<n){
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j<m){
        temp[k] = b[j];
        j++;
        k++;
    }
    for(int x : temp)
        cout<<x<<" ";
    cout<<endl;
}

//*Time Complexity :ϴ(n) *Auxiliary Space : ϴ(n)
void merge(int arr[],int low,int mid,int high){
    int n1 = mid-low+1, n2 = high-mid;
    int left[n1],right[n2];
    int i,j,k;
    for(i=0;i<n1;i++){
        left[i] = arr[low+i];
    }
    for(i=0;i<n2;i++){
        right[i] = arr[mid+i+1];
    }
    i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}
//*Time comlexity : ϴ(n.logn) *Auxiliary Space : ϴ(n)
void mergeSort(int *arr,int low,int high){ 
    if(low<high){
        int mid = low + (high-low)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    //Merge Two array : 
    /*int arr1[] = {10,20,30,50};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {5,15,25,35,45,55};
    int m = sizeof(arr2)/sizeof(arr2[0]);

    cout<<"Before mergeTwoArray : "<<endl;
    cout<<"Array 1 : "<<endl;
    for(int x : arr1)
        cout<<x<<" ";
    cout<<"\nArray 2 : "<<endl;
    for(int x : arr2)
        cout<<x<<" ";
    cout<<endl;  
    cout<<"After mergeTwoArray : "<<endl;
    mergeTwoArray1(arr1,n,arr2,m);
    */
    
    int arr[] = {5,50,10,30,65,4,70,16};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array : "<<endl;
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    cout<<"Sorted Array : "<<endl;
    mergeSort(arr,0,n-1);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}