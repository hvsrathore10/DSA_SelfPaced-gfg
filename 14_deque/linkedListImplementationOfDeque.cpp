#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};
struct MyDeque{
    Node *front;
    Node *rear;
    int SIZE;
    MyDeque(){
        front = NULL;
        rear = NULL;
        SIZE = 0;
    }
    void insertFront(int x){
        SIZE++;
        Node *temp = new Node(x);
        if(front==NULL && rear==NULL){
            front = temp;
            rear = temp;
            return;
        }
        front->prev = temp;
        temp->next = front;
        front = temp;
    }
    void insertRear(int x){
        SIZE++;
        Node *temp = new Node(x);
        if(front==NULL && rear==NULL){
            front = temp;
            rear = temp;
            return;
        }
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
    int deleteFront(){
        if(front==NULL) 
            return -1;

        int res = front->data;
        Node *temp = front;
        front = front->next;
        //if front is the only node of list[DEQUE]
        if(front==NULL) 
            rear = NULL;
        else 
            front->prev = NULL;
            
        delete(temp);
        SIZE--;
        return res;
    }
    int deleteRear(){
        if(front==NULL) 
            return -1;

        int res = rear->data;
        Node *temp = rear;
        rear = rear->prev;
    //if rear is the only node of list[DEQUE]
        if(rear==NULL) 
            front = NULL;
        else    
            rear->next = NULL;

        delete(temp);
        SIZE--;
        return res;
    }
    int size(){
        return SIZE;
    }
    bool isEmpty(){
        if(front==NULL) 
            return true;
        return false;
    }
};
int main(){
    MyDeque dq;
    dq.insertFront(10);
    dq.insertFront(20);
    dq.insertRear(30);
    dq.insertRear(40);
    dq.insertFront(50);
    cout<<dq.deleteFront()<<" ";
    cout<<dq.deleteRear()<<" ";
    cout<<dq.size()<<endl;

    return 0;
}