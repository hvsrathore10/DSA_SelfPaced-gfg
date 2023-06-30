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

//Iterative Traversal of Singly LinkedList
// Time complexity : ϴ(n) Auxiliary Space : ϴ(1) 
void printList(Node *head){
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}

void removeLoop(Node *head){
    Node *slow_p = head;
    Node *fast_p = head;
    //detect loop 
    while(fast_p!=NULL && fast_p->next!=NULL){
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if(slow_p == fast_p)
            break;
    }
    if(slow_p!=fast_p)
        return;

    //remove loop
    slow_p = head;
    while(slow_p->next != fast_p->next){
        slow_p = slow_p->next;
        fast_p = fast_p->next;
    }
    fast_p->next = NULL;
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
    t4->next = t1;

    removeLoop(head);
    printList(head);
    return 0;
}