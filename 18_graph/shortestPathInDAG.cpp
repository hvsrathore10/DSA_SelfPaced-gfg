#include<iostream>
#include<queue>
using namespace std;

int weight_matrix[5][5];
//Time complexity :O(1)
void addEdge(vector<int>* adj,int u,int v,int wt){
    if(u>=0 && v>=0){
        adj[u].push_back(v);
        weight_matrix[u][v] = wt;
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
int weight(int u,int v){
    return weight_matrix[u][v];
}


void topologicalSort(vector<int>* adj,int V,int sort[]){
    int indegree[V];
    fill(indegree,indegree+V,0);
    for(int u=0;u<V;u++)
        for(int v: adj[u])
            indegree[v]++;
        
    queue<int> q;
    for(int i=0;i<V;i++)
        if(indegree[i]==0)
            q.push(i);
    
    int i = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        sort[i++] = u;
        for(int v: adj[u]){
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }

    }
}
void shortestPath(vector<int>* adj,int V,int S){
    int dist[V];
    fill(dist,dist+V,INT_MAX);
    dist[S] = 0;

    int sort[V];
    int visited[V];
    fill(visited,visited+V,0);

    topologicalSort(adj,V,sort);

    for(int i=0;i<V;i++){
        int u = sort[i];
        for(int v: adj[u])
            if(dist[v] > dist[u]+weight(u,v))
                dist[v] = dist[u] + weight(u,v);
    }

    for(int i=0;i<V;i++)
        cout<<dist[i]<<" ";
}


int main(){
    int V = 6;
    vector<int> *adj;
    adj = new vector<int>[V];

    addEdge(adj,0,1,2);
    addEdge(adj,0,4,1);
    addEdge(adj,1,2,3);
    addEdge(adj,2,3,6);
    addEdge(adj,4,2,2);
    addEdge(adj,4,5,4);
    addEdge(adj,5,3,1);

    toString(adj,V);
    shortestPath(adj,V,0);
    return 0;
}