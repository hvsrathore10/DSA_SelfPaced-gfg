#include<stdio.h>
//Naive Method :- 
// Time Complexity :ϴ(n^2) 
// Auxiliary space = O(1)
int getOddOccurring1(int *arr,int n){
    
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                cnt++;
            }
        }    
        if(cnt%2!=0){
            return arr[i];
        }
    }
    return 0;
}
//Efficient Method :  -->Hashing is also have Time Complexity :ϴ(n), but with Auxiliary space = O(n)
// Time Complexity :ϴ(n) 
// Auxiliary space = O(1)
int getOddOccurring2(int *arr,int n){
    int res = arr[0];
    for(int i=1;i<n;i++){
        res = res^arr[i];
    }
    return res;
}
int main()
{
    int arr[] = {2,2,2,2,3,3,3,4,4,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d occurres ODD Number of time in array\n",getOddOccurring1(arr,n));
    printf("%d occurres ODD Number of time in array\n",getOddOccurring2(arr,n));
    return 0;
}
