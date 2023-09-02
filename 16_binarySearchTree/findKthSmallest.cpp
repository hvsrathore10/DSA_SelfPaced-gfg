#include<iostream>
using namespace std;

//Augmented binary search tree
struct Node{
    int data;
    Node *left,*right;
    int lcount; //<--- count of left children
    Node(int d){
        data = d;
        left = right = NULL;
        lcount = 0;
    }
};

Node *insert(Node *root,int key){
    if(root==NULL)
        return (new Node(key));
    
    if(root->data > key){
        root->lcount = root->lcount + 1;
        root->left = insert(root->left,key);
    }
    else if(root->data < key){
        root->right = insert(root->right,key);
    }

    return root;
}
Node *getSuccessor(Node *curr){
    if(curr==NULL)
        return NULL;

    curr = curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr = curr->left;
    
    return curr;
}
Node *delNode(Node *root,int key){
    if(root==NULL)
        return NULL;
    
    if(root->data > key){
        root->lcount = root->lcount - 1;
        root->left = delNode(root->left,key);
    }
    else if(root->data < key)
        root->right = delNode(root->right,key);
    else{
        if(root->left==NULL){
            Node *temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL){
            Node *temp = root->left;
            delete(root);
            return temp;
        }
        else{
            Node *succ = getSuccessor(root);
            root->data = succ->data;
            root->right = delNode(root->right,succ->data);
        }
    }
    return root;
}

//Naive Approach :- Time complexity :O(H+K) and Auxiliary space :O(H)
int countNodes = 0;
void findKth(Node *root,int k){
    if(root==NULL)
        return;
    
    findKth(root->left,k);

    countNodes++;
    if(countNodes == k){
        cout<<root->data<<endl;
        return;
    }
    
    findKth(root->right,k);
}

//Using Augmented-BST
//Efficient Approach :- Time complexity :O(H) and Auxiliary space :O(H)
void printKth(Node *root,int k){
    if(root==NULL)
        return;
    
    if(root->lcount+1 == k)
        cout<<root->data<<endl;
    else if(root->lcount+1 > k)
        printKth(root->left,k);
    else{
        k = k - root->lcount - 1;
        printKth(root->right,k);
    }
}
int main(){
    Node *root = NULL;

    root = insert(root,50);
    root = insert(root,20);
    root = insert(root,100);
    root = insert(root,10);
    root = insert(root,40);
    root = insert(root,70);
    root = insert(root,120);
    root = insert(root,4);
    root = insert(root,60);
    root = insert(root,80);

    int k = 7;
    cout<<k<<" Smallest Element in BST : ";
    findKth(root,k);
    cout<<k<<" Smallest Element in BST : (using Efficient Method) ";
    printKth(root,k);
    return 0;
}