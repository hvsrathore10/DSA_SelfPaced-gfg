// Question : Why have we taken a pointer that points to the last node instead of first node?
// Answer : For insertion of node in the beginning we need to traverse the whole list. Also, 
// for insertion at the end, the whole list has to be traversed. If instead of start pointer 
// we take a pointer to the last node then in both the cases there won’t be any need to traverse 
// the whole list. So, insertion in the beginning or at the end takes constant time irrespective 
// of the length of the list.

//Note : As be discuss insert at begin/end in constant time with head-node in circularLinkedList.cpp file but 
//this is better the that one ∵ using head-node we use swapping data tech. but if be have large object 
//as data of linked list then it will not work well but this is not the case in last-node tech.

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

//Time complexity : ϴ(n)
void printList(Node *last){
    if(last == NULL)
        return;

    Node *curr = last->next;
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr!=last);
    cout<<endl;
}
//Time complexity : O(1)
Node *insertAtBegin(Node *last,int data){
    Node *temp = new Node(data);

    if(last == NULL){
        temp->next = temp;
        return temp;
    }
    else{
        temp->next = last->next;
        last->next = temp;
        return last;
    }
}
//Time complexity : O(1)
Node *insertAtEnd(Node *last,int data){
    Node *temp = new Node(data);

    if(last == NULL)
        temp->next = temp;
    else{
        temp->next = last->next;
        last->next = temp;
    }
    return temp;
}

int main(){
    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    Node *t3 = new Node(40);
    Node *t4 = new Node(50);
    Node *last = new Node(60);

    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = last;
    last->next = head;
    printList(last);
    last = insertAtBegin(last,5);
    printList(last);
    last = insertAtEnd(last,70);
    printList(last);

    return 0;
}