#include<iostream>
#include<stack>
using namespace std;

//Naive Approach for getMin() 
struct MyStack{
    stack<int> ms; //Main stack
    stack<int> as; //Auxiliary stack

    void push(int x){
        if(ms.empty())
            as.push(x);
        else if(x <= as.top())
            as.push(x);
        ms.push(x);
    }
    void pop(){
        if(as.top() == ms.top())
            as.pop();
        ms.pop();
    }
    int top(){
        return ms.top();
    }
    int getMin(){
        return as.top();
    }
};
//Efficient Approach to implement getMin() 
struct MyStack1{
    stack<int> ms; //Main stack
    int min;
    void push(int x){
        if(ms.empty()){
            min = x;
            ms.push(x);
        }
        else if(x <= min){
            ms.push(x-min);
            min = x;
        }
        else 
            ms.push(x);
    }
    void pop(){
        if(ms.top() <= 0)
            min = min - ms.top();
        ms.pop();
    }
    int top(){
        int t =  ms.top();
        return (t<=0)? min : t;
    }
    int getMin(){
        return min;
    }
};
int main(){
    MyStack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();
 
    cout<<" Minimum Element from Stack: " <<s.getMin()<<endl;
    return 0;
}