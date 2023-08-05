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

int height(Node *root){
    //If we have empty tree or we are at leaf node
    if(root == NULL) 
        return 0;

    return (max(height(root->left),height(root->right))+1);
}
void printNode(Node *root,int k){
    if(root == NULL)
        return;
    if(k==0)
        cout<<root->data<<" ";
    printNode(root->left,k-1);
    printNode(root->right,k-1);
}


//Naive Approach :- Time:O(n + n*h) & Space:O(h)
void levelOrder1(Node *root){
    int h = height(root);

    for(int i=0;i<h;i++){
        printNode(root,i);
    }
}
/*      10
       /   \
      20   30
      /\      \
    40  50     6
        /\
       70 80
    
    output : 10 20 30 40 50 60 70 80
*/
//Efficient Approach :- Time complexity :O(n) and Space:O(nL)
void levelOrder2(Node *root){
    queue<Node *> q;
    //push root in queue [q = {10}]
    q.push(root);
    while(!q.empty()){
        // pop front from queue
        Node *curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        //push children of current node in queue
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
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

    cout<<"Level Order Traversal : "<<endl;
    levelOrder1(root);
    levelOrder2(root);
    return 0;
}