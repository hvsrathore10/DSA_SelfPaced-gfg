// Maximum Width of Binary tree is the maximum number of nodes present in a level of the Tree.
#include<iostream>
#include<queue>
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

//Time complexity :O(n) and Auxiliary space :O(nL)
int width(Node *root){
    if(root==NULL)
        return 0;

    int res = 0;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        res = max(res,count);
        //push subtree in queue
        for(int i=0;i<count;i++){
            Node *curr = q.front();
            q.pop();
            //left child
            if(curr->left!=NULL) q.push(curr->left);
            //right child
            if(curr->right!=NULL) q.push(curr->right);
        }
    }
    return res;
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

    cout<<width(root);
    return 0;
}