#include<iostream>
using namespace std;
//Naive Mrthod :- Time complexity :O(n^2)
void flipNaive(bool *arr,int n){
    int count_0 = 0,count_1 = 0;
    if(arr[0] == 0)
        count_0 = 1;
    else
        count_1 = 1;
    for(int i=0;i<n-1;i++){
        if(arr[i]==0 && arr[i+1]!=0)
            count_0++;
        else if(arr[i]==1 && arr[i+1]!=1)
            count_1++;
    }
    if(count_0>count_1){
        for(int i=1;i<n;i++){
            if(arr[i]==1){
                cout<<"From "<<i<<" to ";
                for(int j=i;j<n;j++){
                    if(arr[j]==0){
                        cout<<j-1<<endl;
                        i = j;
                        break; } //if-end
                } //second for-loop end
            }
        }
    }
    else{
        for(int i=1;i<n;i++){
            if(arr[i]==0){
                cout<<"From "<<i<<" to ";
                for(int j=i;j<n;j++){
                    if(arr[j]==1){
                        cout<<j-1<<endl;
                        i = j;
                        break;  } //if-end
                } //second for-loop end
            }
        }
    }
}    
//Efficient Method :- Time complexity :O(n)
void flip(bool *arr,int n){
    for(int i=1;i<n;i++){
        if(arr[i] != arr[i-1]){
            if(arr[i] != arr[0])
                cout<<"From "<< i <<" to ";
            else
                cout<<(i-1)<<endl;
        }
    }
    if(arr[n-1] != arr[0]){
        cout<<(n-1)<<endl;
    }
}
int main(){
    bool arr[] = {0,0,1,1,1,0,0,1,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Flip from Naive Method -->"<<endl;
    flipNaive(arr,n);
    cout<<"Flip -->"<<endl;
    flip(arr,n);
    return 0;
}