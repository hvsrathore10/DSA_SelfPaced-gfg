#include<iostream>
#include<string>
#include<stack>
using namespace std;
 
//Time complexity :O(n) and Auxiliary space :O(n)
bool isBalanced(string &str){
    stack<char> s;

    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')
            s.push(str[i]);
        else{
            switch(str[i]){
                case ')':
                    if(s.top() != '(')
                        return false;
                    s.pop();
                    break;
                case ']':
                    if(s.top() != '[')
                        return false;
                    s.pop();
                    break;
                case '}':
                    if(s.top() != '{')
                        return false;
                    s.pop();
                    break;
                default :
                    cout<<"Unwanted Character is present!!"<<endl;
                    return false;
            }
        }
    }
    return s.empty();
}
int main(){
    string str = "{}([()])";

    cout<<"String is Parenthesis Balanced : "<<(isBalanced(str)? "Yes":"No")<<endl;
    return 0;
}