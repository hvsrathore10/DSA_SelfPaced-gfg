#include<iostream>
#include<queue>
using namespace std;
 
//1.Implementing stack using Queue by making push costly :-
// Time complexity :- Push - O(n) and Pop - O(1) 
struct Stack1{
    queue<int> q1;
    queue<int> q2;

    void push(int x){
        if(q1.empty()){
            q1.push(x);
            return;
        }
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        //swap name of Queue's
        swap(q1,q2);
    }
    int pop(){
        if(q1.empty()) 
            return -1;
        int res = q1.front();
        q1.pop();
        return res;
    }
    int size(){
        return q1.size();
    }
    bool isEmpty(){
        return q1.empty();
    }
};

//2.Implementing stack using Queue by making pop costly :-
// Time complexity :- Push - O(1) and Pop - O(n) 
struct Stack2{
    queue<int> q1;
    queue<int> q2;

    void push(int x){
        q1.push(x);
    }
    int pop(){
        if(q1.empty())
            return -1;
        
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        //swap name of Queue's
        swap(q1,q2);
        return res;
    }
    int size(){
        return q1.size();
    }
    bool isEmpty(){
        return q1.empty();
    }
};

//3.Implementing stack using single Queue :-
// Time complexity :- Push - O(n) and Pop - O(1) 
struct Stack3{
    queue<int> q;

    void push(int x){
        if(q.empty())
            q.push(x);
        else{
            q.push(x);
            int n = q.size() - 1;
            while(n!=0){
                int temp = q.front();
                q.pop();
                q.push(temp);
                n--;
            }
        }
    }
    int pop(){
        if(q.empty()) 
            return -1;
        int res = q.front();
        q.pop();
        return res;
    }
    int size(){
        return q.size();
    }
    bool isEmpty(){
        return q.empty();
    }
};
int main(){
    Stack3 s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";
    return 0;
}