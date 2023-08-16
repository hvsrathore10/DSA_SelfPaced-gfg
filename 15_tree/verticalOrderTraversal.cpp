#include<iostream>
#include<map>
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

void fillMap(Node *root,map<int,vector<int> > &m,int hb){
    if(root==NULL)
        return;
    
    m[hb].push_back(root->data);

    fillMap(root->left,m,hb-1);
    fillMap(root->right,m,hb+1);
}
//Time complexity :O(N.logN) and Auxiliary space :O(N)
void verticalOrder(Node *root){
    if(root==NULL)
        return;

    map<int,vector<int> > m;
    fillMap(root,m,0);

    map<int,vector<int> >::iterator it;
    for(it = m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();i++)
            cout<<it->second[i]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    Node *root = new Node(10);

    //left & right child of 'root = 10'
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    root->left = t1;
    root->right = t2;

    //left & right child of "node=20"
    Node *t3 = new Node(40);
    Node *t4 = new Node(50);
    t1->left = t3;
    t1->right = t4;


    //left & right child of "node=30"
    Node *t5 = new Node(60);
    Node *t6 = new Node(70);
    t2->left = t5;
    t2->right = t6;
     
    verticalOrder(root);
    return 0;
}