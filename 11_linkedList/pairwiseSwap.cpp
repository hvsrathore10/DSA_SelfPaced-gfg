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
// Naive Method :-Time complexity :O(n) but swapping data
Node *pairwiseSwapNaive(Node *head){
    Node *curr = head;
    while(curr!=NULL && curr->next!=NULL){
        swap(curr->data,curr->next->data);
        curr = curr->next->next;
    }
    return head;
}
// Efficient Method :- Time complexity :O(n) but changing Pointer
Node *pairwiseSwap(Node *head){
    if(head==NULL || head->next==NULL)
        return head;

    Node *prev = head;
    Node *curr = head->next->next;
    //first two node will be handle here
    head = head->next;
    head->next = prev;
    //rest nodes will be handle here
    while(curr!=NULL && curr->next!=NULL){
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;  //handles both even and odd nodes
    return head;
}

int main(){
    Node *head = new Node(1);
    Node *t1 = new Node(2);
    Node *t2 = new Node(3);
    Node *t3 = new Node(4);
    Node *t4 = new Node(5);
    Node *t5 = new Node(6);

    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    printList(head);
    head = pairwiseSwap(head);
    printList(head);
    return 0;
}