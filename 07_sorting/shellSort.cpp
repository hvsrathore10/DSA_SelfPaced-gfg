//ShellSort is extended part of insertionSort.We required shellSort when large data is given and smaller number are present at the end because in this case insertionSort work really very bad.(i.e.,inserction ka code fat jaaga)
// *Time complexity : O(n²) *Auxiliary space : O(1)

#include<iostream>
using namespace std;
//Time complexity :- Worst case : O(n²) Best case : Ω(n.logn) Average case : ϴ(n.logn)
void shellSort(int arr[],int n){
    // Gap finding tech. - Hibbard sequence uses powers of 2 as the gap {n/2,n/4,n/8,n/16....}
    for(int gap = n/2;gap>0;gap/=2){

        for(int i=gap;i<n;i++){
            int key = arr[i];
            int j = i;
            while(j>=gap && arr[j-gap]>key){
                arr[j] = arr[j-gap];
                j = j - gap;
            }
            arr[j] = key;
        }
    }
}
int main(){
    int arr[] = {12, 34, 54, 70, 3, 60, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before Sorting : "<<endl;
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    cout<<"Array after Sorting : "<<endl;
    shellSort(arr,n);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}



