//Cycle detection using topological sort
#include<iostream>
#include<queue>
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
//Time complexity :O(V+E)
bool detectCycle(vector<int>* adj,int V){
    int indegree[V];
    fill(indegree,indegree+V,0);
    for(int u=0;u<V;u++){
        for(int v: adj[u])
            indegree[v]++;
    }

    queue<int> q;
    for(int i=0;i<V;i++)
        if(indegree[i]==0)
            q.push(i);
        
    int count = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: adj[u]){
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }
        count++;
    }
    return (count!=V);
}
int main(){
    int V = 6;
    vector<int> *adj;
    adj = new vector<int>[V];

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,2);
    addEdge(adj,5,3);

    toString(adj,V);
    cout<<"Cycle is present : "<<(detectCycle(adj,V)?"Yes":"No")<<endl;
    return 0;
}