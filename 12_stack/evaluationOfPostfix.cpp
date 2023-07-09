#include<iostream>
#include<stack>
using namespace std;


int evaluate(int a,int b,char opt){
    int sum;
    switch (opt){
        case '+':
            sum = a + b;
            break;
        case '-':
            sum = a - b;
            break;
        case '*':
            sum = a * b;
            break;
        case '/':
            sum = a / b;
            break;
        case '^':
            sum = (int)pow(a,b);
            break;
        default:
            break;
    }
    return sum;
}
//Time complexity : O(n) and Auxiliary space :O(n)
int evaluationPostfix(string &postfix){
    stack<int> st;
    
    for(char c : postfix){
        if(c==' ')
            continue;
        else if(isdigit(c))
            st.push(c-'0');
        else{
            int opt1 = st.top();
            st.pop();
            int opt2 = st.top();
            st.pop();
            int sum = evaluate(opt2,opt1,c);
            st.push(sum);
        }
    }
    return st.top();
}
int main(){
    string postfix = "2 3 1 * + 9 -";
    cout<<"Evaluatuion of postfix exprection :\n"<<postfix<<endl;
    cout<<"Resutl : "<<evaluationPostfix(postfix)<<endl;
    return 0;
}