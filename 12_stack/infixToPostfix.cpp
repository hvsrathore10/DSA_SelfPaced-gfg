#include<iostream>
#include<stack>
using namespace std;

//Time :O(1)
bool isOperator(char x){
    return (!isalpha(x) && !isdigit(x));
}
//Time :O(1)
int prec(char x){
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='^')
        return 3;
    else 
        return -1;
}
//Time complexity :O(n) and Auxiliary space :O(n)
string infixToPostfix(string &infix){
    stack<char> st; //stack will store OPERATOR
    string postfix = "";

    for(int i=0;i<infix.length();i++){
        if(!isOperator(infix[i]))
            postfix += infix[i];
        else if(infix[i]=='(')
            st.push('(');
        else if(infix[i]==')'){
            while(st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(st.empty())  
                st.push(infix[i]);
            else if(prec(infix[i]) > prec(st.top()))
                st.push(infix[i]);
            else{
                while(!st.empty() && prec(infix[i]) <= prec(st.top())){
                    postfix += st.top();
                    st.pop();
                }
                st.push(infix[i]);
            }
        }
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main(){
    string infix = "((A+B)-C*(D/E))+F";
    cout<<"Infix to Postfix"<<endl;
    cout<<"Infix exprection : "<<infix<<endl;
    cout<<"Postfix exprection : "<<infixToPostfix(infix)<<endl;

    return 0;
}