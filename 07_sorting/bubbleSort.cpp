#include<iostream>
using namespace std;
//Bubble Sort is Stable sorting algorithm
//*Time complexity : ϴ(n²) *Auxiliary space : ϴ(1)
void bubbleSort(int *arr,int n){
    //Due to isSorted Variable Time complexity : O(n²) and ϴ(n) if array is sorted.
    bool isSorted;                    
    for(int i=0;i<n-1;i++){          //-->It will count Phase.
        isSorted = true;
        for(int j=0;j<n-i-1;j++){   //-->It will compair elements of array.
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSorted = false;
            }
        }
        if(isSorted){
            return;
        }
    }
}
int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    cout<<"Array Before Sorting :\n";
    for(int i : arr)
        cout<<i<<" ";
    cout<<endl; 
    cout<<"Array After Sorting :\n";
    bubbleSort(arr,n);
    for(int i : arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}