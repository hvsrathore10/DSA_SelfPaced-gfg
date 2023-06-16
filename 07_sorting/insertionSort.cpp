/* Note : 
1.O(n²) worst case
2.In-place and stable 
3.Used in practice for small array (TimSort and IntroSort)
4.ϴ(n) Best case 
5.Insertion sort is adaptive in nature, i.e. it is appropriate for data sets which are already partially sorted.
*/
#include<iostream>
using namespace std;
//*Time complexity : O(n²) *Auxiliary space : O(1)
void insertionSort(int *arr,int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertionSort(arr,n);
    for(int i : arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}


