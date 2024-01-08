#include<iostream>
using namespace std;

//Adjacency Matrix : 
class MyGraph{
    private:
        bool **adj;
        int numVertices;
    
    public:
        MyGraph(int numVertices){
            this->numVertices = numVertices;
            adj = new bool*[numVertices];
            for(int i=0;i<numVertices;i++){
                adj[i] = new bool[numVertices];
                for(int j=0;j<numVertices;j++)
                    adj[i][j] = false;
            }
        }
        //Time complexity :O(1)
        void addEdge(int u,int v){
            if((u>=0 && u<numVertices) && (v>=0 && v<numVertices)){
                adj[u][v] = true;
                adj[v][u] = true;
            }
            else
                cout<<"Enter a valied Edge location"<<endl;
        }
        //Time complexity :O(1)
        void removeEdge(int u,int v){
            if((u>=0 && u<numVertices) && (v>=0 && v<numVertices)){
                adj[u][v] = false;
                adj[v][u] = false;
            }
            else
                cout<<"Enter a valied Edge location"<<endl;
        }
        //Print Matrix : 
        void toString(){
            for(int i=0;i<numVertices;i++){
                cout<<i<<" : ";
                for(int j=0;j<numVertices;j++)
                    cout<<adj[i][j]<<" ";
                cout<<endl;
            }
        }
};
//Adjacency List : 
class Graph{
    private:
        vector<int> *adj;
        int numVertices;

    public:
        Graph(int numVertices){
            this->numVertices = numVertices;
            adj = new vector<int>[numVertices];
        }
        //Time complexity :O(1)
        void addEdge(int u,int v){
            if(u>=0 && v>=0){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            else
                cout<<"Enter correct edge location"<<endl;
        }
        //Time complexity :O(V)
        void removeEdge(int u,int v){
            // Traversing through the first vector list
            // and removing the second element from it
            for(int i=0;i<adj[u].size();i++){
                if(adj[u][i] == v){
                    adj[u].erase(adj[u].begin()+i);
                    break;
                }
            }
            // Traversing through the second vector list
            // and removing the first element from it
            for(int i=0;i<adj[v].size();i++){
                if(adj[v][i] == u){
                    adj[v].erase(adj[v].begin()+i);
                    break;
                }
            }
        }

        void toString(){
            for(int i=0;i<numVertices;i++){
                cout<<i<<" : ";
                for(int x: adj[i])
                    cout<<x<<" ";
                cout<<endl;
            }
        }
};
int main(){
    MyGraph adjMatrix(4);
    adjMatrix.addEdge(0,1);
    adjMatrix.addEdge(0,2);
    adjMatrix.addEdge(1,2);
    adjMatrix.addEdge(1,3);

    adjMatrix.toString();

    Graph adjList(4);
    adjList.addEdge(0,1);
    adjList.addEdge(0,2);
    adjList.addEdge(1,2);
    adjList.addEdge(1,3);

    adjList.toString();
    return 0;
}