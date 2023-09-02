#include<iostream>
#include<map>
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

Node *getSuccessor(Node *curr){
    curr = curr->right;
    //find leftmost child in right subtree
    while(curr!=NULL && curr->left!=NULL)
        curr = curr->left;
    return curr;
}
//Time complexity :O(H) ==> (H - ㏒N )
Node *delNode(Node *root,int item){
    //base case :
    if(root==NULL)
        return root;
    
    if(root->data > item)
        root->left = delNode(root->left,item);
    else if(root->data < item)
        root->right = delNode(root->right,item);
    else{
        //root having only one child or no child
        if(root->left==NULL){
            Node *temp = root->right;
            delete(root);
            return temp;
        }
        //root having only left child
        else if(root->right==NULL){
            Node *temp = root->left;
            delete(root);
            return temp;
        }
        //if root having both children
        else{
            Node *succ = getSuccessor(root);
            root->data = succ->data;
            root->right = delNode(root->right,succ->data);
        }
    }
    return root;
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

    cout<<"BST before Deletion : ";
    inorderTraversal(root);
    root = delNode(root,50);
    cout<<"\nBST after Deletion of '50' : ";
    inorderTraversal(root);
    return 0;
}