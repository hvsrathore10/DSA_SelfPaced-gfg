#include <iostream>
using namespace std;

class MaxHeap{
    int capacity, size;
    int *arr;

public:
    MaxHeap(int cap){
        size = 0;
        capacity = cap;
        arr = new int(capacity);
    }
    //Time complexity :O(1)
    int parent(int i) { return (i-1)/2; }
    int leftChild(int i) { return (2*i + 1); }
    int rightChild(int i) { return (2*i + 2); }
    //Time complexity :ϴ(size)
    void printHeap(){
        for(int i=0;i<size;i++) 
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    void insert(int data);
    void heapify(int i);
    int extract();
    int peek();
    void increaseKey(int index, int key);
    int deleteKey(int index);
    void buildHeap();
};

//Time complexity :O(logN)
void MaxHeap::insert(int data){
    if (size == capacity)
        return;

    size++;
    arr[size-1] = data;

    for(int i=size-1;i!=0 && arr[i]>arr[parent(i)];){
        swap(arr[i],arr[parent(i)]);
        i = parent(i);
    }
}
//Time complexity :O(logN)  N -->No. of nodes And Auxiliary space :O(logN)
void MaxHeap::heapify(int i){
    int lc = leftChild(i);
    int rc = rightChild(i);
    int largest = i;
    // find smallest b/w three patent,leftchild & rightchild
    if (lc < size && arr[lc] > arr[largest])
        largest = lc;
    if (rc < size && arr[rc] > arr[largest])
        largest = rc;

    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(largest);
    }
}
//Time complexity :O(logN)
int MaxHeap::extract(){
    if (size <= 0)
        return INT_MAX;
    if (size == 1){
        size--;
        return arr[0];
    }

    swap(arr[0], arr[size - 1]);
    size--;
    heapify(0);
    return arr[size];
}
//Time complexity :O(1)
int MaxHeap::peek(){
    return arr[0];
}
//Time complexity :O(logN)
void MaxHeap::increaseKey(int index, int key){
    if (index < 0 || index > size)
        return;

    arr[index] = key;
    while (index > 0 && arr[index] > arr[parent(index)]){
        swap(arr[index], arr[parent(index)]);
        index = parent(index);
    }
}
//Time complexity :O(logN)
int MaxHeap::deleteKey(int index){
    increaseKey(index,INT_MAX);
    return extract();
}
//Time complexity :O(N)
void MaxHeap::buildHeap(){
    if (size == 0)
        return;

    for (int i = (size - 2 / 2); i >= 0; i--){
        heapify(i);
    }
}


int main(){
    MaxHeap obj(10);
    // arr = {10,15,50,80,12,20}

    obj.insert(10);
    obj.insert(15);
    obj.insert(50);
    obj.insert(80);
    obj.insert(12);
    obj.insert(20);
    obj.insert(2);
    cout<<"Heap : ";
    obj.printHeap();
    return 0;
}