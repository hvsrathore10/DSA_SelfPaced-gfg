#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    bool leftThread;
    bool rightThread;
    Node(int key){
        data = key;
        left = right = NULL;
        leftThread = rightThread = false;
    }
};

Node *leftMost(Node *N){
    if(N == NULL)
        return NULL;

    while(N->left!=NULL){
        if(N->leftThread)
            return N;
        N = N->left;
    }

    return N;
}
Node *rightMost(Node *N){
    if(N == NULL)
        return NULL;

    while(N->right!=NULL){
        if(N->rightThread)
            return N;
        N = N->right;
    }

    return N;
}
void inorder(Node *root){
    if(root==NULL)
        return;

    Node *curr = leftMost(root);
    while(curr!=NULL){
        cout<<curr->data<<" ";
        
        if(curr->rightThread)
            curr = curr->right;
        else
            curr = leftMost(curr->right);
    }
}
void reverseInorder(Node *root){
    if(root==NULL)
        return;
    
    Node *curr = rightMost(root);
    while(curr!=NULL){
        cout<<curr->data<<" ";
        if(curr->leftThread)
            curr = curr->left;
        else
            curr = rightMost(curr->left);
    }
}

int main(){
    Node *root = new Node(10);

    //left & right child of 'root = 10'
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    root->left = t1;
    root->right = t2;

    //left & right child of "node=20"
    Node *t3 = new Node(40);
    Node *t4 = new Node(50);
    t1->left = t3;
    t1->right = t4;

    t3->rightThread = true;
    t3->right = t1;

    t4->leftThread = true;
    t4->left = t1;
    t4->rightThread = true;
    t4->right = root;

    //left & right child of "node=30"
    Node *t5 = new Node(60);
    Node *t6 = new Node(70);
    t2->left = t5;
    t2->right = t6;

    t5->leftThread = true;
    t5->left = root;
    t5->rightThread = true;
    t5->right = t2;

    t6->leftThread = true;
    t6->left = t2;

    cout<<"Inorder Traversal : ";
    inorder(root);
    cout<<"\nReverse Inorder Traversal : ";
    reverseInorder(root);
    return 0;
}