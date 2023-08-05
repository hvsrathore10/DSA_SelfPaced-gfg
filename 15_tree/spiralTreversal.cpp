#include<iostream>
#include<queue>
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
//Method 1 :- Time complexity :O(n)  *Atmost every element will get 4 push/pop operation 
void printSpiral(Node *root){
    if(root == NULL) return;

    queue<Node *> q;
    stack<int> s;
    bool reverse = false;

    q.push(root);

    while(!q.empty()){
        int count = q.size();
        for(int i=0;i<count;i++){
            Node *curr = q.front();
            q.pop();
            //if reverse is true then we have to print in reverse order
            if(reverse)
                s.push(curr->data);
            else   
                cout<<curr->data<<" ";
            
            if(curr->left!=NULL) q.push(curr->left);            
            if(curr->right!=NULL) q.push(curr->right);            
        }
        if(reverse){
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse = !reverse;  //flip reverse value
    }
}
//Method 2 :- Time complexity :O(n)
void spiral(Node *root){
    stack<Node *> s1,s2;
    //push root into s1
    s1.push(root);

    int level = 1;
    while(!s1.empty() || !s2.empty()){
        if(level%2 != 0){
            while(!s1.empty()){
                Node *curr = s1.top();
                s1.pop();
                cout<<curr->data<<" ";
                //push current node in s2 (in left-right order)
                if(curr->left!=NULL) s2.push(curr->left); 
                if(curr->right!=NULL) s2.push(curr->right); 
            }
        }
        else{
            while(!s2.empty()){
                Node *curr = s2.top();
                s2.pop();
                cout<<curr->data<<" ";
                //push current node in s1 (in right-left order)
                if(curr->right!=NULL) s1.push(curr->right);
                if(curr->left!=NULL) s1.push(curr->left);
            }
        }
        level++;
    }
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

    printSpiral(root);
    spiral(root);
    return 0;
}