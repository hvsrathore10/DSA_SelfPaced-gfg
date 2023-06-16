#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//Naive Approach : Time complxity :O(n*n + m*(n+m)) Auxiliary space :O(n+m)
int getUnionNaive(int a[],int n,int b[],int m){
    vector<int> dist;
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<dist.size();j++){
            if(a[i]==dist[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            dist.push_back(a[i]);
        }
    }
    for(int i=0;i<m;i++){
        bool flag = false;
        for(int j=0;j<dist.size();j++){
            if(b[i]==dist[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            dist.push_back(b[i]);
        }
    }
    cout<<"Union of a[] & b[] : "<<endl; 
    for(int i=0;i<dist.size();i++)
        cout<<dist[i]<<" ";
    return dist.size();
}
//Efficent Approach : Time complexity : ϴ(n+m) Auxiliary space :O(n+m)
int getUnion(int a[],int n,int b[],int m){
    unordered_set<int> set(a,a+n);
    for(int i=0;i<m;i++){
        auto ite = set.find(b[i]);
        //it indicate b[i] is not present in Hash Table
        if(ite==set.end())
            set.insert(b[i]);
    }
    cout<<"Union of a[] & b[] : "<<endl;
    for(auto ite : set)
        cout<<ite<<" ";
    return set.size();
}
int main(){
    int a[] = {10,15,20,25,30,50};
    int n = sizeof(a)/sizeof(a[0]);
    int b[] = {30,5,15,80};
    int m = sizeof(b)/sizeof(b[0]);
     
    // int res = getUnionNaive(a,n,b,m);
    int res = getUnion(a,n,b,m);
    cout<<"\nNumber of distint element in array a[] & b[] : "<<res<<endl; 
    return 0;
}