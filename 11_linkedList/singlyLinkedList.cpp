//Note : Complete Singly LinkedList
#include<iostream>
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


Node *createList(Node *head);
int countNode(Node *head);
void printListI(Node *head);
void printListR(Node *head);
int search(Node *head,int key);
int searchRecursive(Node *head,int key);
Node *insertAtBegin(Node *head,int data);
Node *insertAfter(Node *head,int data,int key);
Node *insertAtEnd(Node *head,int data);
Node *insertAtPos(Node *head,int data,int pos);
Node *delHead(Node *head);
Node *delTail(Node *head);
Node *reverseList(Node *head);
Node *reverseListRecursive(Node *head);
Node *reverseListRecursive2(Node *head,Node *prev);
void sort(Node *head);

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
        cout<<"10.To delete tail\n";
        cout<<"11.To reverse the linked list\n";
        cout<<"12.To sort linklist\n";
        cout<<"13.To exit\n";
        
        cout<<"Enter your choose : ";
        scanf("%d",&choose);

        switch(choose)
        {
            case 1 :
                head = createList(head);
                break;
            case 2 :
                printListI(head);
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
                // head = reverseListRecursive(head);
                // head = reverseListRecursive2(head,NULL);
                break;
            case 12 :
                sort(head);
                break;
            case 13 :
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

//Iterative Traversal of Singly LinkedList
// Time complexity : ϴ(n) Auxiliary Space : ϴ(1) 
void printListI(Node *head){
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}
// Recursive Traversal of Singly LinkedList
// Time complexity : ϴ(n) Auxiliary Space : ϴ(n) <-- function-call stack
void printListR(Node *head){
    if(head == NULL)
        return;
    cout<<head->data<<" ";
    head = head->next;
    printListR(head);
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
//Time complexity : O(n) Auxiliary space : O(n) <--Function-call stack
int searchRecursive(Node *head,int key){
    if(head == NULL)
        return -1;
    
    if(head->data == key)
        return 1;
    else{
        int res = searchRecursive(head->next,key);
        if(res == -1) return -1;
        else return (res+1);
    }
}

// Time complexity : ϴ(1)
Node *insertAtBegin(Node *head,int data){
    Node *newHead = new Node(data);
    newHead->next = head;

    return newHead;
}
//Time complexity : ϴ(pos(key))
Node *insertAfter(Node *head,int data,int key){
    if(head == NULL){
        cout<<"List is Empty\n";
        return head;
    }

    Node *temp = new Node(data);
    Node *curr = head;
    while(curr != NULL){
        if(curr->data == key){
            temp->next = curr->next;
            curr->next = temp;
            return head;
        }
    }
    cout<<key<<" is not present in List\n";
    return head;
    
}
//Time complexity : O(n)
Node *insertAtEnd(Node *head,int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        return newNode;
    }
    Node *p = head;
    while(p->next != NULL)
        p = p->next;
    
    p->next = newNode;
    return head;
}
//Time complexity : O(pos)
Node *insertAtPos(Node *head,int data,int pos){
    //creating new node
    Node *temp = new Node(data);
    //if list is empty
    if(head == NULL){
        if(pos == 1) return temp;
        else return head;
    }
    if(pos == 1){
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
    return head;
}

// Time complexity : O(1)
Node *delHead(Node *head){
    if(head == NULL)
        return NULL;
    
    Node *temp = head->next;
    //In C++ programmer have to deallocation memory 
    // where as in JAVA deallocation will be done by compiler/garbage-collector
    delete(head);
    return temp;
}
//Time complexity : O(n)
Node *delTail(Node *head){
    //if list is Empty
    if(head == NULL)
        return NULL;
    //if list have head as only node
    if(head->next == NULL){
        delete(head);
        return NULL;
    }

    Node *p = head;
    while(p->next->next != NULL)
        p = p->next;
        
    delete(p->next);
    p->next = NULL;
    return head;
}

//Time complexity : ϴ(n)
Node *reverseList(Node *head){
    Node *prev,*curr,*next;
    //if head is null or head is only node
    if(head == NULL || head->next == NULL)
        return head;
    
    prev = NULL;
    curr = head;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//Time complexity : O(n)
Node *reverseListRecursive(Node *head){
    if(head==NULL || head->next==NULL)
        return head;
    
    Node *ref_head = reverseListRecursive(head->next);
    Node *ref_tail = head->next;
    ref_tail->next = head;
    head->next = NULL;
    return ref_head;
}
//Time complexity : O(n)
Node *reverseListRecursive2(Node *curr,Node *prev){
    if(curr==NULL)
        return prev;
    
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    return reverseListRecursive2(next,curr);
}

//Time complexity : O(n²)
void sort(Node *head){
    if(head==NULL)
        return;
    Node *p1,*p2;
    p1 = head;
    while(p1->next != NULL){
        p2 = p1->next;
        while(p2 != NULL){
            if(p2->data < p1->data)
                swap(p2->data,p1->data);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}
