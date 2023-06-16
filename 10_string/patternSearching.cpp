// Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function patternSearch(char pat[], char txt[]) 
// that prints all occurrences of pat[] in txt[]. You may assume that n > m.
#include<iostream>
#include<string>
using namespace std;

//Naive Approach :- Time complexity :O((n-m+1)*m)  Auxiliary space :O(1)
//Example : i/p:- text = "abcabcd" pat = "abcd"
void patternSearchNaive(string &text,string &pat){
    int n = text.length();
    int m = pat.length();
    //Terminating condition
    if(n<m)
        return;
    //traverse over text string
    for(int i=0;i<=n-m;i++){
        if(text[i]==pat[0]){
            int index = i;
            int j=0;
            while(j<m){
                if(text[index] != pat[j])
                    break;
                
                index++;
                j++;
            }
            if(j==m)
                cout<<i<<" ";
        }
    } 
    cout<<endl;
}

//Naive Approach :- Time complexity :O(n) *Condition :-Pattern have all distinct characters
//Example : i/p:- text = "geeksforgeeks" pat = "eks"
void patternSearchNaive2(string &text,string &pat){
    int n = text.length();
    int m = pat.length();
    //Terminating condition
    if(n<m)
        return;

    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j] != pat[j])
                break;
        }
        if(j==m)
            cout<<i<<" ";
        if(j==0)
            i++;
        else
            i = i+j;
    }
    cout<<endl;
}

//Efficient Methods :- 

const int d = 256;
// 1.Rabin Karp Algorithm
//Example : i/p:- text = "abdabcbabc" pat = "abc"
void patternSearch_RK(string &text,string &pat){
    int n = text.length();
    int m = pat.length();

    //q - must be a big prime-number ∵ by this we will reduce spurious hit
    int q = 101;   //use for modulo operation

    // Harsh value
    int h = 1;     // h = pow(d,m-1)%q
    for(int i=1;i<=m-1;i++)
        h = (h*d)%q;
    
    int p = 0,t = 0;
    //combutation of p and t0
    for(int i=0;i<m;i++){
        p = (d*p + pat[i])%q;
        t = (d*t + text[i])%q;
    }

    for(int i=0;i<=n-m;i++){
        if(p==t){
            bool flag = true;
            for(int j=0;j<m;j++){
                if(text[i+j]!=pat[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                cout<<i<<" ";
        }
        if(i<n-m){
            t = (d*(t - text[i]*h) + text[i+m])%q;
            if(t<0)
                t = t+q;
        }
    }
    cout<<endl;
}
// 2.KMP Algorithm
void fillLPS(string &str,int lps[]){
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
                lps[i] = len;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
}
//KMP Pattern Searching method :- Time complexity :O(n) and Auixilairy Space :O(m)
void patternSearch_KMP(string &text,string &pat){
    int n = text.length();
    int m = pat.length();

    int lps[m];
    fillLPS(pat,lps);
    
    int i=0,j=0;
    while(i<n){
        if(text[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            cout<<(i-j)<<" ";
            j = lps[j-1];
        }
        else if(i<n && text[i]!=pat[j]){
            if(j==0)
                i++;
            else
                j = lps[j-1];
        }
    }
    cout<<endl;
}
// 3.Suffix Tree : 


int main(){
    string text = "abdabcbabc";
    string pat = "abc";
    patternSearchNaive(text,pat);
    patternSearchNaive2(text,pat);
    patternSearch_RK(text,pat);
    patternSearch_KMP(text,pat);
    return 0;
}