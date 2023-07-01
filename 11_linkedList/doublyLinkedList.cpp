//Complete Doubly Linked-list
#include<iostream>
using namespace std;
 
struct Node{
    //Node details
    int data;
    Node *prev;
    Node *next;
    //Constructor
    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};


Node *createList(Node *head);
void printList(Node *head);
int countNode(Node *head);
int search(Node *head,int key);
Node *insertAtBegin(Node *head,int data);
Node *insertAfter(Node *head,int data,int key);
Node *insertAtEnd(Node *head,int data);
Node *insertAtPos(Node *head,int data,int pos);
Node *reverseList(Node *head);
Node *delHead(Node *head);
Node *delTail(Node *head);


int main(){
     Node *head = NULL;
    int choose,pos,data,key;

    while(1)
    {
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
        cout<<"10.To delete tail\n";
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
            case 3 :
                cout<<countNode(head)<<" Number of Node is list\n";
                break;
            case 4 :
                cout<<"Enter the element to be search : ";
                scanf("%d",&key);
                cout<<search(head,key)<<" Position of "<<key<<endl;
                break;
            case 5 :
                cout<<"Enter element to be add : ";
                scanf("%d",&data);
                head = insertAtBegin(head,data);
                break;
            case 6 :
                cout<<"Enter element to be add : ";
                scanf("%d",&data);
                head = insertAtEnd(head,data);
                break;
            case 7 :
                cout<<"Enter element to be add : ";
                scanf("%d",&data);
                cout<<"Enter element after which you want to add : ";
                scanf("%d",&key);
                head = insertAfter(head,data,key);
                break;
            // case 8 :
            //     cout<<"Enter element to be add : ";
            //     scanf("%d",&data);
            //     cout<<"Enter element before which you want to add : ";
            //     scanf("%d",&key);
            //     head = addBefore(head,data,key);
            //     break;
            case 8 :
                cout<<"Enter element to be add : ";
                scanf("%d",&data);
                cout<<"Enter possion at which to want to add : ";
                scanf("%d",&pos);
                head = insertAtPos(head,data,pos);
                break;
            case 9 :
                head = delHead(head);
                break;
            case 10 :
                head = delTail(head);
                break;
            case 11 :
                head = reverseList(head);
                break;
            // case 12 :
            //     head = sort_lisklist(head);
            //     break;
            case 12 :
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
    cout<<"Enter number of NODE's required :";
    cin>>n;

    cout<<"Enter information for node : ";
    cin>>data;
    head = insertAtBegin(head,data);
    for(int i=2;i<=n;i++){
        cout<<"Enter information for node : ";
        cin>>data;
        head = insertAtEnd(head,data);
    }
    return head;
}

//Time complexity : ϴ(n)
int countNode(Node *head){
    int count = 0;

    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

//Time complexity : O(n)
void printList(Node *head){
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}

//Time complexity : O(n)
int search(Node *head,int key){
    if(head == NULL){
        cout<<"List is empty\n";
        return -1;
    }
    int pos = 1;
    while(head != NULL){
        if(head->data == key)
            return pos;
        head = head->next;
        pos++;
    }
    cout<<key<<" is not present is List\n";
    return -1;
}

//Time complexity : O(1)
Node *insertAtBegin(Node *head,int data){
    Node *temp = new Node(data);
    if(head == NULL)
        return temp;
    
    temp->next = head;
    head->prev = temp;
    return temp;
}

Node *insertAfter(Node *head,int data,int key){
    if(head == NULL)
        return head;
    
    Node *temp = new Node(data);
    Node *curr = head;

    while(curr != NULL){
        if(curr->data == key){
            temp->next = curr->next;
            curr->next->prev = temp;
            curr->next = temp;
            temp->prev = curr;
            return head;
        }
        curr = curr->next;
    }
    cout<<"Key is not present in List\n";
    return head;
}
//Time complexity : ϴ(n)
Node *insertAtEnd(Node *head,int data){
    Node *temp = new Node(data);
    if(head == NULL){
        return temp;
    }

    Node *curr = head; 
    while(curr->next != NULL)
        curr = curr->next;
    
    curr->next = temp;
    temp->prev = curr;
    return head;
}
//Time complexity : O(pos)
Node *insertAtPos(Node *head,int data,int pos){
    Node *temp = new Node(data);

    if(head == NULL){
        if(pos==1) return temp;
        else return NULL;
    }
    if(pos == 1){
        head->prev = temp;
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for(int i=1;i<pos-1 && curr != NULL;i++)
        curr = curr->next;
    
    if(curr == NULL){
        cout<<"Position is out of Range"<<endl;
        return head;
    }
    
    temp->next = curr->next;
    curr->next = temp;
    temp->prev = curr;
    temp->next->prev = temp;
    return head;
}

//Time complexity :O(1)
Node *delHead(Node *head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete(head);
        return NULL;
    }
    else{
        Node *temp = head->next;
        delete(head);
        temp->prev = NULL;
        return temp;
    }
    
}
//Time complexity : O(n)
Node *delTail(Node *head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL){
        delete(head);
        return NULL;
    }
    Node *curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    
    curr->prev->next = NULL;
    curr->prev = NULL;  //optional 
    delete(curr);
    return head;
}

//Time compleaxity : O(n)
Node *reverseList(Node *head){
    Node *prev,*curr;
    if(head == NULL || head->next == NULL){
        return head;
    }
    prev = NULL;
    curr = head;
    while(curr != NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}
