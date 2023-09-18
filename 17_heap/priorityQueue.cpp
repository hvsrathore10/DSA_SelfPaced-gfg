#include<iostream>
#include<queue>
using namespace std;
 
int main(){
    //By default C++ priority_queue form MAX_HEAP where 
    //as Java PriorityQueue class form MIN_HEAP bu default
    priority_queue<int> max_heap;
    max_heap.push(10);
    max_heap.push(5);
    max_heap.push(30);

    cout<<"Max Heap : ";
    while(!max_heap.empty()){
        cout<<max_heap.top()<<" ";
        max_heap.pop();
    }

    priority_queue< int,vector<int>,greater<int> > min_heap;
    min_heap.push(10);
    min_heap.push(5);
    min_heap.push(30);

    cout<<"\nMin Heap : ";
    while(!min_heap.empty()){
        cout<<min_heap.top()<<" ";
        min_heap.pop();
    }
    return 0;
}