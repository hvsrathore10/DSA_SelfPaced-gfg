#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}
//Iterative Solution :- Time complexity :O(n) & Auxiliary spcae :O(n) --> auxiliary stack
void reverseQueueI(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
//Recursive Solution :- Time complexity :O(n) & Auxiliary spcae :O(1) --> fuction call stack
void reverseQueueR(queue<int> &q){
    if(q.empty())
        return;
    int x = q.front();
    q.pop();
    reverseQueueR(q);
    q.push(x);
}
int main(){
    queue<int> Q;
    Q.push(5);
    Q.push(10);
    Q.push(15);
    Q.push(20);
    Q.push(25);
    cout<<"Befor Reverse : ";
    display(Q);

    // reverseQueueI(Q);
    reverseQueueR(Q);
    cout<<"After Reverse : ";
    display(Q);

    return 0;
}