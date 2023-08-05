#include<iostream>
#include<stack>
#include<unordered_map>
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
int height(Node *root){
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
//Naive Approach :- Time complexity :O(n²) and Auxiliary space :O(n)
int diameter1(Node *root){
    if(root==NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    int curr_max = lh+rh+1;
    
    return max(max(diameter1(root->left),diameter1(root->right)),curr_max);
}
//Better Solution :- Time complexity :O(n) :: using unordered_map to store precomputed height of every node

//Efficient Solution :- Time complexity :O(n)
int res = 0;
int diameter3(Node *root){
    if(root==NULL)
        return 0;
    int lh = diameter3(root->left);
    int rh = diameter3(root->right);

    res = max(res,(lh+rh+1));
    return 1+max(lh,rh);
}

int main(){
    Node *root = new Node(10);

    Node *t1 = new Node(20);
    Node *t2 = new Node(60);
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(30);
    Node *t4 = new Node(80);
    t1->left = t3;
    t1->right = t4;

    Node *t5 = new Node(40);
    Node *t6 = new Node(50);
    t3->left = t5;
    t3->right = t6;

    Node *t7 = new Node(60);
    t5->left = t7;

    Node *t8 = new Node(90);
    t4->right = t8;

    Node *t9 = new Node(18);
    t8->right = t9;

    
    int height = diameter3(root);
    cout<<"Diameter of Binary Tree : "<<res<<endl;
    
    return 0;
}
