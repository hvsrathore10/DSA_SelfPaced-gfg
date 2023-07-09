#include<iostream>
using namespace std;

struct twoStack{
    int *arr;
    int cap,top1,top2;
    twoStack(int capacity){
        cap = capacity;
        arr = new int[cap];
        top1 = -1;
        top2 = cap;
    }

    bool push1(int x){
        if(top1 >= top2-1){
            cout<<"Stack Overflow!!"<<endl;
            return false;
        }
        arr[++top1] = x;
        return true;
    }
    int pop1(){
        if(top1==-1){
            cout<<"Stack Underflow!!"<<endl;
            return INT_MAX;
        }
        int res = arr[top1];
        top1--;
        return res;
    }
    int peek1(){
        if(top1==-1){
            cout<<"Stack Underflow!!"<<endl;
            return INT_MAX;
        }
        return arr[top1];
    }
    int size1(){
        return top1+1;
    }
    bool isEmpty1(){
        if(top1==-1)
            return true;
        return false;
    }


    bool push2(int x){
        if(top1 >= top2-1){
            cout<<"Stack overflow!!"<<endl;
            return false;
        }
        arr[--top2] = x;
        return true;
    }
    int pop2(){
        if(top2==cap){
            cout<<"Stack Underflow!!"<<endl;
            return INT_MAX;
        }
        int res = arr[top2];
        top2++;
        return res;
    }
    int peek2(){
        if(top2==cap){
            cout<<"Stack Underflow!!"<<endl;
            return INT_MAX;
        }
        return arr[top2];
    }
    int size2(){
        return top2+1;
    }
    bool isEmpty2(){
        if(top2==cap)
            return true;
        return false;
    }
    void display(){
        cout<<"Stack1 : ";
        for(int i=0;i<=top1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\nStack2 : ";
        for(int i=top2;i<cap;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};
int main(){
    twoStack s(10);
    cout<<"5 is pushed in stack1: "<<(s.push1(5)?"Yes":"No")<<endl;
    cout<<"10 is pushed in stack1: "<<(s.push1(10)?"Yes":"No")<<endl;
    cout<<"100 is pushed in stack2: "<<(s.push2(100)?"Yes":"No")<<endl;
    cout<<"20 is pushed in stack1: "<<(s.push1(20)?"Yes":"No")<<endl;
    cout<<"30 is pushed in stack1: "<<(s.push1(30)?"Yes":"No")<<endl;
    cout<<"110 is pushed in stack2: "<<(s.push2(110)?"Yes":"No")<<endl;
    cout<<"40 is pushed in stack1: "<<(s.push1(40)?"Yes":"No")<<endl;
    cout<<"130 is pushed in stack2: "<<(s.push2(130)?"Yes":"No")<<endl;
    cout<<"50 is pushed in stack1: "<<(s.push1(50)?"Yes":"No")<<endl;
    cout<<"120 is pushed in stack2: "<<(s.push2(120)?"Yes":"No")<<endl;
    cout<<"70 is pushed in stack1: "<<(s.push1(70)?"Yes":"No")<<endl;
    s.display();
    return 0;
}