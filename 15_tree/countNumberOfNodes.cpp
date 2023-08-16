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
//Naive Approach :- Time complexity :ϴ(N) and Auxiliary space : O(H)
int countNodesNaive(Node *root){
    if(root==NULL)
        return 0;
    return 1+countNodesNaive(root->left) + countNodesNaive(root->right);
}

//Efficient Approach :- Time complexity :O(log(N)*log(N))
//Best case :Prefect Binary tree and Recurrence Relation :T(N) = T(2*N/3) + ϴ(H)  ::H = ㏒N
int countNodes(Node *root){
    if(root==NULL)
        return 0;
    
    int lh = 0,rh = 0;
    //left height of tree
    Node *curr = root;
    while(curr!=NULL){
        lh++;
        curr = curr->left;
    }
    //right height of tree
    curr = root;
    while(curr!=NULL){
        rh++;
        curr = curr->right;
    }

    if(lh == rh)
        return ( pow(2,lh)-1 );
    else
        return 1+countNodes(root->left)+countNodes(root->right);
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
    Node *t6 = new Node(70);
    t2->left = t5;
    t2->right = t6;

    Node *t7 = new Node(80);
    Node *t8 = new Node(90);
    t3->left = t7;
    t3->right = t8;

    Node *t9 = new Node(100);
    Node *t10 = new Node(110);
    t4->left = t9;
    t4->right = t10;

    Node *t11 = new Node(120);
    t5->left = t11;

    cout<<countNodesNaive(root)<<endl;
    cout<<countNodes(root)<<endl;
    return 0;
}