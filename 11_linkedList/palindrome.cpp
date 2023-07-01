#include<iostream>
#include<stack>
using namespace std;
 
struct Node{
    char data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void display(Node *head){
    if(head==NULL){
        cout<<"List is Empty!"<<endl;
        return;
    }
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}
//Naive Approach:- Time complexity:O(n) & Auxiliary space:O(n) using Stack
bool isPalindromeNaive(Node *head){
    stack<char> st;
    Node *curr = head;
    while(curr!=NULL){
        st.push(curr->data);
        curr = curr->next;
    }
    curr = head;
    while(curr!=NULL){
        if(st.top() != curr->data)
            return false;
        st.pop();
        curr = curr->next;
    }
    return true;
}
Node *reverseList(Node *head){
    //if head is null or head is only node
    if(head == NULL || head->next == NULL)
        return head;

    Node *rest_head=reverseList(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}
//Efficient Approach:- Time complexity:O(n) & Auxiliary space:O(1)
bool isPalindrome(Node *head){
    if(head == NULL)
        return true;

    Node *slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *curr = head;
    Node *rev = reverseList(slow->next);
    while(rev!=NULL){
        if(curr->data != rev->data)
            return false;
        curr = curr->next;
        rev = rev->next;
    }
    return true;
}
int main(){
    Node *head = new Node('g');
    Node *t1 = new Node('e');
    Node *t2 = new Node('e');
    Node *t3 = new Node('k');
    Node *t4 = new Node('s');

    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    cout<<"Linked List : ";
    display(head);
    cout<<(isPalindrome(head)? "True":"False")<<endl;
    return 0;
}