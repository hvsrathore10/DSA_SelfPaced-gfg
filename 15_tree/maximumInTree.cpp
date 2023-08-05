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
//Recursive Approach :- Time complexity:-O(n) and Auxiliary space:-O(h)
int getMax(Node *root){
    if(root == NULL)
        return INT_MIN;
    
    return max(root->data,max(getMax(root->left),getMax(root->right)));
}
//Queue Based Approach :- Time complexity:-O(n) and Auxiliary space:-O(nL) nL == width of tree or no. of node at level L
int getMaxQ(Node *root){
    if(root==NULL)
        return INT_MIN;

    queue<Node *> q;
    int res = INT_MIN;
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        int c1 = INT_MIN,c2 = INT_MIN;
        if(curr->left != NULL){
            q.push(curr->left);
            c1 = curr->left->data;
        }
        if(curr->right != NULL){
            q.push(curr->right);
            c2 = curr->right->data;
        }
        res = max(res,max(c1,c2));
    }
    return res;
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

    cout<<"Maximum in Tree : "<<getMax(root)<<endl;
    cout<<"Maximum in Tree : "<<getMaxQ(root)<<endl;
    return 0;
}