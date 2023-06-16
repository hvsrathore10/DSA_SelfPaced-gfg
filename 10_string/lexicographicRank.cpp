#include<iostream>
using namespace std;
// Naive Approach of LEXIOGRAPHIC RANK is to generate all possible permutation 
// of the string which take O(n!) time where n --> str.len()

const int CHAR = 256;
int fact(int n){
    if(n==0 || n==1)
        return 1;
    return n*fact(n-1);
}
// Efficient Approach :- Time complexity :O(n)
int lex_rank(string &str){
    int res = 1;
    int n = str.length();
    int count[CHAR] = {0};
    int mult = fact(n);

    for(int i=0;i<n;i++)
        count[str[i]]++;
    //cumulative sum
    for(int i=1;i<CHAR;i++)
        count[i] += count[i-1];
    
    for(int i=0;i<n;i++){
        mult = mult/(n-i);
        res = res + (count[str[i] - 1]*mult);

        for(int j=str[i];j<CHAR;j++)
            count[j]--;
    }
    return res;
}
int main(){
    string str = "DCBA";
    printf("Lexicographic Rank of str is : %d\n",lex_rank(str));
    return 0;
}