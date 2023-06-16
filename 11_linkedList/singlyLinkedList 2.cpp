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

void printListI(Node *head);
void printListR(Node *head);
Node *insertAtBegin(Node *head,int data);
Node *insertAtEnd(Node *head,int data);
Node *delHead(Node *head);
Node *delTail(Node *head);


int main(){
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *forth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = forth;

    head = insertAtBegin(head,5);
    head = insertAtEnd(head,50);

    printListI(head);
    // printListR(head);

    head = delHead(head);
    printListI(head);

    head = delTail(head);
    printListI(head);

    return 0;
}


//Iterative Traversal of Singly LinkedList
// Time complexity : ϴ(n) Auxiliary Space : ϴ(1) 
void printListI(Node *head){
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
// Recursive Traversal of Singly LinkedList
// Time complexity : ϴ(n) Auxiliary Space : ϴ(n) 
void printListR(Node *head){
    if(head == NULL)
        return;
    cout<<head->data<<" ";
    head = head->next;
    printListR(head);
}
// Time complexity : ϴ(1)
Node *insertAtBegin(Node *head,int data){
    Node *newHead = new Node(data);
    newHead->next = head;

    return newHead;
}
//Time complexity : O(n)
Node *insertAtEnd(Node *head,int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        return newNode;
    }
    Node *p = head;
    while(p->next != NULL)
        p = p->next;
    
    p->next = newNode;
    return head;
}
// Time complexity : O(1)
Node *delHead(Node *head){
    if(head == NULL)
        return NULL;
    
    Node *temp = head->next;
    //In C++ programmer have to deallocation memory 
    // where as in JAVA deallocation will be done by compiler
    delete(head);
    return temp;
}
//Time complexity : O(n)
Node *delTail(Node *head){
    //if list is Empty
    if(head == NULL)
        return NULL;
    //if list have head as only node
    if(head->next == NULL){
        delete(head);
        return NULL;
    }

    Node *p = head;
    while(p->next->next != NULL)
        p = p->next;
        
    delete(p->next);
    p->next = NULL;
    return head;
}