// Description : In this problem be have to reverse the string word by word.
// Example : str = "I love coding"  o/p : "coding love I"

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Naive Approach :- Time complexity :O(n) Ausiliary space :O(n)
void reverseStr(string &str){
    vector<string> temp;
    string s = "";
    //push all words expect last word in vector temp
    for(int i=0;i<str.length();i++){
        if(str[i] == ' '){
            temp.push_back(s);
            s = "";
        }
        else{
            s += str[i];
        }
    }
    // push last word in vector
    temp.push_back(s);
    //print reversed string
    for(int i=temp.size() - 1;i>0;i--)
        cout<<temp[i]<<" ";
    cout<<temp[0]<<endl;
}
//Efficient Approach :- Time complexity:O(n) Ausiliary space :O(1)
void myReverseFun(string &str,int start,int end){
    while(start<=end){
        swap(str[start],str[end]);
        start++;
        end--;
    }
}
void reverseString(string &str){
    int start = 0;
    for(int end=0;end<str.length();end++){
        if(str[end]==' '){
            myReverseFun(str,start,end-1);
            start = end+1;
        }
    }
    myReverseFun(str,start,str.length()-1);
    myReverseFun(str,0,str.length()-1);
}
int main(){
    string str = "I love coding";
    reverseStr(str);
    reverseString(str);
    cout<<str<<endl;
    return 0;
}


//Some case :
// 1.if it have multiple space in b/w words
// 2.Number of trading spaces