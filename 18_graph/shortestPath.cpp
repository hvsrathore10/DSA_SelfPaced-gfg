//Problem :: Given a unweighted graph and source vertex we have to find shortest 
//path from source to every other vertex.
#include<iostream>
#include<queue>
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
void shortestPath(vector<int>* adj,int V,int S){
    //store distance from source vertex to 'i' vertex
    int dist[V];
    fill(dist,dist+V,INT_MAX);

    bool visited[V+1];
    for(int i=0;i<=V;i++)
        visited[i] = false;
    
    queue<int> q;
    dist[S] = 0;
    visited[S] = true;
    q.push(S);
    //computing distance for every vertex - BFS logic
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: adj[u]){
            if(visited[v]==false){
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    //printing shortest distance 
    for(int i=0;i<V;i++)
        cout<<i<<" : "<<dist[i]<<endl;
}
int main(){
    int V = 6;
    vector<int> *adj;
    adj = new vector<int>[V];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,0,4);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,3,5);
    addEdge(adj,4,5);

    toString(adj,V);
    shortestPath(adj,V,0);
    return 0;
}