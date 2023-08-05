// Tree traversal :- Breadth First or Depth First
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

//Inorder Traversal :- [left root right]
//Time complexity :ϴ(n) and Auxiliary space :ϴ(h) h-->height of tree 
//                          {for skewed tree O(n) and or balanced tree O(㏒n)}
void inorder(Node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);        
}
//Preorder Traversal :- [root left right]
//Time complexity :ϴ(n) and Auxiliary space :ϴ(h)
void preorder(Node *root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);        
}
//Postorder Traversal :- [left right root]
//Time complexity :ϴ(n) and Auxiliary space :ϴ(h)
void postorder(Node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);        
    cout<<root->data<<" ";
}

//Function To Find height of Binary Tree
// Time complrxity :O(n) and Auxiliary space :O(h)
int height(Node *root){
    //If we have empty tree or we are at leaf node
    if(root == NULL) 
        return 0;

    return (max(height(root->left),height(root->right))+1);
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

    cout<<"Height of Tree : "<<height(root)<<endl;
    cout<<"\nInorder Treversal : ";
    inorder(root);

    cout<<"\nPreorder Treversal : ";
    preorder(root);

    cout<<"\nPostorder Treversal : ";
    postorder(root);

    return 0;
}