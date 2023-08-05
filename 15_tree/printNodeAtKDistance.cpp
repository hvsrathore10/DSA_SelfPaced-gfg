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
//Time complexity : O(n) and Auxiliary space :O(nL)  nL = no. of node at level L
void printNode(Node *root,int k){
    if(root == NULL)
        return;
    if(k==0)
        cout<<root->data<<" ";
    printNode(root->left,k-1);
    printNode(root->right,k-1);
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

    printNode(root,3);
    return 0;
}