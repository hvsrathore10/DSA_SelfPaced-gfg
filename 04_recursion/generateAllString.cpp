/*
Problem :
Given an integer, K. Generate all binary strings of size k without consecutive 1’s.
Input : K = 3  
Output : 000 , 001 , 010 , 100 , 101 
Input : K  = 4 
Output :0000 0001 0010 0100 0101 1000 1001 1010
*/
#include<iostream>
using namespace std;

void printStrings(char str[],int k,int n){
    if(n==k){
        str[n] = '\0';
        cout<<str<<" ";
        return;
    }
    if(str[n-1] == '1'){
        str[n] = '0';
        printStrings(str,k,n+1);
    }
    if(str[n-1] == '0'){
        str[n] = '1';
        printStrings(str,k,n+1);
        str[n] = '0';
        printStrings(str,k,n+1);
    }
}
void generateAllStrings(int k){
    char str[k];
    str[0] = '1';
    printStrings(str,k,1);
    str[0] = '0';
    printStrings(str,k,1);
}
int main(){
    int t;
    cout<<"Number of Test Case : ";
    cin>>t;
    while(t > 0){
        int k;
        cout<<"\nEnter value for K : ";
        cin>>k;
        generateAllStrings(k);
        t--;
    }
    return 0;
}