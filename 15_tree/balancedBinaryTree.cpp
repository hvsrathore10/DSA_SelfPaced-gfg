// In a Balanced Binary Tree for every node, the difference between heights of left subtree 
// and right subtree should not be more than one.
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
// Time complrxity :O(n) and Auxiliary space :O(h)
int height(Node *root){
    //If we have empty tree or we are at leaf node
    if(root == NULL) 
        return 0;

    return (max(height(root->left),height(root->right))+1);
}
//Naive Approach :- Time complrxity :O(n²) and Auxiliary space :O(h)
bool isBal(Node *root){
    if(root == NULL) 
        return true;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    return (abs(lh-rh)<=1 && isBal(root->left) && isBal(root->right));
}

//Efficent Approach :- Time complrxity :O(n) and Auxiliary space :O(h)
int isBalanced(Node *root){
    if(root==NULL) 
        return 0;
    
    //check for left-subtree 
    //Also get height of left-subtree
    int lh = isBalanced(root->left);
    if(lh == -1) return -1;

    //check for right-subtree 
    //Also get height of right-subtree
    int rh = isBalanced(root->right);
    if(rh == -1) return -1;

    //check for current-node
    if(abs(lh-rh)>1) 
        return -1;
    else
        return (max(lh,rh)+1);

}
int main(){
    Node *root = new Node(30);

    Node *t1 = new Node(40);
    Node *t2 = new Node(80);
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(50);
    Node *t4 = new Node(70);
    t1->left = t3;
    t1->right = t4;

    Node *t5 = new Node(5);
    t2->left = t5;

    Node *t6 = new Node(20);
    Node *t7 = new Node(10);
    t4->left = t6;
    t4->right = t7;

    if(isBalanced(root) == -1)
        cout<<"Binary Tree is Not-Balanced"<<endl;
    else
        cout<<"Binary Tree is Balanced"<<endl;
        
    cout<<(isBal(root)? "True":"False")<<endl;
    return 0;
}