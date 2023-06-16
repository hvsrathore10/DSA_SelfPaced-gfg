#include<iostream>
using namespace std;

//Naive Approach :- Time complexity:O(n²)
int leftmostNonRep(string &str){
    for(int i=0;i<str.length();i++){
        bool flag = false;
        for(int j=0;j<str.length();j++){
            if((j!=i) && (str[i] == str[j])){
                flag = true;
                break;
            }
        }
        if(flag==false)
            return i;
    }
    return -1;
}
const int CHAR = 256;
//Efficient Approach : Time complexity :O(n) Auxiliary space:O(CHAR)
int leftmostNonRepeatingChar(string &str){
    int count[CHAR] = {0};
    for(int i=0;i<str.length();i++)
        count[str[i]]++;
    
    for(int i=0;i<str.length();i++){
        if(count[str[i]]==1)
            return i;
    }
    return -1;
}
//Better solution : Time complexity :O(n) Auxiliary space:O(CHAR) **Only one traversal is required
int leftmost(string &str){
    int fIndex[CHAR];
    fill(fIndex,fIndex+CHAR,-1);

    for(int i=0;i<str.length();i++){
        int fi = fIndex[str[i]];
        if(fi == -1)
            fIndex[str[i]] = i;
        else
            fIndex[str[i]] = -2;
    }
    int res = INT_MAX;
    for(int i=0;i<CHAR;i++){
        if(fIndex[i]>0)
            res = min(res,fIndex[i]);
    }
    return (res==INT_MAX)? -1 : res;
}
int main(){
    string str = "geeksforgeeks";
    cout<<"Index of Leftmost Repeating Character : "<<leftmostNonRep(str)<<endl;
    cout<<"Index of Leftmost Repeating Character : "<<leftmostNonRepeatingChar(str)<<endl;
    cout<<"Index of Leftmost Repeating Character : "<<leftmost(str)<<endl;
    return 0;
}