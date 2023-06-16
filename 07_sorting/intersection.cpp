//Discription : Find intersection of two sorted arrays.
#include<iostream>
using namespace std;
//Naive method  :- *Time complexity :O(n*m)
void getIntersectionNaive(int a[],int b[],int n,int m){
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1])
            continue;
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                cout<<a[i]<<" ";
                break;
            }
        }
    }
}
//Efficient Method :- *Time complexity : ϴ(n+m)
void getIntersection(int a[],int b[],int n,int m){
    int i=0,j=0;
    while(i<n && j<m){
        if(i>0 && a[i]==a[i-1]){
            i++;
            continue;
        }
        if(a[i]<b[j])
            i++;
        else if(a[i]>b[j])
            j++;
        else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
}
int main(){
    int arr1[] = {3,5,10,10,15,15,20};
    int arr2[] = {5,10,10,15,20,30};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    getIntersection(arr1,arr2,n,m);
    return 0;
}