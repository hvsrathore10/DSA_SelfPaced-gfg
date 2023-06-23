//Complete Circular Linked-list
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};


Node *createList(Node *head);
void printList(Node *head);
int countNode(Node *head);
int search(Node *head,int key);
Node *insertAtBegin1(Node *head,int data);
Node *insertAtBegin2(Node *head,int data,Node *tail);
Node *insertAtBegin(Node *head,int data);
Node *insertAfter(Node *head,int data,int key);
Node *insertAtEnd1(Node *head,int data);
Node *insertAtEnd2(Node *head,int data,Node *tail);
Node *insertAtEnd(Node *head,int data);
// Node *insertAtPos(Node *head,int data,int pos);
Node *delHeadNaive(Node *head);
Node *delHead(Node *head);
Node *delKth(Node *head,int k);



int main(){
    Node *head = NULL;
    int choose,pos,data,key;

    while(1){
        cout<<"1.Create linked list\n";
        cout<<"2.Display\n";
        cout<<"3.Count\n";
        cout<<"4.To search any key\n";
        cout<<"5.To insert at begening of link list\n";
        cout<<"6.To insert at end of link list\n";
        cout<<"7.To add after any specific element\n";
        // cout<<"8.To add before any specific element\n";
        cout<<"8.To insert at any specific position\n";
        cout<<"9.To delete head\n";
        cout<<"10.To delete kth node\n";
        cout<<"11.To reverse the linked list\n";
        // cout<<"13.To sort linklist\n";
        cout<<"12.To exit\n";
        
        cout<<"Enter your choose : ";
        scanf("%d",&choose);

        switch(choose)
        {
            case 1 :
                head = createList(head);
                break;
            case 2 :
                printList(head);
                break;
            // case 3 :
            //     cout<<countNode(head)<<" Number of Node is list\n";
            //     break;
            // case 4 :
            //     cout<<"Enter the element to be search : ";
            //     cin>>key;
            //     cout<<search(head,key)<<" Position of "<<key<<endl;
            //     break;
            case 5 :
                cout<<"Enter element to be add : ";
                cin>>data;
                head = insertAtBegin(head,data);
                break;
            case 6 :
                cout<<"Enter element to be add : ";
                cin>>data;
                head = insertAtEnd(head,data);
                break;
            case 7 :
                cout<<"Enter element to be add : ";
                cin>>data;
                cout<<"Enter element after which you want to add : ";
                cin>>key;
                head = insertAfter(head,data,key);
                break;
            // case 8 :
            //     cout<<"Enter element to be add : ";
            //     cin>>data;
            //     cout<<"Enter element before which you want to add : ";
            //     cin>>key;
            //     head = addBefore(head,data,key);
            //     break;
            // case 8 :
            //     cout<<"Enter element to be add : ";
            //     cin>>data;
            //     cout<<"Enter possion at which to want to add : ";
            //     cin>>pos;
            //     head = insertAtPos(head,data,pos);
            //     break;
            case 9 :
                head = delHead(head);
                break;
            case 10 :
                int k;
                cout<<"Enter value of k : ";
                cin>>k;
                head = delKth(head,k);
                break;
            // case 11 :
            //     head = sort_lisklist(head);
            //     break;
            case 11 :
                exit(1);

            defalut :
                cout<<"Entered wronge choose!!\n\n";
        }
    
    }
    return 0;
}



//Time complexity : O(n)
Node *createList(Node *head){
    int n,data;
    cout<<"Enter Number of NODE's required : ";
    cin>>n;

    cout<<"Enter data for node : ";
    cin>>data;
    head = insertAtBegin(head,data);
    for(int i=2;i<=n;i++){
        cout<<"Enter data for node : ";
        cin>>data;
        head = insertAtEnd(head,data);
    }
    return head;
}
//Time complexity : ϴ(n)
void printList(Node *head){
    if(head == NULL)
        return;

    Node *curr = head;
    //While loop used : 
    // cout<<head->data<<" ";
    // Node *curr = head->next;
    // while(curr != head){
    //     cout<<curr->data<<" ";
    //     curr = curr->next;
    // }cout<<endl;

    //do-while loop used : 
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr != head);
    cout<<endl;
}

