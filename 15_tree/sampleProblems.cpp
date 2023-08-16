#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    int hd;
    Node(int key){
        data = key;
        left = right = NULL;
        hd = 0;
    }
};
void preorderTraversal(Node *root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
// Problem 1: Given a Binary Tree and a Key. The task is to insert the key into the binary 
// tree at first position available in level order.
void insert(Node *root,int key){
    Node *temp = new Node(key);
    if(root==NULL){
        root = temp;
        return;
    }
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        //if left child NULL
        if(curr->left!=NULL)    
            q.push(curr->left);
        else{
            curr->left = temp;
            break;
        }
        //if right child NULL
        if(curr->right!=NULL)   
            q.push(curr->right);
        else{
            curr->right = temp;
            break;
        }
    }
}

// Problem 2: Given a Binary Tree and a node to be deleted from this tree. 
// The task is to delete the given node from it.
void deleteDeepest(Node *root,Node *d_node){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();

        if(curr->right!=NULL){
            if(curr->right == d_node){
                curr->right = NULL;
                delete(d_node);
                return;
            }
            else
                q.push(curr->right);
        }
        if(curr->left!=NULL){
            if(curr->left == d_node){
                curr->left = NULL;
                delete(d_node);
                return;
            }
            else
                q.push(curr->left);
        }
    }
}
void deleteNode(Node *root,int item){
    if(root==NULL)
        return;
    
    queue<Node *> q;
    q.push(root);

    Node *temp;
    Node *key_Node;
    
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->data == item)
            key_Node = temp;
        
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }

    int x = temp->data;
    deleteDeepest(root,temp);
    key_Node->data = x;
}
// Problem 3: Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children 
// of all non-leaf nodes interchanged.Trees in the below figure are mirror of each other.
void mirrorTree(Node *root){
    if(root==NULL)
        return;
    
    mirrorTree(root->left);
    mirrorTree(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
//Problem 4: Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
// Given a binary tree, print the top view of it. The output nodes can be printed in any order. 
// Expected time complexity is O(n)
void topView(Node *root){
    //base case
    if(root==NULL)
        return;

    map<int,int> m;
    queue<Node *> q;

    int hd = 0; //hd = horizontal distance 
    root->hd = hd;

    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();       
        q.pop();
        hd = curr->hd;

        if(m.find(hd) == m.end())
            m[hd] = curr->data;
        
        if(curr->left!=NULL){
            curr->left->hd = hd - 1;
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            curr->right->hd = hd + 1;
            q.push(curr->right);
        }
    }

    map<int,int>::iterator it;
    for(it = m.begin();it != m.end();it++){
        cout<<it->second<<" ";
    }
    cout<<endl;
}
int main(){
    Node *root = new Node(1);

    Node *t1 = new Node(2);
    Node *t2 = new Node(3);
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(4);
    Node *t4 = new Node(5);
    t1->left = t3;
    t1->right = t4;

    Node *t5 = new Node(6);
    Node *t6 = new Node(7);
    t2->left = t5;
    t2->right = t6;

    // cout<<"Main tree : ";
    // preorderTraversal(root);

    // cout<<"\nAfter inserting new key = 40 : ";
    // insert(root,40);
    // preorderTraversal(root);

    // cout<<"\nAfter deleting key = 40 : ";
    // deleteNode(root,40);
    // preorderTraversal(root);

    // cout<<"\nMirror Image of tree : ";
    // mirrorTree(root);
    // preorderTraversal(root);

    cout<<"\nTop View : ";
    topView(root);

    return 0;
}