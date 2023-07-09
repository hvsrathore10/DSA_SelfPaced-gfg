#include<iostream>
using namespace std;

//Fixed size stack implementation using array
struct MyStack{
    int *arr;
    int cap; //capacity
    int top;
    MyStack(int c){
        cap = c;
        arr = new int(cap);
        top = -1;
    }
    //push-function :-Time complexity:O(1)
    void push(int x){
        if(top >= cap-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    //pop-function :-Time complexity:O(1)
    int pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            return INT_MAX;
        }
        int res = arr[top];
        top--;
        return res;
    }
    //top-function :-Time complexity:O(1)
    int peek(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            return INT_MAX;
        }
        return arr[top];
    }
    //empty-function :-Time complexity:O(1)
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    //size-function :-Time complexity:O(1)
    int size(){
        return (top+1);
    }
};

//Dynamic size stack implementation using vector
struct MyDynamicStack{
    vector<int> v;

    //push-function :-Time complexity:O(1)
    void push(int x){
        v.push_back(x);
    }
    //pop-function :-Time complexity:O(1)
    int pop(){
        int res = v.back();
        v.pop_back();
        return res;
    }
    //top-function :-Time complexity:O(1)
    int peek(){
        return v.back();
    }
    //empty-function :-Time complexity:O(1)
    bool isEmpty(){
        return v.empty();
    }
    //size-function :-Time complexity:O(1)
    int size(){
        return v.size();
    }
};

int main(){
    cout<<"Static Stack : "<<endl;
    MyStack s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    cout<<s.peek()<<endl;
    cout<<s.pop()<<" is poped from stack"<<endl;
    cout<<s.peek()<<endl;
    cout<<(s.isEmpty()? "True":"False")<<endl;
    cout<<s.size()<<endl;
    
    
    cout<<"Dynamic Stack : "<<endl;
    MyDynamicStack st;
    st.push(50);
    st.push(100);
    st.push(150);
    cout<<st.peek()<<endl;
    cout<<st.pop()<<" is poped from stack"<<endl;
    cout<<st.peek()<<endl;
    cout<<(st.isEmpty()? "True":"False")<<endl;
    cout<<st.size()<<endl;

    return 0;
}