//Problem : We are give a BST in which exactly two node are out of order,your task is to find and 
// fix BST by swapping the data of nodes.

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
}; 
void inorder(Node *root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//Method 1:- Time complexity :O(n) [but two traversal required] and Auxiliary space :O(H)
/*1.Generate an array of node in sorted order using inorder treversal
2.Using Two-pointer Approach swap data which are outoff order*/

//Method 2:- Time complexity :O(n) and Auxiliary space :O(H)
void fixBstUtility(Node *root,Node **prev,Node **first,Node **second){
    if(root==NULL)
        return;
    
    fixBstUtility(root->left,prev,first,second);

    if((*prev)!=NULL && root->data < (*prev)->data){
        if((*first)==NULL)
            *first = *prev;
        *second = root;
    }
    *prev = root;

    fixBstUtility(root->right,prev,first,second);
}
void fixBST(Node *root){
    Node *prev = NULL;
    Node *first = NULL;
    Node *second = NULL;

    fixBstUtility(root,&prev,&first,&second);

    //swaping :
    if(first!=NULL && second!=NULL){
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
    }
    cout<<"\nInorder Treversal After fixing BST : ";
    inorder(root);
}
int main(){
    Node *root = new Node(18);

    Node *t1 = new Node(60);    
    Node *t2 = new Node(70); 
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(4);    
    Node *t4 = new Node(10);    
    t1->left = t3;
    t1->right = t4;

    Node *t5 = new Node(8);
    Node *t6 = new Node(80);
    t2->left = t5;
    t2->right = t6;

    cout<<"Inorder Traversal : ";
    inorder(root);
    fixBST(root);
    return 0;
}