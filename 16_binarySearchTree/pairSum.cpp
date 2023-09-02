// Problem : Given a Balanced Binary Search Tree and a target sum, write a function that returns true 
// if there is a pair with sum equals to target sum, otherwise return false. 
#include<iostream>
#include<unordered_set>
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


//Method 1:- Inorder and Two-pointer based
void inorderUtility(Node *root,vector<int> &arr){
    if(root==NULL)
        return;
    
    inorderUtility(root->left,arr);
    arr.push_back(root->data);
    inorderUtility(root->right,arr);
}
//Method 1:- Inorder and Two-pointer based
// Time complexity :ϴ(n) and Auxiliary space :ϴ(n)
bool isPairSum1(Node *root,int sum){
    if(root==NULL)
        return false;
        
    vector<int> arr;
    //create sorted array using inorder traversal
    inorderUtility(root,arr);

    vector<int>::iterator begin_it = arr.begin();
    vector<int>::iterator end_it = arr.end()-1;

    int res;
    while(begin_it!=end_it){
        res = (*begin_it) + (*end_it);

        if(res==sum)
            return true;
        else if(res > sum)
            end_it--;
        else
            begin_it++;
    }
    return false;
}



//Method 2:- Inorder and Hashing based
bool utilityFun(Node *root,int sum,unordered_set<int> &s){
    if(root==NULL)  
        return false;
    
    if(utilityFun(root->left,sum,s))
        return true;

    if(s.find(sum - root->data) != s.end())
        return true;
    else 
        s.insert(root->data);
    
    return utilityFun(root->right,sum,s);
}
//Method 2:- Inorder and Hashing based
// Time complexity :O(n) and Auxiliary space :O(H)
bool isPairSum2(Node *root,int sum){
    unordered_set<int> s;

    return utilityFun(root,sum,s);
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

    int sum = 90;
    cout<<"Method 1:- "<<(isPairSum1(root,sum)?"True" : "False")<<endl;
    cout<<"Method 2:- "<<(isPairSum2(root,sum)?"True" : "False")<<endl;
    return 0;
}