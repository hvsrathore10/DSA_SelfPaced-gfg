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
//Time compelxity :O(㏒N) and Auxiliary space :O(㏒N)
void findFloorRecursive(Node *root,int X,int &floorVal){
    if(root==NULL)
        return;
    
    if(root->data == X)
        floorVal = root->data;
    else if(root->data > X)
        findFloorRecursive(root->left,X,floorVal);
    else{
        floorVal = root->data;
        findFloorRecursive(root->right,X,floorVal);
    }
}
//Time compelxity :O(㏒N) and Auxiliary space :O(1)
Node *findFloor(Node *root,int X){
    if(root==NULL)
        return NULL;
    
    Node *res = NULL;
    while(root!=NULL){
        if(root->data == X)
            return root;
        else if(root->data > X)
            root = root->left;
        else{
            res = root;
            root = root->right;
        }
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

    int floorVal = -1;
    findFloorRecursive(root,25,floorVal);
    if(floorVal!=-1)
        cout<<"Floor of 25 : "<<floorVal<<endl;
    else 
        cout<<"Floor is not present"<<endl;

    Node *floor = findFloor(root,25);
    if(floor!=NULL)
        cout<<"Flooe : "<<floor->data<<endl;
    else 
        cout<<"Floor is not present"<<endl;

    return 0;
}


