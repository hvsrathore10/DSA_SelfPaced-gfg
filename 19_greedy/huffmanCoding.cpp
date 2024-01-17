#include<iostream>
#include<queue>
using namespace std;

struct Node{
    char data;
    unsigned freq;

    Node *left,*right;
    Node(int c,unsigned f){
        data = c;
        freq = f;
        left = right = NULL;
    }
};
struct compair{
    bool operator()(Node* a,Node* b){
        return a->freq > b->freq;
    }
};

void printCode(Node* root,string str){
    if(root==NULL)
        return;
    
    if(root->data != '$')
        cout<<root->data<<" : "<<str<<endl;
    
    printCode(root->left,str+"0");
    printCode(root->right,str+"1");
}

void huffmanCode(char data[],int freq[],int n){
    priority_queue<Node* ,vector<Node*>,compair> minHeap;

    for(int i=0;i<n;i++)
        minHeap.push(new Node(data[i],freq[i]));

    while(minHeap.size() > 1){
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();

        Node* newNode = new Node('$',left->freq+right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    printCode(minHeap.top()," ");
}
int main(){
/*
    character   Frequency
    a            5
    b           9
    c           12
    d           13
    e           16
    f           45
*/
    char char_arr[] = {'a','b','c','d','e','f'};
    int freq_arr[] = {5,9,12,13,16,45};
    int n = sizeof(freq_arr)/sizeof(freq_arr[0]);

    huffmanCode(char_arr,freq_arr,n);
    return 0;
}