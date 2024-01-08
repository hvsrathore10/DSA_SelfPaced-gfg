//Cycle detection in Directed graph :: 
#include<iostream>
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
//Time complexity :O(V+E) and Auxiliary space :O(V)
bool detectCycleUtility(vector<int>* adj,int S,bool visited[],bool recStack[]){
    //mark source visited and mark its entry in function call stack
    visited[S] = true;
    recStack[S] = true;

    for(int u: adj[S]){
        if(visited[u]==false && detectCycleUtility(adj,u,visited,recStack))
            return true;
        //check is 'u' present in stack 
        //if present than there will be a backedge present =>backedge == cycle
        else if(recStack[u]==true)
            return true;
    }
    recStack[S] = false;
    return false;
}
bool detectCycle(vector<int>* adj,int V){
    //track which verties is present in function call stack
    bool recStack[V+1];
    //track visited verties :-
    bool visited[V+1];
    for(int i=0;i<=V;i++){
        visited[i] = false;
        recStack[i] = false;
    }
    //call utility function and handle disconnected graph
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            if(detectCycleUtility(adj,i,visited,recStack))
                return true;
    }
    return false;
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