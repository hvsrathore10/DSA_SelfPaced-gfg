// Problem: Given a Binary Tree. The task is to print the nodes of the binary tree 
// when viewed from different sides. That is, the left view of the binary tree will 
// contain only those nodes which can be seen when the Binary tree is viewed from left.
#include<iostream>
#include<queue>
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
//Recursive Approach :- Time complexity : O(n) and Auxiliary space : O(h)
int maxLevel = 0;
void leftView(Node *root,int level){
    if(root==NULL) 
        return;
    if(maxLevel<level){
        cout<<root->data<<" ";
        maxLevel = level;
    }
    leftView(root->left,level+1);
    leftView(root->right,level+1);
}
//Iterative Solution :- Time complexity : O(n) and Auxiliary space : O(1)
void leftViewI(Node *root){
    if(root == NULL)  
        return;
    
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
       int count = q.size();
       for(int i=0;i<count;i++){
        Node *curr = q.front();
        q.pop();
        //print only first node of every level
        if(i==0)    
            cout<<curr->data<<" ";

        if(curr->left != NULL) 
            q.push(curr->left);
        if(curr->right != NULL)
            q.push(curr->right);
       }
    }
}
//Iterative Approach :- Time complexity:O(n) and Ausiliary space:O(nL)
void rightView(Node *root){
    if(root == NULL)  
        return;
    
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
       int count = q.size();
       for(int i=0;i<count;i++){
        Node *curr = q.front();
        q.pop();
        //print only first node of every level
        if(i==count-1)    
            cout<<curr->data<<" ";

        if(curr->left != NULL) 
            q.push(curr->left);
        if(curr->right != NULL)
            q.push(curr->right);
       }
    }
}
//Recursive Approach :- Time complexity : O(n) and Auxiliary space : O(h)
void bottomView(Node *root){
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL)
        cout<<root->data<<" ";
    else{
        bottomView(root->left);
        bottomView(root->right);
    }
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

    // leftView(root,1);
    cout<<"Left View : ";
    leftViewI(root);
    cout<<"\nRight View : ";
    rightView(root);
    cout<<"\nBottom View : ";
    bottomView(root);
    
    return 0;
}