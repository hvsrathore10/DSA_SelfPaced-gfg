#include<iostream>
#include<map>
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
//print inorder traversal of Binary Tree :
void inorder(Node *root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node *createNodeParentLink(Node *root,map<Node *,Node *> &nodeParentMap,int target){
    Node *targetNode;
    //fill map for node to parent and find targetNode
    queue<Node *> q;
    q.push(root);
    nodeParentMap[root] = NULL;
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();

        if(curr->data == target)
            targetNode = curr;
        //map curr->left with curr 
        if(curr->left!=NULL){
            q.push(curr->left);
            nodeParentMap[curr->left] = curr;
        }
        //map curr->right with curr 
        if(curr->right!=NULL){
            q.push(curr->right);
            nodeParentMap[curr->right] = curr;
        }
    }

    return targetNode;
}
int burnTime(map<Node *,Node *> &nodeParentMap,Node *targetNode){
    if(targetNode==NULL)
        return 0;
    
    int ans = 0;
    map<Node *,bool> visited;
    // breadth first search
    queue<Node *> q;
    q.push(targetNode);
    visited[targetNode] = true;
    while(!q.empty()){
        bool flag = false;
        int size = q.size();
        for(int i=0;i<size;i++){
            Node *curr = q.front();
            q.pop();

            if(curr->left!=NULL && !visited[curr->left]){
                flag = true;
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right!=NULL && !visited[curr->right]){
                flag = true;
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(nodeParentMap[curr]!=NULL && !visited[nodeParentMap[curr]]){
                flag = true;
                q.push(nodeParentMap[curr]);
                visited[nodeParentMap[curr]] = true;
            } 
        }
        if(flag == true)
            ans++;
    }
    
    return ans;
}
//Method 1:- Time complexity :O(N) and Auxiliary space :O(N) --> O(3N) 
                                                // map of nodeParentMap = O(n), visited = O(n) and  queue = O(n)
int burnBinaryTree(Node *root,int target){
    //base case :
    if(root==NULL)
        return 0;

    map<Node *,Node *> nodeParentMap;
    Node *targetNode = createNodeParentLink(root,nodeParentMap,target);  //<---- O(N)

    int minTime = burnTime(nodeParentMap,targetNode); ///<---- O(N)

    return minTime;
}

int res = 0;
//Method 2:- Time complexity :O(N) and Auxiliary spcae :O(N) * Single Traversal and O(N) space only
int minBurnTime(Node *root,int target,int &dist){
    if(root==NULL)
        return 0;
    if(root->data == target){
        dist = 0;
        return 1;
    }

    int left_dist = -1,right_dist = -1;
    int lh = minBurnTime(root->left,target,left_dist);
    int rh = minBurnTime(root->right,target,right_dist);

    if(left_dist != -1){
        dist = left_dist + 1;
        res = max(res,dist+rh);
    }
    else if(right_dist != -1){
        dist = right_dist + 1;
        res = max(res,dist+lh);
    }

    return max(lh,rh) + 1;
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

    cout<<"Inorder Traversal of Binary Tree : ";
    inorder(root);

    //Two traversal will we reqired for burnBinaryTree function
    // Time : O(2*N) and Space : O(3*N)
    cout<<"\nTime taken to Burn tree : "<<burnBinaryTree(root,80)<<endl;

    int dist = -1;
    //Single traversal will we reqired for minBurnTree function
    // Time : O(N) and Space : O(N)
    int height = minBurnTime(root,80,dist);
    cout<<"\nTime taken to Burn tree : "<<res<<endl;
    return 0;
}