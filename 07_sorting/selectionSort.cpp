/*Note : 
>Worst Case : ϴ(n²)
>Does less memory writer compared to QuickSort,mergeSort,insertionSort,etc.
 But cycleSort is optimal in terms of memory writing
>Basic idea for heapSort
>Not Stable 
>In-place
*/
#include<iostream>
using namespace std;
//*Time complexity : O(n²) *Auxiliary space : O(1)
void selectionSort(int *arr,int n){
    int idxMin;
    for(int i=0;i<n-1;i++){
        idxMin = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[idxMin])
                idxMin = j;
        }
        if(idxMin != i){
            swap(arr[i],arr[idxMin]);
        }
    }
}
int main(){
    int arr[] = {10,2,30,5,8,40,25,20,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    cout<<"Array Before Sorting :\n";
    for(int i : arr)
        cout<<i<<" ";
    cout<<endl; 
    cout<<"Array After Sorting :\n";
    selectionSort(arr,n);
    for(int i : arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
