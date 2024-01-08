/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear 
ordering of vertices such that for every directed edge uv, vertex 
u comes before v in the ordering. Topological Sorting for a graph 
is not possible if the graph is not a DAG.
*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//Time complexity :O(1)
void addEdge(vector<int>* adj,int u,int v){
    if(u>=0 && v>=0)
        adj[u].push_back(v);
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
void findIndegree(vector<int>* adj,int indegree[],int V){
    //set indegree as zero for all verties :
    for(int i=0;i<V;i++)
        indegree[i] = 0;
    //calculate indegree's :
    for(int u=0;u<V;u++){
        for(int v: adj[u])
            indegree[v]++;
    }
}
//Topological Sort - Kahn's Algorithm
//Time complexity :O(V+E) and Auxiliary space :O(V)
void topologicalSort(vector<int>* adj,int V){
    //store indegree : 
    int indegree[V];
    findIndegree(adj,indegree,V);

    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";

        for(int v: adj[u]){
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }
    }
}
//DFS based topological sort :: Time complexity :O(V+E) and Auxiliary space :O(V)
void dfs(vector<int>* adj,int S,bool visited[],stack<int> &st){
    visited[S] = true;

    for(int u: adj[S]){
        if(visited[u]==false)
            dfs(adj,u,visited,st);
    }
    st.push(S);
}
void topologicalSortDFS(vector<int>* adj,int V){
    stack<int> st;
    bool visited[V+1];
    for(int i=0;i<=V;i++)
        visited[i] = false;

    for(int i=0;i<V;i++)
        if(visited[i]==false)
            dfs(adj,i,visited,st);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

}

int main(){
    int V = 6;
    vector<int> *adj;
    adj = new vector<int>[V];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,3,5);

    toString(adj,V);
    cout<<"\nOutput of Topological Sort using Kahn's Algorithm ::";
    topologicalSort(adj,V);
    cout<<"\nOutput of Topological Sort using DFS ::";
    topologicalSortDFS(adj,V);
    return 0;
}