#include<iostream>
#include<stack>
using namespace std;

//1.Implementing Queue using Stack by making enqueue costly :-
//Time complexity :- Enqueue :O(n) and Dequeue :O(1)
struct Queue1{
    stack<int> s1;
    stack<int> s2;

    void enqueue(int x){
        //move all element from stack1 to stack2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        //move all element back stack1 from stack2
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int dequeue(){
        if(s1.empty()) 
            return -1;

        int res = s1.top();
        s1.pop();
        return res;
    }
    int size(){
        return s1.size();
    }
    bool isEmpty(){
        return s1.empty();
    }
};

//2.Implementing Queue using Stack by making dequeue costly :-
//Time complexity :- Enqueue :O(1) and Dequeue :O(n)
struct Queue2{
    stack<int> s1;
    stack<int> s2;

    void enqueue(int x){
        s1.push(x);
    }
    int dequeue(){
        if(s1.empty()) 
            return -1;
        
        while(s1.size() != 1){
            s2.push(s1.top());
            s1.pop();
        }
        int res = s1.top();
        s1.pop();
        //swap name of stack's
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }
    int size(){
        return s1.size();
    }
    bool isEmpty(){
        return s1.empty();
    }
};
 
//3.Implementing Queue using single stack :-
// Time complexity :- enqueue :O() and dequeue :O()
struct Queue3{
    stack<int> s;

    void enqueue(int x){
        s.push(x);
    }
    int dequeue(){
        if(s.empty()) 
            return -1;
        if(s.size() == 1){
            int res = s.top();
            s.pop();
            return res;
        }
        int x = s.top();
        s.pop();
        int retVal = dequeue();
        s.push(x);
        return retVal;
    }
    int size(){
        return s.size();
    }
    bool isEmpty(){
        return s.empty();
    }
};

int main(){
    Queue3 q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    cout<<q.dequeue()<<" ";
    cout<<q.dequeue()<<" ";
    cout<<q.dequeue()<<" ";
    cout<<q.dequeue()<<" ";
    cout<<q.dequeue()<<" ";
    return 0;
}