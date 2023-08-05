// A function that takes root of a Binary Tree and converts it into a Doubly linked list.
// Hint:- we need to do the inorder traversal of the Tree and while doing inorder traversal 
// we can simply maintain a previous pointer or reference of the previously traversed node.
// And change right child of the previous node to current node and left child of current node as previous.
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int key){
        data = key;
        left = right = NULL;
    }
};
void printList(Node *head){
    if(head==NULL) return;
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->right;
    }cout<<endl;
}
Node *convert(Node *root){
    if(root==NULL) return root;

    static Node *prev = NULL;
    Node *head = convert(root->left);
    if(prev == NULL) 
        head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    convert(root->right);
    return head;
}
int main(){
    Node *root = new Node(10);

    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(40);
    Node *t4 = new Node(50);
    t1->left = t3;
    t1->right = t4;

    Node *t5 = new Node(60);
    t2->right = t5;

    Node *t6 = new Node(70);
    Node *t7 = new Node(80);
    t4->left = t6;
    t4->right = t7;

    Node *head = convert(root);
    printList(head);
    return 0;
}