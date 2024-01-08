#include<iostream>
#define N 5
using namespace std;

int parent[N];
int ranks[N];
void initialize(){
    for(int i=0;i<N;i++){
        parent[i] = i;
        ranks[i] = 0;
    }
}
//Time complexity :O(N) and Auxiliary space :O(1)
int find(int x){
    if(parent[x]==x)
        return x;
    else
        return find(parent[x]);
}
//Time complexity :O(N) and Auxiliary space :O(1)
void unions(int x,int y){
    int x_rep = find(x);
    int y_rep = find(y);

    if(x_rep == y_rep)
        return;
    else    
        parent[y_rep] = x_rep;
}
//After Rank and Path compression ::
//For m operations on n elements : 
//Time complexity : O(m.⍺(n)) ==>⍺(n)≤4 where ⍺(n) is Inverse Ackermann Function

//Rank is optimization techniques for union function
void unionByRank(int x,int y){
    int x_rep = find(x);
    int y_rep = find(y);

    if(x_rep == y_rep)    
        return;
    if(ranks[x_rep]<ranks[y_rep])
        parent[x_rep] = y_rep;
    else if(ranks[x_rep]>ranks[y_rep])
        parent[y_rep] = x_rep;
    else{
        parent[y_rep] = x_rep;
        ranks[x_rep]++;
    }   
} 
// Path compression is optimization techniques for find function
int find(int x){
    if(parent[x]==x)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}
int main(){
    initialize();

    unionByRank(3,4);
    unionByRank(2,3);
    unionByRank(1,2);
    unionByRank(0,1);
    
    cout<<parent[3]<<endl;
    cout<<ranks[3]<<endl;
    return 0;
}