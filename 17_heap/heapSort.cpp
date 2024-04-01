// Important Notes:
// 1.Heap sort is an in-place algorithm.
// 2.Its typical implementation is not stable, but can be made stable.

#include<iostream>
using namespace std;

//Time complexity :O(logN) and Auxiliary space :O(logN)
void heapify(int arr[],int size,int i){
    int largest = i;
    int lc = 2*i + 1;
    int rc = 2*i + 2;

    if(lc<size && arr[largest] < arr[lc])
        largest = lc;
    if(rc<size && arr[largest] < arr[rc])
        largest = rc;

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,size,largest);
    }
}
//Time complexity :O(N) and Auxiliary space :O(logN)
void buildHeap(int arr[],int n){
    if(n==0)
        return;
    for(int i = (n-2)/2;i>=0;i--){
        heapify(arr,n,i);
    }
}
//Time complexity :O(N.logN) and Auxiliary space :O(logN)
void heapSort(int arr[],int n){
    //build head :
    buildHeap(arr,n);

    int size = n;
    //Arrange array in sorted faction
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        size--;
        heapify(arr,size,0);
    }
}
int main(){
    int arr[] = {20,30,5,100,80,2,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before sort : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    heapSort(arr,n);
    cout<<"\nArray after heapSort() called : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

// Heap sort algorithm has limited use because Quicksort and Mergesort are better
// in practice.Nevertheless, the Heap data structure itself is enormously used.