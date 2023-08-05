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
bool findPath(Node *root,vector<Node *> &path,int n){
    //base case
    if(root==NULL)
        return false;
    //push 'root' node to path[] assuming 'root' will be part of path 
    path.push_back(root);
    //if root->data is equal to n (i.e. we reach an required node)
    if(root->data == n)
        return true;
    
    if(findPath(root->left,path,n) || findPath(root->right,path,n))
        return true;
    
    //if funtion does not return from any to the if-condition 
    // => 'root' is not part of required path[]
    path.pop_back();
    return false;
}

//Naive Solution :- Time complexity :ϴ(n) *But required Three traversal of Tree
//                  and Auxiliary space :O(n)
Node *LCA(Node *root,int n1,int n2){
    if(root==NULL)
        return NULL;
    vector<Node *> path1,path2;
    
    //findPath() will fill both path array 
    // {if findPath() return false it means n1 or n2 is not present in tree}
    if(findPath(root,path1,n1)==false || findPath(root,path2,n2)==false)
        return NULL;
    
    //find Lowest Comman Ancestor for path1[] & path2[]
    for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++){
        if(path1[i+1] != path2[i+1])
            return path1[i];
    }
    return NULL;
}


//Efficient Approach :- Time complexity :ϴ(n) *only single traversal is required
                        // and Auxiliary space :ϴ(h)
Node *_LCA(Node *root,int n1,int n2){
    //base case
    if(root==NULL)
        return NULL;
    // case 1 : if root is same as n1 or n2
    if(root->data==n1 || root->data==n2)
        return root;

    Node *lca1 = _LCA(root->left,n1,n2);
    Node *lca2 = _LCA(root->right,n1,n2);
    // case 2 : if one of its subtree contain n1 and another conatain n2
    if(lca1!=NULL && lca2!=NULL)
        return root;
    
    //case 3 : if one of its subtree contain both n1 & n2
    if(lca1!=NULL)
        return lca1;
    //case 4 : if non of its subtree contain any of n1 or n2
    else 
        return lca2;
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

    Node *res1 = LCA(root,30,80);
    cout<<res1->data<<endl;
    Node *res2 = _LCA(root,30,80);
    cout<<res2->data<<endl;
    return 0;
}