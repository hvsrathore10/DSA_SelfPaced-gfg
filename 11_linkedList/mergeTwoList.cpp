// A O(m+n) time and O(1) auxiliary space solution.
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

void display(Node *head){
    if(head==NULL){
        cout<<"List is Empty!"<<endl;
        return;
    }
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}

//Time complexity :O(m+n) Auxiliary space :O(1)
Node *merge(Node *a,Node *b){
    if(a==NULL) return b;
    if(b==NULL) return a;

    Node *head = NULL,*tail = NULL;
    if(a->data <= b->data){
        head = tail = a;
        a = a->next;
    }
    else{
        head = tail = b;
        b = b->next;
    }

    while(a!=NULL && b!=NULL){
        if(a->data < b->data){
            tail->next = a;
            a = a->next;
            tail = tail->next;
        }
        else{
            tail->next = b;
            b = b->next;
            tail = tail->next;
        }
    }
    if(a==NULL) 
        tail->next = b;
    else 
        tail->next = a;
    return head;
}


int main(){
    Node *a = new Node(10);
    Node *at1 = new Node(20);
    Node *at2 = new Node(30);
    Node *at3 = new Node(40);

    a->next = at1;
    at1->next = at2;
    at2->next = at3;
    cout<<"List a : "<<endl;
    display(a);

    Node *b = new Node(5);
    Node *bt1 = new Node(15);
    Node *bt2 = new Node(17);
    Node *bt3 = new Node(18);
    Node *bt4 = new Node(35);

    b->next = bt1;
    bt1->next = bt2;
    bt2->next = bt3;
    bt3->next = bt4;
    cout<<"List b : "<<endl;
    display(b); 

    Node *head = merge(a,b);
    cout<<"Merged List : "<<endl;
    display(head);

    return 0;
}