#include<iostream>
#include<map>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
}; 
void inorder(Node *root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void verticalTraversal(Node *root,map<int,int> &m){
    if(root==NULL)
        return;
    
    queue< pair<int,Node *> > q;
    q.push(make_pair(0,root));
    
    while(!q.empty()){
        int hd = q.front().first;
        Node *curr = q.front().second;
        q.pop();

        m[hd] += curr->data;

        if(curr->left!=NULL)
            q.push(make_pair(hd-1,curr->left));

        if(curr->right!=NULL)
            q.push(make_pair(hd+1,curr->right));
    }
}
void verticalSum(Node *root){
    //base case :
    if(root==NULL)
        return;
    
    map<int,int> result;
    verticalTraversal(root,result);

    map<int,int>::iterator it;
    for(it=result.begin();it!=result.end();it++)
        cout<<it->second<<" ";
    cout<<endl;
}

int main(){
    Node *root = new Node(18);

    Node *t1 = new Node(8);    
    Node *t2 = new Node(70); 
    root->left = t1;
    root->right = t2;


    Node *t3 = new Node(4);    
    Node *t4 = new Node(10);    
    t1->left = t3;
    t1->right = t4;

    Node *t5 = new Node(60);
    Node *t6 = new Node(80);
    t2->left = t5;
    t2->right = t6;

    cout<<"Inoder Traversal : ";
    inorder(root);
    cout<<endl;
    verticalSum(root);
    return 0;
}