#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    //constructor 
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
//Time complexity : O(㏒N) & Auxiliary space : O(㏒N) -->Function call stack
Node *lca(Node *root,int n1,int n2){
    if(root==NULL)
        return NULL;

    //if root->data>n1 and root->data<n2 => root is the lca
    if(root->data>n1 && root->data<n2)
        return root;
    //root->data>n1 and root->data>n2 => lca is present in left subtree
    else if(root->data>n1 && root->data>n2)
        return lca(root->left,n1,n2);
    //root->data<n1 and root->data<n2 => lca is present in right subtree
    else
        return lca(root->right,n1,n2);
}
int main(){
    Node *root = new Node(50);

    Node *t1 = new Node(30);
    Node *t2 = new Node(70);
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(10);
    Node *t4 = new Node(40);
    t1->left = t3;
    t1->right = t4;

    Node *t5 = new Node(60);
    Node *t6 = new Node(80);
    t2->left = t5;
    t2->right = t6;

    int n1 = 10,n2 = 40;

    //assumption : Both n1 & n2 are present in BST and n1<n2
    Node *res = lca(root,n1,n2);
    if(res!=NULL)
        cout<<"Lowest Comman Ancestor of "<<n1<<" & "<<n2<<" is : "<<res->data<<endl;
    else 
        cout<<"Lowest Comman Ancestor Not Found"<<endl;
    return 0;
}