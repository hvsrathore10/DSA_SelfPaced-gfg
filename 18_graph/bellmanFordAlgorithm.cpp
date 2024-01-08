// Problem: Given a graph and a source vertex src in graph,find shortest paths 
// from src to all vertices in the given graph.The graph may contain negative 
// weight edges.
#include<iostream>
using namespace std;

class Edge {
    public: 
        int src,dest,weight;
};
class Graph {
    public: 
        int V,E;
        Edge *edge;
};
Graph* createGraph(int V,int E) {
    Graph *graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    return graph;
}

//Time complexity :: O(V﹡E) and Auxiliary space :O(V)
void bellmanFord(Graph *adj,int V,int E,int src){
    // Step 1: Initialize distances from src to all other vertices as INFINITE
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;
    
    // Step 2: Relax all edges |V| - 1 times. A simple shortest 
    // path from src to any other vertex can have at-most |V| - 1 edges
    for(int count=0;count<(V-1);count++){
        for(int i=0;i<E;i++){
            int u = adj->edge[i].src;
            int v = adj->edge[i].dest;
            int weight = adj->edge[i].weight;

            //relax operation on edge (u-v)
            if(dist[u]!=INT_MAX && ( dist[v] > dist[u]+weight))
                dist[v] = dist[u] + weight;
        }
    }
    // Step 3: check for negative-weight cycles.The above step guarantees 
    // shortest distances if graph doesn't contain negative weight cycle.
    // If we get a shorter path, then there is a cycle.
    for(int i=0;i<E;i++){
        int u = adj->edge[i].src;
        int v = adj->edge[i].dest;
        int weight = adj->edge[i].weight;

        if(dist[u]!=INT_MAX && (dist[u]+weight < dist[v])){
            cout<<"Graph contains negative weight cycle\n";
            return;
        }
    }
    //print distance array :
    for(int i=0;i<V;i++)
        cout<<i<<"\t"<<dist[i]<<endl;
}

int main() {
    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    Graph* graph = createGraph(V, E);

    // add edge 0-1 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // add edge 0-2 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // add edge 1-3 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // add edge 1-4 
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // add edge 3-2 
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // add edge 3-1 
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // add edge 4-3
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    bellmanFord(graph,V,E,0);
    return 0;
}
/*
      [1]____________
     / | \           |
    /  |  \          |
   /   |   \        [4]
[0]    |    \       /
   \   |     \     / 
    \  |      \   /
     \ |       \ /
      [2]------[3]
*/