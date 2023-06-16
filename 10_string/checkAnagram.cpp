#include<iostream>
#include<string>
using namespace std;

const int CHAR = 256;
//Efficient Approach :-  Time complexity: O(n) Auxiliary space: O(CHAR) 
//n --> sizeof strings and CHAR --> Number of all possible charaters in ASCII formate
bool isAnagram(string &s1,string &s2){
    //Base case for termination
    if(s1.length() != s2.length())
        return false;

    int count[CHAR] = {0};
    for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i=0;i<CHAR;i++){
        if(count[i] != 0)
            return false;
    }
    return true;
}

//Naive Method :- Time complexity:O(n㏒n)
bool isAnagramNaive(string &s1,string &s2){
    //Base case for termination
    if(s1.length() != s2.length())
        return false;
    
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    return (s1 == s2);
}
int main(){
    string s1 = "listen";
    string s2 = "silent";
    cout<<(isAnagram(s1,s2)?"True" : "False")<<endl;
    cout<<(isAnagramNaive(s1,s2)?"True" : "False")<<endl;
    return 0;
}