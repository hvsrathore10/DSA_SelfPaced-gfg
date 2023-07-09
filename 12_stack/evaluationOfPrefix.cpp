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
int evaluationPrefix(string &prefix){
    stack<int> st;
    
    for(int i=prefix.length()-1;i>=0;i--){
        char c = prefix[i];
        if(c==' ')
            continue;
        else if(isdigit(c))
            st.push(c-'0');
        else{
            int opt1 = st.top();
            st.pop();
            int opt2 = st.top();
            st.pop();
            int sum = evaluate(opt1,opt2,c);
            st.push(sum);
        }
    }
    return st.top();
}
int main(){
    string prefix = "- + 7 * 4 5 + 2 0";
    cout<<"Evaluatuion of prefix exprection :\n"<<prefix<<endl;
    cout<<"Resutl : "<<evaluationPrefix(prefix)<<endl;
    return 0;
}