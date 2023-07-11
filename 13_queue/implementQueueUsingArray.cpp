#include<iostream>
using namespace std;

//Simple Implementation : 
struct MyQueue{
    int *arr;
    int cap;
    int front,rear;
    MyQueue(int capacity){
        cap = capacity;
        arr = new int[cap];
        front = rear = -1;
    }

    void enqueue(int x){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;}
        if(front == -1 && rear == -1)
            front = rear = 0;
        else
            rear++;

        arr[rear] = x;
    }
    int dequeue(){
        if(isEmpty()) return -1;

        int t = arr[front];
        front++;
        return t;
    }
    int getFront(){
        return front;
    }
    int getRear(){
        return rear;
    }
    bool isFull(){
        if(rear == cap-1)
            return true;
        return false;
    }
    bool isEmpty(){
        if(front == -1 || front>rear)
            return true;
        return false;
    }
    int size(){
        return rear + 1;
    }
};
// What is Circular Queue ?
// A circular queue is a linear queue that behaves as if the end position of the queue 
// is connected to the start position, forming a circular ring. It is also known as a Ring Buffer.
struct MyCircularQueue{
    int *arr;
    int cap;
    int front,rear;
    MyCircularQueue(int capacity){
        cap = capacity;
        arr = new int[cap];
        front = rear = -1;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue Overflow\n";
            return;}
        if(front == -1 && rear == -1)
            front = 0;

        rear = (rear+1)%cap;
        arr[rear] = x;
    }
    int dequeue(){
        if(isEmpty()) return -1;

        int t = arr[front];
        if(front == rear)
            front = rear = -1;
        else 
            front = (front+1)%cap;

        return t;
    }
    int getFront(){
        return front;
    }
    int getRear(){
        return rear;
    }
    bool isFull(){
        if((rear+1)%cap == front)
            return true;
        return false;
    }
    bool isEmpty(){
        if(front == -1)
            return true;
        return false;
    }
    int size(){
        return front > rear ? (cap - (front - rear) + 1) : ((rear - front) + 1);
    }
};

int main(){
    MyQueue q(5);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(3);
    q.enqueue(9);
    cout<<"Dequeue : ";
    cout<<q.dequeue()<<" ";
    cout<<q.dequeue()<<" ";
    cout<<q.dequeue()<<" ";
    cout<<q.dequeue()<<"\n";
    q.enqueue(1);

    MyCircularQueue cq(5);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);
    cq.enqueue(3);
    cq.enqueue(9);
    cout<<"Dequeue : ";
    cout<<cq.dequeue()<<" ";
    cout<<cq.dequeue()<<" ";
    cout<<cq.dequeue()<<" ";
    cout<<cq.dequeue()<<" ";
    cq.enqueue(1);
    cout<<cq.dequeue()<<" ";
    cout<<cq.dequeue()<<"\n";

    return 0;
}