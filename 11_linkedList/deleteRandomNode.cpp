// Question : This is one of the tricky problem asked in an interview where a random address to a 
// node of the linked list is given and the user needs to delete the node of the given address. 
// The address can point to any random node in-between a linked list.

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
//Time complexity : O(1)
void deleteNode(Node *ptr){
    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete(temp);
}

int main(){
    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    Node *t3 = new Node(40);
    Node *t4 = new Node(50);

    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;

    printList(head);
    deleteNode(t2);
    printList(head);

    return 0;
}