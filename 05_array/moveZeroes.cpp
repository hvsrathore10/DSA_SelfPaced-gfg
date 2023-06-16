#include <iostream>
using namespace std;
//Naive Meyhod :- Time complexity :O(n^2)
void moveZero(int *arr, int n){
    for (int i = 0; i < n-1; i++){
        if (arr[i] == 0){
            for(int j=i+1;j<n;j++){
                if(arr[j]!=0){
                    swap(arr[i],arr[j]);
                    break;
                }
            }
        }
    }
}
//Efficient Meyhod :- Time complexity :O(n)
void moveZeroes(int *arr,int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[count]);
            count++;
        }
    }
}
int main(){
    int arr[] = {8, 5, 0, 0, 10, 0, 20, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    moveZeroes(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}