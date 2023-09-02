#include<iostream>
using namespace std;
 
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void inorderTraversal(Node *root){
    if(root==NULL)
        return;
    
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
//Time complexity :O(㏒N) and Auxiliary space :O(㏒N)
Node *insertNode(Node *root,int x){
    if(root==NULL)
        return new Node(x);
    
    if(root->data > x)
        root->left = insertNode(root->left,x);
    else if(root->data < x)
        root->right = insertNode(root->right,x);
    
    return root;
}
//Time complexity :O(㏒N) and Auxiliary space :O(㏒N)
bool searchNode(Node *root,int item){
    if(root==NULL)
        return false;
    
    if(root->data == item)
        return true;
    else if(root->data>item)
        return searchNode(root->left,item);
    else
        return searchNode(root->right,item);
}
int main(){
    Node *root = new Node(50);

    Node *t1 = new Node(20);
    Node *t2 = new Node(70);
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(15);
    Node *t4 = new Node(40);
    t1->left = t3;
    t1->right = t4;

    Node *t5 = new Node(60);
    Node *t6 = new Node(80);
    t2->left = t5;
    t2->right = t6;

    inorderTraversal(root);
    root = insertNode(root,35);

    cout<<endl;
    inorderTraversal(root);
    cout<<"\nSearch Node with value=40 : "<<(searchNode(root,40)?"Found":"Not-Found")<<endl;
    return 0;
}