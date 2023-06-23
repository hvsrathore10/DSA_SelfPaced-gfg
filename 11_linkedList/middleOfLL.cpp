// Description : Given a singly linked list, find the middle of the linked list. For example, if the given  
            // linked list is 1->2->3->4->5 then the output should be 3. 
            // If there are even nodes, then there would be two middle nodes, we need to print the second  
            // middle element. For example, if the given linked list is 1->2->3->4->5->6 then the output 
            // should be 4. 
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
//Naive Approach :- Time complexity : O(n) Auxiliary Space : O(1)
void middle(Node *head){
    if(head==NULL)
        return;
    int count = 0;
    Node *curr;
    for(curr=head;curr!=NULL;curr = curr->next)
        count++;
    
    curr = head;
    for(int i=0;i<count/2;i++)
        curr = curr->next;
    cout<<curr->data<<endl;
}
//Effiecent Approach :- Time complexity : O(n)
void printMiddle(Node *head){
    if(head == NULL)
        return;
    Node *slow,*fast;
    slow = head;
    fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data<<endl;
}
int main(){
    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    Node *t3 = new Node(40);
    Node *t4 = new Node(50);
    Node *t5 = new Node(60);

    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;

    middle(head);
    printMiddle(head);
    return 0;
}