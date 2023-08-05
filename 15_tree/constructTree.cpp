#include<iostream>
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

//Time complexity :O(n²) and Auxiliary space :O(n)
Node *construct(int in[],int pre[],int inStart,int inEnd){
    //inStart & inEnd- starting and ending are index of Inorder array
    if(inStart > inEnd)
        return NULL;
    static int preIndex = 0;
    Node *root = new Node(pre[preIndex++]); //create nodes for tree

    int inIndex;
    //search root->data in given Inorder traversal array( in[] )
    for(int i=inStart;i<=inEnd;i++){
        if(in[i] == root->data){
            inIndex = i;
            break;
        }
    }
    root->left = construct(in,pre,inStart,inIndex-1);
    root->right = construct(in,pre,inIndex+1,inEnd);

    return root;
}


//Hashing Based Approach : 
//Time complexity :O(n) and Auxiliary space :O(n)
Node *construct2(unordered_map<int,int> mp,int pre[],int inStart,int inEnd){
    if(inStart > inEnd)
        return NULL;

    static int preIndex = 0;
    Node *root = new Node(pre[preIndex++]);

    if(mp.find(root->data) != mp.end()){
        root->left = construct2(mp,pre,inStart,mp[root->data]-1);
        root->right = construct2(mp,pre,mp[root->data]+1,inEnd);
    }
    else 
        return NULL;
    return root;
}
Node *constructTree(int in[],int pre[],int n){
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++)
        mp[in[i]] = i;
    
    Node *root = construct2(mp,pre,0,n-1);
    return root;
}

void preorderPrint(Node *root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);        
}
int main(){
    int inorder[] = {20,10,40,30,50};
    int preorder[] = {10,20,30,40,50};
    int n = sizeof(inorder)/sizeof(inorder[0]);

    Node *root = construct(inorder,preorder,0,n-1);
    Node *root = constructTree(inorder,preorder,n);
    printf("Preorder : ");
    preorderPrint(root);
    return 0;
}