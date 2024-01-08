#include<iostream>
using namespace std;

//Time complexity :O(1)
void addEdge(vector<int>* adj,int u,int v){
    if(u>=0 && v>=0){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    else
        cout<<"Enter correct edge location"<<endl;
}
void toString(vector<int>* adj,int V){
    for(int i=0;i<V;i++){
        cout<<i<<" : ";
        for(int x: adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}
//Time complexity :O(V+E) and Auxiliary space :O(V)
void dfsRec(vector<int>* adj,bool visited[],int S){
    visited[S] = true;
    cout<<S<<" ";
    for(int u: adj[S])
        if(visited[u] == false)
            dfsRec(adj,visited,u);
}
void dfs(vector<int>* adj,int V,int S){
    bool visited[V+1];
    for(int i=0;i<=V;i++)
        visited[i] = false;
    
    dfsRec(adj,visited,S);
}
int main(){
    int V = 6;
    vector<int> *adj;
    adj = new vector<int>[V];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,4);
    addEdge(adj,3,4);
    addEdge(adj,3,5);
    addEdge(adj,4,5);

    toString(adj,V);
    cout<<"Depth First Search :: ";
    dfs(adj,V,0);
    return 0;
}