//Naive Approach :- Time complexity : O(n)
Node *insertAtBegin1(Node *head,int data){
    Node *temp = new Node(data);
    if(head == NULL)
        temp->next = temp;

    else{
        Node *curr = head;
        while(curr->next != head)
            curr = curr->next;

        temp->next = curr->next;
        curr->next = temp;
    }
    return temp;
}
// Efficient Approach :- Time complexity :O(1)
//Using tail pointer (i.e.,pointer points to the last node of list)
Node *insertAtBegin2(Node *head,int data,Node *tail){
    Node *temp = new Node(data);
    if(head == NULL)
        temp->next = temp;
    else{
        tail->next = temp;
        temp->next = head;
    }
    return temp;
}
//Efficient Approach :- Time complexity : O(1)
Node *insertAtBegin(Node *head,int data){
    Node *temp = new Node(data);

    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    else{
        //insert temp node after head
        temp->next = head->next;
        head->next = temp;
        //swap data to head & temp
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return head;
    }
}

Node *insertAfter(Node *head,int data,int key){
    if(head == NULL)
        return NULL;

    Node *temp = new Node(data);
    Node *tail = head;
    while(tail->next != head)
        tail = tail->next;
    
    if(tail->data == key){
        temp->next = head;
        tail->next = temp;
        return head;
    }

    Node *curr = head;
    while(curr!=NULL){
        if(curr->data == key){
            temp->next = curr->next;
            curr->next = temp;
            return head;
        }
        curr = curr->next;
    }

    cout<<key<<" is not present is List\n";
    return head;
}

//Naive Approach :- Time complexity : O(n)
Node *insertAtEnd1(Node *head,int data){
    Node *temp = new Node(data);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    else{
        Node *curr = head;
        while(curr->next != head)
            curr = curr->next;

        temp->next = curr->next;
        curr->next = temp;
        return head;
    }
}
// Efficient Approach :- Time complexity :O(1)
//Using tail pointer (i.e.,pointer points to the last node of list)
Node *insertAtEnd2(Node *head,int data,Node *tail){
    Node *temp = new Node(data);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    else{
        tail->next = temp;
        temp->next = head;
        tail = temp;
        return head;
    }
}
//Efficient Approach :- Time complexity : O(1)
Node *insertAtEnd(Node *head,int data){
    Node *temp = new Node(data);

    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    else{
        //insert temp node after head 
        temp->next = head->next;
        head->next = temp;
        //swap data to head & temp
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return temp;
    }
}

// Node *insertAtPos(Node *head,int data,int pos){

// }

//Naive Approach :- Time complexity : O(n)
Node *delHeadNaive(Node *head){
    //if list is empty
    if(head == NULL)
        return NULL;
    if(head->next == head){
        delete(head);
        return NULL;
    }
    Node *curr = head;
    while(curr->next != head)
        curr = curr->next;
    
    curr->next = head->next;
    delete(head);
    return curr->next;
}
// Time complexity : O(1)
Node *delHead(Node *head){
    if(head == NULL)
        return NULL;
    if(head->next == head){
        delete(head);
        return NULL;
    }
    //copying data of next of head in head
    // -->|10|-|-->|20|-|-->|30|-|---
    // -->|20|-|-->|20|-|-->|30|-|---
    head->data = head->next->data;

    Node *temp = head->next;
    head->next = head->next->next;
    delete(temp);

    return head;
}
//Time complexity : 
//With assumption 1<k<n
Node *delKth(Node *head,int k){
    if(head == NULL)
        return NULL;
    if(k == 1)
        return delHead(head);
    
    Node *curr = head;
    for(int i=0;i<k-2;i++)
        curr = curr->next;
    
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete(temp);
    return head;
    
}
