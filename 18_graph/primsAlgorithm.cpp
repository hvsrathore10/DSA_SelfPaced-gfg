#include<iostream>
#define V 5
using namespace std;

//Time complexity :O(V²)
int primsAlgo(int graph[V][V]){
    int key[V],res = 0;
    fill(key,key+V,INT_MAX);
    key[0] = 0;

    bool mstSet[V];
    fill(mstSet,mstSet+V,false);

    for(int count=0;count<V;count++){
        int u = -1;
        for(int i=0;i<V;i++)
            if(!mstSet[i] && (u==-1 || key[i]<key[u]))
                u = i;
        
        mstSet[u] = true;
        res = res + key[u];
        for(int v=0;v<V;v++){
            if(graph[u][v]!=0 && mstSet[v]==false)
                key[v] = min(key[v],graph[u][v]);
        }
    }
    return res;
}
int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
    cout<<"Cost of Minimum Spanning Tree :: "<<primsAlgo(graph)<<endl;
    return 0;
}