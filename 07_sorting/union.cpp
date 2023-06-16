#include<iostream>
using namespace std;
//Naive Method :Time complexity :ϴ((n+m).log(n+m))  *Auxiliary space : ϴ(n+m)
void getUnionNaive(int *a,int *b,int n,int m){
    int temp[m+n];
    for(int i=0;i<n;i++){
        temp[i] = a[i];
    }
    for(int i=0;i<m;i++){
        temp[n+i] = b[i];
    }
    sort(temp,temp+(n+m));
    for(int i=0;i<n+m;i++){
        if(i>0 && temp[i]==temp[i-1])
            continue;
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
//Time complexity :O(n+m)  *Auxiliary space : O(1)
void getUnion(int *a,int *b,int n,int m){
    int i=0,j=0;
    while(i<n && j<m){
        if(i>0 && a[i]==a[i-1]){        //-->It will handle duplicates
            i++;
            continue;
        }
        if(j>0 && b[j]==b[j-1]){
            j++;
            continue;
        }
        if(a[i]==b[j]){
            cout<<a[i]<<" ";
            i++;
            j++;
        }
        else if(a[i]<b[j]){
            cout<<a[i]<<" ";
            i++;
        }
        else{
            cout<<b[j]<<" ";
            j++;
        }
    }
    while(i<n){
        if(i>0 && a[i]==a[i-1]){
            i++;
            continue;
        }
        cout<<a[i]<<" ";
        i++;
    }
    while(j<m){
        if(j>0 && b[j]==b[j-1]){
            j++;
            continue;
        }
        cout<<b[j]<<" ";
        j++;
    }
}
int main(){
    int arr1[] = {3,5,8,8,9,9};
    int arr2[] = {2,8,9,10,15,15,15};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    getUnionNaive(arr1,arr2,n,m);
    getUnion(arr1,arr2,n,m);
    return 0;
}

