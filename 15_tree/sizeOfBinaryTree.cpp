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

//Time complexity :ϴ(n) and Auxiliary space :O(h) 
int getSize(Node *root){
    if(root == NULL)
        return 0;
    return (1+getSize(root->left)+getSize(root->right));
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

    //Maximum no. of possible node in Binary Tree with height(h) = 2^h - 1
    cout<<"Size of Tree : "<<getSize(root);

    return 0;
}