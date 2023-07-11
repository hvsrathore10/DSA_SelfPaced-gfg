#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
struct MyQueue{
    Node *front;
    Node *rear;
    int qSize;
    MyQueue(){
        front = NULL;
        rear = NULL;
        qSize = 0;
    }
    void enqueue(int x){
        Node *temp = new Node(x);
        if(front==NULL && rear==NULL)
            front = temp;
        else
            rear->next = temp;
        rear = temp;
        qSize++;
    }
    int dequeue(){
        if(front==NULL)
            return -1;
        int t = front->data;
        Node *temp = front;
        front = front->next;
        if(front==NULL) 
            rear = NULL;

        delete(temp);
        qSize--;
        return t;
    }
    Node *getFront(){
        return front;
    }
    Node *getRear(){
        return rear;
    }
    bool isEmpty(){
        if(front==NULL)
            return true;
        return false;
    }
    int size(){
        return qSize;
    }
    void display(){
        Node *curr = front;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }cout<<endl;
    }
};
int main(){
    MyQueue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    cout<<q.dequeue();
    q.enqueue(9);
    q.enqueue(10);
    cout<<q.dequeue();
    q.display();
    return 0;
}