/*This video discusses a famous interview problem in which you need to segregate an array of elements containing three types of elements. The types are:
1.Sort an array of 0s, 1s, 2s.
2.Three-way partitioning when multiple occurrences of a pivot may exist.
3.Partitioning around a range.*/
#include<iostream>
using namespace std;
//Naive Method :- *Time complexity :O(n) *Auxiliary space :O(n)
void sortThreeTypes(int arr[],int n){
    int temp[n],i=0;
    //Set all zeroes at there position
    for(int j=0;j<n;j++){
        if(arr[j]==0){
            temp[i] = arr[j];
            i++;
        }
    } 
    //It will set all 1's at there position
    for(int j=0;j<n;j++){
        if(arr[j]==1){
            temp[i] = arr[j];
            i++;
        }
    }
    //It will set all 2's at there position
    for(int j=0;j<n;j++){
        if(arr[j]==2){
            temp[i] = arr[j];
            i++;
        }
    }
    for(int j=0;j<n;j++){
        arr[j] = temp[j];
    }
}
//Efficient Method :- Dutch National Flag Algorithm
//Time complexity :O(n) Auxiliary space :O(1)
void sortThreeTypesEle(int arr[],int n){
    int low = 0,mid = 0,high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    // sortThreeTypes(arr,n);
    sortThreeTypesEle(arr,n);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}

