#include<iostream>
using namespace std;
//Naive Method :-  *Time complexity :ϴ(n^2)  *Auxiliary space :ϴ(1)
int maxConsecutiveOnes(bool *arr,int n){
    int res = 0;
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=i;j<n;j++){
            if(arr[j] == 1)
                count++;
            else
                break;
        }
        res = max(res,count);
    }
    return res;
}
//Efficient Meyhod :-  *Time complexity :ϴ(n)  *Auxiliary space :ϴ(1)
int maximumConsecutiveOnes(bool *arr,int n){
    int count = 0,res = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)
            count = 0;
        else{
            count++;
            res = max(res,count);
        }
    }
    return res;
}
int main(){
    bool arr[] = {0,1,1,0,0,1,1,1,1,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum Consecutive Ones : "<<maxConsecutiveOnes(arr,n)<<endl;
    cout<<"Maximum Consecutive Ones : "<<maximumConsecutiveOnes(arr,n)<<endl;
    return 0;
}
