//Cycle detection in Undirected graph :: 
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
bool detectCycleUtility(vector<int>* adj,int S,bool visited[],int parent){
    //mark visited source vertex
    visited[S] = true;
    //check for cycle in connected vertex of source vertex
    for(int u: adj[S]){
        if(visited[u]==false){
            if(detectCycleUtility(adj,u,visited,S))
                return true;
        }
        else if(u!=parent)
            return true;
    }
    return false;
}
bool detectCycle(vector<int>* adj,int V){
    //track visited verties :-
    bool visited[V+1];
    for(int i=0;i<=V;i++)
        visited[i] = false;
    //call utility function and handle disconnected graph
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            if(detectCycleUtility(adj,i,visited,-1))
                return true;
    }
    return false;
}
int main(){
    int V = 4;
    vector<int> *adj;
    adj = new vector<int>[V];

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);

    toString(adj,V);
    cout<<"Cycle is present : "<<(detectCycle(adj,V)?"Yes":"No")<<endl;
    return 0;
}