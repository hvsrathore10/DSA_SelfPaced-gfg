#include<iostream>
#include<string>
using namespace std;

int longestPrefixSuffix(string &str,int n){
    //provide substrings
    for(int len=n-1;len>0;len--){
        bool flag = true;
        //trevers over substrings to check for maximum 
        //lenght Prefix which is suffix
        for(int i=0;i<len;i++){
            if(str[i]!=str[n-len+i])
                flag = false;
        }
        if(flag==true)
            return len;
    }
    return 0;
}
//Naive Approach :- Time complexity :O(n³) Auxiliary space :O(1)
void fillLPSNaive(string &str,int lps[]){
    for(int i=0;i<str.length();i++)
        lps[i] = longestPrefixSuffix(str,i+1);
}

// Efficent Approach :- Time complexity :O(n) Auxiliary space :O(1)
void fillLPS(string str,int lps[]){
    int n = str.length();
    int len=0,i=1;

    lps[0] = 0;
    while(i<n){
        if(str[len]==str[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len==0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
}
int main(){
    string str = "abcdabeabf";
    int n = str.length();
    int lps[n];

    // fillLPSNaive(str,lps);
    fillLPS(str,lps);
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<lps[i]<<" ";
    }
    cout<<"]"<<endl;
    return 0;
}