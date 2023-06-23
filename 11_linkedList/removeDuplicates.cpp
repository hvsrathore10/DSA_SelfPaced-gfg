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


Node *createList(Node *head);
Node *insertAtBegin(Node *head,int data);
Node *insertAtEnd(Node *head,int data);
void printList(Node *head);

//Time comlexity : O(n)
void removeDuplicates(Node *head){
    if(head==NULL || head->next==NULL)
        return;

    Node *curr = head;
    while(curr->next!=NULL){
        if(curr->data == curr->next->data){
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }
        else
            curr = curr->next;
    }
}

int main(){
    Node *head = NULL;
    head = createList(head);

    printList(head);
    removeDuplicates(head);
    printList(head);
    return 0;
}

void printList(Node *head){
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}
//Time complexity : O(n)
Node *createList(Node *head){
    int n,data;
    cout<<"Enter number of NODE's required :";
    cin>>n;

    cout<<"Enter information for node : ";
    cin>>data;
    head = insertAtBegin(head,data);
    for(int i=2;i<=n;i++){
        cout<<"Enter information for node : ";
        cin>>data;
        head = insertAtEnd(head,data);
    }
    return head;
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
