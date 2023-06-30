#include<iostream>
using namespace std;
 
struct Node{
    int data;     //data --> information
    Node* next;  //next --> pointer to the next node
    //constructor
    Node(int d){
        data = d;
        next = NULL;
    }
};

bool isLoop(Node *head){
    Node *slow_p = head;
    Node *fast_p = head;
    while(fast_p!=NULL && fast_p->next!=NULL){
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if(slow_p == fast_p)
            return true;
    }
    return false;
}

int main(){
    Node *head = new Node(10);
    Node *t1 = new Node(15);
    Node *t2 = new Node(12);
    Node *t3 = new Node(4);
    Node *t4 = new Node(20);

    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t2;
    
    cout<<isLoop(head)<<endl;
    return 0;
}