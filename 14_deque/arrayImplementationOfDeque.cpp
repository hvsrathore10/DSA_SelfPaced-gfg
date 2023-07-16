#include<iostream>
using namespace std;

//Simple Implementation :-
//Time complexity : insertFront/deleteFront - O(n) and insertRead/deleteRear - O(1)
struct MyDeque1{
    int *arr;
    int cap,SIZE;
    MyDeque1(int capacity){
        cap = capacity;
        arr = new int[cap];
        SIZE = 0;
    }
    //Time comlexity of insertFront() :-O(n)
    void insertFront(int x){
        if(isFull()) return;
        //transfer all item 1 head
        for(int i=SIZE-1;i>=0;i--)
            arr[i+1] = arr[i];
        arr[0] = x;
        SIZE++;
    }
    void insertRear(int x){
        if(isFull()) return;
        arr[SIZE] = x;
        SIZE++;
    }
    //Time comlexity of deleteFront() :-O(n)
    int deleteFront(){
        if(isEmpty()) return -1;
        int res = arr[0];
        //transfer every item 1 backward
        for(int i=0;i<SIZE;i++)
            arr[i]  = arr[i+1];
        SIZE--;
        return res;
    }
    int deleteRear(){
        if(isEmpty()) return -1;
        int res = arr[SIZE-1];
        SIZE--;
        return res;
    }
    bool isFull(){
        if(SIZE==cap) 
            return true;
        return false;
    }
    bool isEmpty(){
        if(SIZE==0)
            return true;
        return false;
    }
    int size(){
        return SIZE;
    }
};
//Efficient implementation :-
//Time complexity :- O(1) for all function's 
struct MyDeque{
    int *arr;
    int cap;
    int front,SIZE;
    MyDeque(int capacity){
        cap = capacity;
        front = 0;
        SIZE = 0;
        arr = new int[cap];
    }
    void insertFront(int x){
        if(isFull()) return;
        front = (front-1+cap)%cap;
        arr[front] = x;
        SIZE++;
    }
    void insertRear(int x){
        if(isFull()) return;
        int rear = (getRear()+1)%cap;
        arr[rear] = x;
        SIZE++;
    }
    int deleteFront(){
        if(isEmpty()) return -1;
        int res = arr[front];
        front = (front+1)%cap;
        SIZE--;
        return res;
    }
    int deleteRear(){
        if(isEmpty()) return -1;
        int rear = getRear();
        int res = arr[rear];
        SIZE--;
        return res;
    }
    bool isFull(){
        if(SIZE==cap) 
            return true;
        return false;
    }
    bool isEmpty(){
        if(SIZE==0)
            return true;
        return false;
    }
    int size(){
        return SIZE;
    }
    int getRear(){
        if(isEmpty()) return -1;
        else return (front+SIZE-1)%cap;
    }
};

int main(){
    MyDeque dq(5);
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