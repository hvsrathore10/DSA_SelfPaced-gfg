#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
//Time complexity :O(㏒N)
Node *findCeil(Node *root,int X){
    if(root==NULL)
        return NULL;
    
    Node *res = NULL;
    while(root!=NULL){
        if(root->data == X)
            return root;
        else if(root->data > X){
            if(res != NULL){
                if(res->data > root->data)
                    res = root;
            }
            else
                res = root;
            root = root->left;
        }
        else
            root = root->right;
    } 
    return res;
}
int main(){
    Node *root = new Node(50);

    Node *t1 = new Node(20);
    Node *t2 = new Node(70);
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(15);
    Node *t4 = new Node(40);
    t1->left = t3;
    t1->right = t4;

    Node *t5 = new Node(60);
    Node *t6 = new Node(80);
    t2->left = t5;
    t2->right = t6;

    Node *ceilVal = findCeil(root,58);
    if(ceilVal != NULL)
        cout<<"Ceil of 58 : "<<ceilVal->data<<endl;
    else 
        cout<<"Ceil Not found"<<endl;
        
    return 0;
}