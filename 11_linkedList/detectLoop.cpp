// Important Interviwe Question
// Description : 
#include<iostream>
#include<unordered_set>
using namespace std;
 
struct Node{
    int data;     //data --> information
    Node* next;  //next --> pointer to the next node
    //constructor
    Node(int d){
        data = d;
        next = NULL;
    }
};


//Time complexity : O(n)
void printList(Node *head){
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}
//Method 1 :- Time complexity : O(n²) & Auxiliary space :O(1)
bool isLoop1(Node *head){
    if(head==NULL)
        return false;
    Node *curr = head;
    while(curr!=NULL){
        Node *temp = head;
        while(temp!=curr){
            if(temp == curr->next)
                return true;
            temp = temp->next;
        }
        curr = curr->next;
    }
    return false;
}

//Structure used by Method 2
struct Node_2{
    int data;     //data --> information
    Node_2 *next;  //next --> pointer to the next node
    bool visited;
    //constructor
    Node_2(int d){
        data = d;
        next = NULL;
        visited = false;
    }
};
// Method 2 :- Time complexity :O(n) & Auxiliary space :O(1)
// But we need to modified our structure every time.
bool isLoop2(Node_2 *head){
    Node_2 *curr = head;
    while(curr!=NULL){
        if(curr->visited == true)
            return true;

        curr->visited = true;
        curr = curr->next;
    }
    return false;
}

//Method 3:- Time complexity :O(n) & Auxiliary space :O(1) 
//But in this method we will lost our list at the end
bool isLoop3(Node *head){
    Node *temp = new Node(0);
    Node *curr = head;
    while(curr!=NULL){
        if(curr->next == NULL)
            return false;
        if(curr->next == temp)
            return true;
        
        Node *curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }
    return false;
}

//Hashing Based Solution
//Method 4:- Time complexity :O(n) & Auxiliary space :O(n) 
bool isLoop4(Node *head){
    unordered_set<Node *> set;
    Node *curr = head;
    while(curr!=NULL){
        if(set.find(curr) != set.end())
            return true;
        
        set.insert(curr);
        curr = curr->next;
    }
    return false;
}


int main(){
    Node *head = new Node(10);
    Node *t1 = new Node(15);
    Node *t2 = new Node(12);
    Node *t3 = new Node(4);
    Node *t4 = new Node(20);

    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t2;
    
    cout<<isLoop1(head)<<endl;
    cout<<isLoop3(head)<<endl;
    cout<<isLoop4(head)<<endl;
    return 0;
}


