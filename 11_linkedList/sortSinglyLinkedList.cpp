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

//Iterative Traversal of Singly LinkedList
// Time complexity : ϴ(n) Auxiliary Space : ϴ(1) 
void printList(Node *head){
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}
//Time complexity : O(n)
Node *insertInSortedList(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL)
        return temp;
    if(head->data > x){
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while(curr->next!=NULL){
        if(curr->next->data > x){
            temp->next = curr->next;
            curr->next = temp;
            return head;
        }
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
int main(){
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->next = temp2;
    
    printList(head);
    head = insertInSortedList(head,35);
    printList(head);
    return 0;
}