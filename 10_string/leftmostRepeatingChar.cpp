#include<iostream>
using namespace std;

//Naive Approach :- Time complexity:O(n²)
int leftmostRep(string &str){
    for(int i=0;i<str.length();i++){
        for(int j=i+1;j<str.length();j++){
            if(str[i] == str[j])
                return i;
        }
    }
    return -1;
}
const int CHAR = 256;
//Efficient Approach : Time complexity :O(n) Auxiliary space:O(CHAR)
int leftmostRepeatingChar(string &str){
    int count[CHAR] = {0};
    for(int i=0;i<str.length();i++)
        count[str[i]]++;
    
    for(int i=0;i<str.length();i++){
        if(count[str[i]]>1)
            return i;
    }
    return -1;
}
//Better solution : Time complexity :O(n) Auxiliary space:O(CHAR) **Only one traversal is required
int leftmost1(string &str){
    int fIndex[CHAR];
    fill(fIndex,fIndex+CHAR,-1);

    int res = INT_MAX;
    for(int i=0;i<str.length();i++){
        int fi = fIndex[str[i]];
        if(fi == -1)
            fIndex[str[i]] = i;
        else
            res = min(res,fi);
    }
    return (res==INT_MAX)? -1 : res;
}
int leftmost2(string &str){
    bool visited[CHAR];
    fill(visited,visited+CHAR,false);

    int res = -1;
    for(int i=str.length()-1;i>=0;i--){
        if(visited[str[i]]==true)
            res = i;
        else
            visited[str[i]] = true;
    }
    return res;
}
int main(){
    string str = "geeksforgeeks";
    cout<<"Index of Leftmost Repeating Character : "<<leftmostRep(str)<<endl;
    cout<<"Index of Leftmost Repeating Character : "<<leftmostRepeatingChar(str)<<endl;
    cout<<"Index of Leftmost Repeating Character : "<<leftmost1(str)<<endl;
    cout<<"Index of Leftmost Repeating Character : "<<leftmost2(str)<<endl;
    return 0;
}