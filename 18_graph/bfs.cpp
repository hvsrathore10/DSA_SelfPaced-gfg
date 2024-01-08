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

//First Version :: Givem an undirected graph and a source vertex 'S' print
//BFS from the given source. Example :Social Network
//*Time Complexity :O(V+E) and Auxiliary space :O(V)
void bfs(vector<int> *adj,int V,int S){
    bool visited[V+1];
    for(int i=0;i<=V;i++)
        visited[i] = false;
    queue<int> q;
    q.push(S);
    visited[S] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        cout<<u<<" ";
        for(int v: adj[u]){
            if(visited[v]==false){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
//Second Version :: Find BFS when Source is not given and graph can 
//be disconnected.Example :Web Crawling
//*Time Complexity :O(V+E) and Auxiliary space :O(V)
void bfs2(vector<int> *adj,bool visited[],int S){
    queue<int> q;
    q.push(S);
    visited[S] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        cout<<u<<" ";
        for(int v: adj[u]){
            if(visited[v]==false){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
void bfsUtility(vector<int>* adj,int V){
    bool visited[V+1];
    for(int i=0;i<=V;i++)
        visited[i] = false;
    
    for(int u=0;u<V;u++){
        if(visited[u] == false)
            bfs2(adj,visited,u);
    }
}
//Third Version ::Given a undirected disconnected graph.find count of 
// connected components in this graph.(or print number of islands in a graph).
//*Time Complexity :O(V+E) and Auxiliary space :O(V)
void bfs3(vector<int> *adj,bool visited[],int S){
    queue<int> q;
    q.push(S);
    visited[S] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        cout<<u<<" ";
        for(int v: adj[u]){
            if(visited[v]==false){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
int bfsUtility3(vector<int>* adj,int V){
    bool visited[V+1];
    for(int i=0;i<=V;i++)
        visited[i] = false;
    
    int count = 0;
    for(int u=0;u<V;u++){
        if(visited[u] == false){
            count++;
            bfs3(adj,visited,u);
        }
    }
    return count;
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
    cout<<"Breadth First Search(BFS) - 1v :: ";
    bfs(adj,V,0);
    // cout<<"Breadth First Search(BFS) - 2v :: ";
    // bfsUtility(adj,V);
    // cout<<"Breadth First Search(BFS) - 3v :: "<<bfsUtility3(adj,V);
    return 0;
}