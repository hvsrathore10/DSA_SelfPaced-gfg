#include<iostream>
using namespace std;
//Time complexity :ϴ(n)
void rotateByOne(int *arr,int n){
    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

//Naive Method :-  *Time Complexity :ϴ(d.n)    *Auxiliary space :ϴ(1)
void rotateByD1(int *arr,int n,int d){
    for(int i=0;i<d;i++){
        rotateByOne(arr,n);
    }
}
//Efficient Method :-  *Time Complexity :ϴ(n)   *Auxiliary space :ϴ(n)
void rotateByD2(int *arr,int n,int d){
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i] = arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d] = arr[i];
    }
    for(int i=0;i<d;i++){
        arr[n-d+i] = temp[i];
    }
}
//Reverse Method :-  *Time Complexity :ϴ(n)   *Auxiliary space :ϴ(1)
void methodReverse(int *arr,int lb,int hb){
    while(lb<hb){
        swap(arr[lb],arr[hb]);
        lb++;
        hb--;
    }
}
void rotateByD3(int *arr,int n,int d){
    methodReverse(arr,0,d-1);
    methodReverse(arr,d,n-1);
    methodReverse(arr,0,n-1);
}

int main(){
    int arr[] = {10,20,30,40};
    int n=sizeof(arr)/sizeof(arr[0]);

    // rotateByOne(arr,n);  -->1 left-rotation
    // rotateByD1(arr,n,2); -->D left-rotation
    rotateByD2(arr,n,2);
    // rotateByD3(arr,n,2);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
