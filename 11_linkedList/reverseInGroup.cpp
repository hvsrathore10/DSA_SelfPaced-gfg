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

//Recursive Solution 
//Time complexity : O(n) & Auxiliary Space : O(n/k)
Node *reverseInGroup(Node *head,int k){
    if(head==NULL)
        return NULL;

    Node *curr = head;
    int count = 0;
    Node *prev=NULL,*next=NULL;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    head->next = reverseInGroup(next,k);
    return prev;
}
//Iterative Solution 
//Time complexity : O(n) & Auxiliary Space : O(1)
Node *reverseKth(Node *head,int k){
    if(head==NULL || head->next==NULL)
        return head;
    
    Node *curr = head,*prevFirst = head;
    bool isFirstPass = true;
    while(curr != NULL){
        Node *first = curr,*prev = NULL;
        int count = 0;
        while(curr!=NULL && count<k){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(isFirstPass){
            head = prev;
            isFirstPass = false;
        }
        else{
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}

int main(){
    Node *head = NULL;
    head = createList(head);

    printList(head);
    // head = reverseInGroup(head,3);
    head = reverseKth(head,3);
    printList(head);
    return 0;
}


//Time complexity : O(n)
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