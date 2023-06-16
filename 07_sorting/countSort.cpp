/*Note : 
1.Not comparision based sorting algorithm
2.Time complexity : ϴ(n+k)
3.Auxiliary space : O(k)  k--> maximum element in array
4.Stable
5.Used as a subroutine in Radix Sort
*/
#include<iostream>
using namespace std;
//Time complxity : O(n+k) *Limitation : It will work only for integer type data.
void countSort1(int arr[],int n,int k){
    int count[k];
    for(int i=0;i<k+1;i++){
        count[i] = 0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    int index = 0;
    for(int i=0;i<k;i++){
        while(count[i]!=0){
            arr[index] = i;
            count[i]--;
            index++;
        }
    }
}
//*Limitation : unable to store negative numbers because index of array never be nagtive.
void countSort(int arr[],int n,int k){
    int count[k],output[n];
    memset(count,0,sizeof(count));
    // for(int i=0;i<k;i++){
    //     count[i] = 0;
    // }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<k;i++){
        count[i] = count[i] + count[i-1];  //cumulative sum 
    }
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    //copy output array into main array 
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}
int main(){
    int arr[] = {0,2,5,4,2,3,5,4,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array Before sorting : "<<endl;
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)
            max = arr[i];
    }
    // countSort1(arr,n,max+1);
    countSort(arr,n,max+1);
    cout<<"Array After sorting : "<<endl;
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}


//For larger value of k (i.e.,inorder of N²) than radixSort will work better.

