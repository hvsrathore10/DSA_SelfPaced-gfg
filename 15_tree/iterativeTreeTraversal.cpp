#include<iostream>
#include<stack>
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
//Time complexity :ϴ(n) and Auxiliary space :O(h)
void inorder(Node *root){
    if(root==NULL)
        return ;
    stack<Node *> st;

    Node *curr = root;
    while(curr!=NULL || st.empty()==false){
        while(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}
//Time complexity :O(n) and Auxiliary space :O(n)
void preorder(Node *root){
    if(root == NULL)
        return;
    
    stack<Node *> st;
    Node *curr = root;
    while(curr!=NULL || st.empty()==false){
        while(curr!=NULL){
            cout<<curr->data<<" ";
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top()->right;
        st.pop();
    }
}
//Since in preorder traversal we simply process and print the node ∴ we not need to put left child in stack
//which give as scope of space optimization

//Time complexity :O(n) and Auxiliary space :O(h)
void preorder_better(Node *root){
    if(root == NULL)
        return;
    
    stack<Node *> st;
    Node *curr = root;
    while(curr!=NULL || st.empty()==false){
        while(curr!=NULL){
            cout<<curr->data<<" ";
            if(curr->right!=NULL)
                st.push(curr->right);
            curr = curr->left;
        }
        if(!st.empty()){
            curr = st.top();
            st.pop();
        }
        
    }
}
int main(){
    Node *root = new Node(30);

    Node *t1 = new Node(40);
    Node *t2 = new Node(80);
    root->left = t1;
    root->right = t2;

    Node *t3 = new Node(50);
    Node *t4 = new Node(70);
    t1->left = t3;
    t1->right = t4;

    Node *t5 = new Node(5);
    t2->left = t5;

    Node *t6 = new Node(20);
    Node *t7 = new Node(10);
    t4->left = t6;
    t4->right = t7;
    cout<<"Inorder Traversal : ";
    inorder(root);
    cout<<"\nPreorder Traversal : ";
    preorder(root);
    cout<<"\nPreorder Traversal : ";
    preorder_better(root);
    return 0;
}