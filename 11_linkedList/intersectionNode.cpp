#include<iostream>
#include<unordered_set>
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
// Method 1:- Time complexity :O(m+n) Auxiliary space :O(m)
int intersection1(Node *head1,Node *head2){
    //step 1:create an empty hash set
    unordered_set<Node *> set;
    //step 2:traversing first list 
    Node *curr = head1;
    while(curr!=NULL){
        set.insert(curr);
        curr = curr->next;
    }
    //step 3:treversing second list and check for first-common node b/w 1st & 2nd list
    curr = head2;
    while(curr!=NULL){
        if(set.find(curr) != set.end())
            return curr->data;
        curr = curr->next;
    }
    return -1;
}
// Method 2:- Time complexity :O(m+n) Auxiliary space :O(1)
int intersection2(Node *head1,Node *head2){
    //step 1:traverse both linked list to count number of node in each
    int c1=0,c2=0;
    //first list treversel
    Node *curr1 = head1;
    while(curr1!=NULL){
        c1++;
        curr1 = curr1->next;
    }
    //second list treversel
    Node *curr2 = head2;
    while(curr2!=NULL){
        c2++;
        curr2 = curr2->next;
    }
    
    //step 2:treverse bigger list abs(c1-c2) times
    if(c1>c2){
        curr1 = head1;
        curr2 = head2;
        for(int i=0;i<(c1-c2);i++)
            curr1 = curr1->next;
    }
    else{
        curr1 = head1;
        curr2 = head2;
        for(int i=0;i<(c2-c1);i++)
            curr2 = curr2->next;
    }
    //step :treverse both list symultaneously
    while(curr1!=NULL && curr2!=NULL){
        if(curr1 == curr2)
            return curr1->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;


}
int main(){
    //creaction of first linked list : 
    Node *head1 = new Node(10);
    Node *t1 = new Node(8);
    Node *t2 = new Node(7);
    Node *t3 = new Node(10);
    Node *t4 = new Node(12);
    Node *t5 = new Node(15);

    head1->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    printList(head1);

    //creaction of second linked list : 
    Node *head2 = new Node(9);

    head2->next = t3;
    printList(head2);

    cout<<"First common node b/w List 1 and 2 is : "<<intersection1(head1,head2)<<endl;
    cout<<"First common node b/w List 1 and 2 is : "<<intersection2(head1,head2)<<endl;
    return 0;
}