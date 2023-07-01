#include<iostream>
#include<unordered_map>
using namespace std;
 
struct Node{
    int data;     //data --> information
    Node* next;  //next --> pointer to the next node
    Node *random_p;
    //constructor
    Node(int d){
        data = d;
        next = NULL;
        random_p = NULL;
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
//Method 1:- Time complexity :ϴ(n) & Auxiliary space :ϴ(n)
Node *cloneList(Node *head){
    if(head == NULL)
        return NULL;
    unordered_map<Node *,Node *> m;

    Node *curr = head;
    //creaction of clone linkedList
    while(curr!=NULL){
        m[curr] = new Node(curr->data);
        curr = curr->next;
    }
    //linking clone list
    curr = head;
    while(curr!=NULL){
        m[curr]->next = m[curr->next];
        m[curr]->random_p = m[curr->random_p];
        curr = curr->next;
    }
    return m[head];
}
//Method 2:- Time complexity :ϴ(n) & Auxiliary space :ϴ(1)
Node *cloneList2(Node *head){
    Node *curr = head;
    //step 1:creaction of clone list and insert next to curr
    while(curr!=NULL){
        Node *next = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = next;
        curr = next;
    }
    // step 2:
    for(Node *curr = head;curr!=NULL;curr = curr->next->next)
        curr->next->random_p = (curr->random_p==NULL)? NULL : curr->random_p->next;
    
    //step 3:
    Node *head2 = head->next;
    Node *clone = head2;
    for(Node *curr=head;curr!=NULL;curr = curr->next){
        curr->next = clone->next;
        clone->next = (clone->next)? clone->next->next : NULL;
        clone = clone->next;
    }
    return head2;
}
int main(){
    Node *head = new Node(10);
    Node *t1 = new Node(5);
    Node *t2 = new Node(20);
    Node *t3 = new Node(15);
    Node *t4 = new Node(25);
    //Normal link's
    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    //random link's
    head->random_p = t2;
    t1->random_p = t3;
    t2->random_p = head;
    t3->random_p = t2;
    t4->random_p = t3;

    printList(head);

    // Node *head2 = cloneList(head);
    // printList(head2);
    Node *head2 = cloneList2(head);
    printList(head2);
    return 0;
}