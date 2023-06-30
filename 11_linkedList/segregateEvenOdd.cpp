// Description : Given a Linked List of integers, write a function to modify the linked list 
// such that all even numbers appear before all the odd numbers in the modified linked list. Also, 
// keep the order of even and odd numbers the same.
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

Node *segregate(Node *head){
    Node *evenStart=NULL,*evenEnd=NULL,*oddStart=NULL,*oddEnd=NULL;
    for(Node *curr=head;curr!=NULL;curr = curr->next){
        int x = curr->data;
        if(x%2 == 0){
            if(evenStart==NULL){
                evenStart = curr;
                evenEnd = evenStart;
            }
            else{
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        }
        else{
            if(oddStart==NULL){
                oddStart = curr;
                oddEnd = oddStart;
            }
            else{
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
    }
    if(oddStart==NULL || evenStart==NULL){
        return head;
    }
    evenEnd->next = oddStart;
    oddEnd->next = NULL;
    return evenStart;
}
int main(){
    Node *head = new Node(17);
    Node *t1 = new Node(15);
    Node *t2 = new Node(8);
    Node *t3 = new Node(12);
    Node *t4 = new Node(5);

    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;

    printList(head);
    head = segregate(head);
    printList(head);
    return 0;
}