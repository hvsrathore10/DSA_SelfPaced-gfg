// Problem: Design a Data Structure a SpecialQueue which supports following operations 
// enqueue, deque, getMin() or getMax() where getMin() operation takes O(1) time.
#include<iostream>
#include<deque>
using namespace std;
 
//Time complexity :O(1) for both getMin() and getMax()
struct MyDeque{
    deque<int> dq;
    void insertMin(int x){
        dq.push_front(x);
    }
    void insertMax(int x){
        dq.push_back(x);
    }
    int getMin(){
        return dq.front();
    }
    int getMax(){
        return dq.back();
    }
};
int main(){
    MyDeque DQ;
    DQ.insertMin(3);
    DQ.insertMax(10);
    DQ.insertMin(2);
    DQ.insertMax(15);

    cout<<DQ.getMax()<<" ";
    cout<<DQ.getMin()<<" ";

    DQ.insertMax(20);
    DQ.insertMin(1);

    cout<<DQ.getMax()<<" ";
    cout<<DQ.getMin()<<" ";

    return 0;
}