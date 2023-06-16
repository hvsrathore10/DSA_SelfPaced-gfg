#include<iostream>
#include<string>
using namespace std;
//Naive method:- Time complexity :ϴ(n) Auixliary space :ϴ(n)
bool isPalindromeByRev(string &str){
    string rev = str;
    reverse(rev.begin(),rev.end());
    return (rev == str);
}
//Efficient method :- Time complexity :O(n) Auixliary space :O(1)
bool isPalindrome(string &str){
    int i=0,j=str.length()-1;
    while(i<j){
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main(){
    string str = "abcdcba";
    cout<<(isPalindromeByRev(str)? "True" : "False")<<endl;
    cout<<(isPalindrome(str)? "True" : "False")<<endl;
    return 0;
}