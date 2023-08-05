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

bool checkProperty(Node *root){
    if(root == NULL) 
        return true;
    //base case for leaf-nodes
    if(root->left==NULL && root->right==NULL)
        return true;

    int sum = 0;
    if(root->left!=NULL) sum += root->left->data;
    if(root->right!=NULL) sum += root->right->data;

    return ((root->data == sum) && 
            checkProperty(root->left) && checkProperty(root->right));

}
int main(){
    Node *root = new Node(20);

    Node *t1 = new Node(8);
    Node *t2 = new Node(12);
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(3);
    Node *t4 = new Node(5);
    t1->left = t3;
    t1->right = t4;
     cout<<checkProperty(root);
    return 0;
}