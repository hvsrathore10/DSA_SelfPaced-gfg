//Complete Circular-Doubly LinkedList
#include<iostream>
using namespace std;
 
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        data = d;
        prev = NULL;
        next =  NULL;
    }
};


void printList(Node *head){
    if(head == NULL)
        return;
    Node *curr = head;
    do{
        cout<<curr->data<<" ";
        curr = curr->next; 
    }while(curr != head);
}
Node *insertAtBegin(Node *head,int data){
    Node *temp = new Node(data);
    if(head == NULL){
        temp->prev = temp;
        temp->next = temp;
        return temp;
    }
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return temp;
}
Node *insertAtEnd(Node *head,int data){
    Node *temp = new Node(data);
    if(head == NULL){
        temp->prev = temp;
        temp->next = temp;
        return temp;
    }
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return head;
}


int main(){
    Node *head = new Node(10); 
    Node *temp1 = new Node(20); 
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1; 
    temp2->next = head;
    head->prev = temp2;

    head = insertAtBegin(head,5);
    printList(head);
    head = insertAtEnd(head,40);
    printList(head);
    return 0;
}