#include<iostream>
#include <list>

#define NIL -1
using namespace std;

// A class that represents an undirected graph
class Graph {
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    void bridgesUtil(int v, bool visited[], int disc[], int low[],int parent[]);
    public:
        Graph(int V);   // Constructor
        void addEdge(int v, int w);   // function to add an edge to graph
        void Bridge();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); 
}

// A recursive function that find bridges in graph using DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] --> Stores lowest discovery time of visited vertices via forward edge or back edge
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgesUtil(int u,bool visited[],int disc[],int low[],int parent[]) {
    static int time = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices adjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;  // v is current adjacent of u

        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v]){
            parent[v] = u;
            bridgesUtil(v, visited, disc, low, parent);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u (∵ of back edge)
            low[u]  = min(low[u], low[v]);

            //u-v edge is bridge if following condition is true
            if (low[v] > disc[u])
               cout<<u<<" "<<v<<endl;
        }
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

// The function to do DFS traversal. 
// It uses recursive function bridgesUtil()

// Time complexity :O(V+E) and Auxiliary space :O(V)
void Graph::Bridge() {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];

    // Initialize parent and visited arrays
    for (int i = 0; i < V; i++){
        parent[i] = NIL;
        visited[i] = false;
    }

    // Call the recursive helper function to find bridges in graph
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgesUtil(i, visited, disc, low, parent);
}

// Driver program to test above function
int main() {
    // Create graphs given in below diagrams
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.Bridge();

    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.Bridge();

    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.Bridge();

    return 0;
}

/*
    Graph 1 :
        1----0----3
        |   /     |
        |  /      |
        | /       |
        2         4
    Graph 2 :
        0
        |
        1
        |
        2
        |
        3
    Graph 3 :
        0       3
        | \    / \
        |  \  /   \
        |   1      5
        |  /| \   /
        | / |  \ /
        2   |   4
            6
*/