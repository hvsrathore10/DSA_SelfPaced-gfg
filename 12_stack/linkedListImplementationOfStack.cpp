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
struct MyStack{
    Node *head;
    int sz;
    MyStack(){
        head = NULL;
        sz = 0;
    }

    void push(int x){
        sz++;
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
    }
    int pop(){
        if(head==NULL){
            cout<<"Stack Underflow"<<endl;
            return INT_MAX;
        }
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete(temp);
        sz--;
        return res;
    }
    int peek(){
        if(head==NULL){
            cout<<"Stack Underflow"<<endl;
            return INT_MAX;
        }
        return head->data;
    }
    int size(){
        return sz;
    }
    bool isEmpty(){
        if(head==NULL)
            return true;
        return false;
    }
};
int main(){
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout<<s.peek()<<endl;
    cout<<s.pop()<<" is poped from stack"<<endl;
    cout<<s.peek()<<endl;
    cout<<(s.isEmpty()? "True":"False")<<endl;
    cout<<s.size()<<endl;
    return 0;
}