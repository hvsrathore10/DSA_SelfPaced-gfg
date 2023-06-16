#include<iostream>
using namespace std;
// Time Complexity : ϴ(n)
int jos(int n,int k){
    if(n==1){
       return 0;
    }
    else{
        return ((jos(n-1,k) + k)%n);
    }
}
//if index start with 1 inset of 0
int myJos(int n,int k){
    return jos(n,k) + 1;
} 
int main(){
    int n,k;
    cout<<"Enter value of n--> ";
    cin>>n;
    cout<<"Enter value of k--> ";
    cin>>k;
    cout<<"Survivor : "<<jos(n,k)<<endl;
    return 0;
}