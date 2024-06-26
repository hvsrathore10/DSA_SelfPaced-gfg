// Problem Statement ::Given a graph and a source vertex in the graph, 
// find the shortest paths from source to all vertices in the given graph.
/*#include<iostream>
#include<vector>
using namespace std;
  
//Time complexity :O(V²) and Auxiliary space :O(V)
void shortestPath(vector< vector<int> > &adj,int V,int src){
    vector<int> dist(V,INT_MAX); //dist[] <- store distance 
    dist[src] = 0;
    //sptSet[] <- shortest path tree set main which vertices pair are 
    //part of shortest path tree
    vector<bool> sptSet(V,false); 

    for(int count=0;count<V-1;count++){
        int u = -1;
        for(int i=0;i<V;i++)
            if(!sptSet[i] && (u==-1 || dist[i]<dist[u]))
                u = i;

        sptSet[u] = true;

        for(int v=0;v<V;v++){
            if(adj[u][v]!=0 && !sptSet[v])
                dist[v] = min(dist[v],dist[u]+adj[u][v]);
        }
    }
    cout<<"Shortest Path :: ";
    for(int i=0;i<V;i++)
        cout<<dist[i]<<" "; 
}
int main(){
    int V = 9; 
    vector< vector<int> > adj{ {0,4,0,0,0,0,0,8,0},
                            {4,0,8,0,0,0,0,11,0},
                            {0,8,0,7,0,4,0,0,2},
                            {0,4,7,0,9,14,0,0,0},
                            {0,0,0,9,0,10,0,0,0},
                            {0,0,4,14,10,0,2,0,0},
                            {0,0,0,0,0,2,0,1,6},
                            {8,11,0,0,0,0,1,0,7},
                            {0,0,2,0,0,0,6,7,0} }; 
  
    shortestPath(adj, V, 0); 
    return 0;
}
*/


//if we use Adjacency list and Heap(minHeap) in implementation of 
//dijkstra's algorithm then time complexity become O(E.logV) 
#include<iostream>
#include<queue>
#include<vector>
using namespace std; 
  
// iPair ==> Integer Pair 
typedef pair<int, int> iPair; 
  
// To add an edge 
void addEdge(vector <pair<int, int> > adj[], int u,int v, int wt) { 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
} 
  
// Prints distance of shortest paths from the source vertex to all other vertices 
void shortestPath(vector<pair<int,int> > adj[], int V, int src) { 
    // Create a priority queue to store vertices that 
    // are being preprocessed.
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    // Create a vector for distances and initialize all distances as infinite
    vector<int> dist(V, INT_MAX); 
  
    // Insert source itself in priority queue and initialize its distance as 0. 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    /* Looping till priority queue becomes empty (or all 
    distances are not finalized) */
    while (!pq.empty()) { 
        // The first vertex in pair is the minimum distance 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = pq.top().second; 
        pq.pop(); 
  
        // Get all adjacent of u.  
        for (auto x : adj[u]) { 
            // Get vertex label and weight of current adjacent of u. 
            int v = x.first; 
            int weight = x.second; 
  
            // If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    // Print shortest distances stored in dist[] 
    printf("Vertex Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t %d\n", i, dist[i]); 
} 

int main() { 
    int V = 9; 
    vector<iPair > adj[V]; 
  
    //addEdge(adj,source(u),destination(v),weight)
    addEdge(adj, 0, 1, 4); 
    addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7); 
  
    shortestPath(adj, V, 0); 
  
    return 0; 
} 
