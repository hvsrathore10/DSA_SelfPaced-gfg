// Problem :Given a number n,print first n numbers(increasing order) such that all these number have 
// digit in set{5,6} only
#include<iostream>
#include<queue>
#include<string>
using namespace std;

void printFirstN(int n){
    queue<string> q;

    q.push("5");
    q.push("6");

    for(int i=0;i<n;i++){
        string curr = q.front();
        cout<<curr<<" ";
        q.pop();
        q.push(curr+'5');
        q.push(curr+'6');
    }cout<<endl;
}
 
int main(){
    int n;
    cout<<"Enter a value for n : ";
    cin>>n;

    printFirstN(n);
    return 0;
}