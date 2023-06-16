/*Chocolate Problem : Given an array of N integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates.There are m students, the task is to distribute chocolate packets such that: 
1.Each student gets one packet.
2.The difference between the number of chocolates in the packet with maximum chocolates and the packet 
with minimum chocolates given to the students is minimum.*/
#include<iostream>
using namespace std;

int chocolateDistribution(int arr[],int n,int m){
    if(m==0 || n==0)
        return 0;
    if(m>n)
        return -1;
        
    sort(arr,arr+n);
    int res = arr[m-1] - arr[0];
    for(int i=1;(i+m-1)<n;i++){
        res = min(res,arr[i+m-1]-arr[i]);
    }
    return res;
}
int main(){
    int arr[] = {7,3,2,4,9,12,56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m;
    cout<<"Enter number of child : ";
    cin>>m;
    cout<<chocolateDistribution(arr,n,m)<<endl;
    return 0;
}