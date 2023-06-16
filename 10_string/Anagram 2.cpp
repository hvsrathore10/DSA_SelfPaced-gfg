#include<iostream>
#include<string>
using namespace std;

const int CHAR = 256;
bool areAnagram(string &txt,string &pat,int x);

// Naive Approact :- Time complexity :O((n-m+1)*m) Auxiliary space :O(CHAR)
bool isPresent(string &txt,string &pat){
    int n = txt.length();
    int m = pat.length();

    for(int i=0;i<n-m;i++){
        if(areAnagram(txt,pat,i))
            return true;
    }
    return false;
}
bool areAnagram(string &txt,string &pat,int x){
    int m = pat.length();

    int count[CHAR] = {0};
    for(int i=0;i<m;i++){
        count[txt[x+i]]++;
        count[pat[i]]--;
    }
    for(int i=0;i<CHAR;i++){
        if(count[i]!=0)
            return false;
    }
    return true;
}

bool areSame(int c_txt[],int c_pat[]);
// Efficient Approach :- Time complexity :O(n-m) Auxiliary space :O(CHAR)
bool isPresent2(string &txt,string &pat){
    int n = txt.length();
    int m = pat.length();

    int c_txt[CHAR] = {0};
    int c_pat[CHAR] = {0};
    for(int i=0;i<m;i++){
        c_txt[txt[i]]++;
        c_pat[pat[i]]++;
    }
    for(int i=m;i<n;i++){
        if(areSame(c_txt,c_pat))
            return true;
        c_txt[txt[i]]++;
        c_txt[txt[i-m]]--;
    }
    return false;
}
bool areSame(int c_txt[],int c_pat[]){
    for(int i=0;i<CHAR;i++){
        if(c_txt[i]!=c_pat[i])
            return false;
    }
    return true;
}
int main(){
    string txt = "geeksforgeeks";
    string pat = "frog";
    cout<<(isPresent(txt,pat)? "True":"False")<<endl;
    cout<<(isPresent2(txt,pat)? "True":"False")<<endl;
    return 0;
}