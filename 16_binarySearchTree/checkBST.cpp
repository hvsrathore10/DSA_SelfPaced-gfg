#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
int maxValue(Node *root){
    if(root==NULL)
        return INT_MIN;
    
    int res = root->data;
    int lres = maxValue(root->left);
    int rres = maxValue(root->right);

    res = max(res,max(lres,rres));
    return res;
}
int minValue(Node *root){
    if(root==NULL)
        return INT_MAX;
    
    int res = root->data;
    int lres = minValue(root->left);
    int rres = minValue(root->right);

    res = min(res,min(lres,rres));
    return res;
}
//Method 1:- Time complexity :O(N²) and Auxiliary space :O(H)
bool checkBST1(Node *root){
    if(root==NULL)
        return true;

    if(root->left!=NULL && maxValue(root->left)>root->data)
        return false;
    
    if(root->right!=NULL && minValue(root->right)<root->data)
        return false;
    
    return (checkBST1(root->left) && checkBST1(root->right));
}

//Method 2:- Time complexity :O(N) and Auxiliary space :O(H)
bool checkBST2(Node *root,int min,int max){
    if(root==NULL)
        return true;
    
    if(!(root->data>min && root->data<max))
        return false;
    
    
    return (checkBST2(root->left,min,root->data) 
            && checkBST2(root->right,root->data,max));
}

//Method 3:- Time complexity :O(N) and Auxiliary space :O(H)
bool checkBST3(Node *root,int &prev){
    if(root==NULL)
        return true;
    
    if(checkBST3(root->left,prev)==false)
        return false;
    
    if(root->data < prev)
        return false;
    prev = root->data;
    return checkBST3(root->right,prev);
}
int main(){
    Node *root = new Node(20);

    Node *t1 = new Node(8);    
    Node *t2 = new Node(30); 
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(22);    
    Node *t4 = new Node(40);    
    t2->left = t3;
    t2->right = t4;

    cout<<"Ckeck weather given tree is BST or Not : "<<checkBST1(root)<<endl;
    cout<<"Ckeck weather given tree is BST or Not : "<<checkBST2(root,INT_MIN,INT_MAX)<<endl;
    int prev = INT_MIN;
    cout<<"Ckeck weather given tree is BST or Not : "<<checkBST3(root,prev)<<endl;
    return 0;
}