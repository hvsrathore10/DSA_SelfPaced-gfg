#include<iostream>
using namespace std;

// Naive Approach :- Travers binary tree to store inorder and preorder or postorder traversal it required 
//two traversal of binary tree.
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void preorder(Node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//Serialization :- Time complexity :O(N) and Auxiliary space :O(N)
void serialize(Node *root,vector<int> &res){
    //base case :
    if(root==NULL){
        res.push_back(-1);
        return;
    }

    res.push_back(root->data);
    
    serialize(root->left,res);
    serialize(root->right,res);
}
//Deserialization :- Time complexity :O(N) and Auxiliary space :O(N)
Node *deserialize(vector<int> &arr,int &index){
    if(index>=arr.size())
        return NULL;
    
    int value = arr[index];
    index++;
    if(value == -1)
        return NULL;

    Node *root = new Node(value);

    root->left = deserialize(arr,index);
    root->right = deserialize(arr,index);

    return root;
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

    Node *t8 = new Node(90);
    t5->right = t8;

    Node *t9 = new Node(100);
    t8->right = t9;

    //serialization :
    vector<int> arr;
    serialize(root,arr);

    cout<<"Serialization of Binary Tree : (arr)\n";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    int index = 0;
    Node *newTree = deserialize(arr,index);

    cout<<"Deserilization of Array into Binary Tree : \n";
    preorder(newTree);
    return 0;
}