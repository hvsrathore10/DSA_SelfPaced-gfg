//If data is uniformly distributed across the array Bucketsort is best sutable.
#include<iostream>
#include<vector>
using namespace std;
//Best case TIME : O(n)  Worst case TIME : O(n²) if used inserction sort and O(n㏒n) if merge or heap sort is used
void bucketSort(int arr[],int n,int k){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)
            max = arr[i];
    }
    max = max + 1;
    vector<int> bkt[k];
    for(int i=0;i<n;i++){
        int bi = (k*arr[i])/max;
        bkt[bi].push_back(arr[i]);
    }
    for(int i=0;i<k;i++){
        sort(bkt[i].begin(),bkt[i].end());
    }
    int index = 0;
    for(int i=0;i<k;i++){
        for(int j=0;j<bkt[i].size();j++){
            arr[index++] = bkt[i][j];
        }
    }
}
int main(){
    int arr[] = {20,50,80,60,18,30,25,100,90};
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
    bucketSort(arr,n,5);
    cout<<"Array After sorting : "<<endl;
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}

