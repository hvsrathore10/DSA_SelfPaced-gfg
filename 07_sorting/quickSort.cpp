/*Note : 
1.Divide and conquer algorithm
2.Worst case time :O(n²)
3.Despite O(n²) worst case, it is onsiderd faster,because of following reason :
    a)In-place
    b)Cache Friendly
    c)Average case is O(n.logn)
    d)Tail Recursive
4.Partition is key function(Naive,Lomuto,Hoare)
5.Unstable
6.For function call stack we can use Tall_Call_Elimination for optimization of QuickSort*/
#include<iostream>
using namespace std;
//*Time :O(n) *Extra space :O(n)
void partitionNaive(int arr[],int l,int h,int p){
    int temp[h-l+1];
    int index=0;
    for(int i=l;i<=h;i++){
        if(arr[i]<=arr[p] && i!=p){
            temp[index] = arr[i];
            index++;
        }
    }
    temp[index++] = arr[p];
    for(int i=l;i<=h;i++){
        if(arr[i]>arr[p]){
            temp[index] = arr[i];
            index++;
        }
    }
    for(int i=l;i<=h;i++){
        arr[i] = temp[i];
    }
}
//*Time :O(n) *Extra space :O(1)
int partitionLomuto(int arr[],int l,int h){
    int pivot = arr[h];
    int i=l-1;
    for(int j=l;j<h;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
//*Time :O(n) *Extra space :O(1)
int partitionHoare(int arr[],int l,int h){
    int pivot = arr[l];
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)
            return j;
        swap(arr[i],arr[j]);
    }
}
//Time complexity :O(n.logn) *Auxiliary space :O(1)
void quickSort(int arr[],int l,int h){
    if(l<h){
        int p = partitionLomuto(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}
//Tail Call Elimination : 
/*void quickSort(int arr[],int low,int high){
    start : 
        if(low<high){
            int p = partitionLomuto(arr,low,high);
            quickSort(arr,low,p-1);

            low = p+1;
            high = high;
            goto start;
        }
}*/

//Time complexity : O(n.logn) -->it will help to prevent recursion overhead 
void quickSortIterative(int arr[],int l,int h){
    //Create stack (it will store index low and high)
    int stack[h-l+1];
    int top = -1;
    
    stack[++top] = l;
    stack[++top] = h;
    while(top>=0){
        h = stack[top--];
        l = stack[top--];
        //Find index of pivot
        int p = partitionLomuto(arr,l,h);
        if(p-1>l){
            stack[++top] = l;
            stack[++top] = p-1;
        }
        if(p+1<h){
            stack[++top] = p+1;
            stack[++top] = h;
        }
    }
}

int main(){
    int arr[] = {8,4,7,9,3,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}

