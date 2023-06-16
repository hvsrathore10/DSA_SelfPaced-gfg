// This video explains the problem "Intersection of two unsorted arrays" firstly using 
// Naive Approach and goes on to optimise the solution further using Hashing. 
#include<iostream>
#include<unordered_set>

using namespace std;
//Naive Approach : Time complexity : O(n*m)
void intersectionNaive(int a[],int n,int b[],int m){
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                flag = true;
                break;
            }
        }
        if(flag)
            cout<<a[i]<<" ";
    }
}
//Efficient Approach : (Using Hashing) Time complexity : ϴ(n+m)  Auxiliary space :O(n+m)
void intersection(int a[],int n,int b[],int m){
    //inserction in hashTable :O(m)
    unordered_set<int> set(b,b+m);
    //O(n)
    for(int i=0;i<n;i++){
        auto ite = set.find(a[i]);
        if(ite!=set.end())
            cout<<*(ite)<<" ";
    }
    // We put array b[], in the hash table because we need to print the intersection 
    // in the same order as the elements of array a[].
}
int main(){
    int a[] = {10,15,20,25,30,50};
    int n = sizeof(a)/sizeof(a[0]);
    int b[] = {30,5,15,80};
    int m = sizeof(b)/sizeof(b[0]);

    intersection(a,n,b,m);
    return 0;
}