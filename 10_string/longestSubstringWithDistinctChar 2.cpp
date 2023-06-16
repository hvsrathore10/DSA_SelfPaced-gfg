#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Naive Approach :- 
bool isDistinct(string &str,int i,int j){
    vector<bool> visited(256);

    for(int k=i;k<=j;k++){
        if(visited[str[k]] == true)
            return false;

        visited[str[k]] = true;
    }
    return true;
}
// Time complexity :O(n³) Auxiliary space :O(1)
int lsdcNaive1(string &str){
    int n = str.length();

    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)
            if(isDistinct(str,i,j))
                res = max(res,j-i+1);
    }
    return res;
}
// Better approach :- Time Complexity :O(n²) Auxiliary space :O(1)
int lsdcNaive2(string &str){
    int n = str.length();

    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    int res=0;
    for(int i=0;i<n;i++){
        vector<bool> visited(256,false);
        int j;
        for(j=i;j<n;j++){
            if(visited[str[j]]==true)
                break;
            else 
                visited[str[j]] = true;
        }
        res = max(res,j-i);
    }
    return res;
}
//Efficient Approach :- Time complexity :O(n) Auxiliary space :O(CHAR)
int lsdc(string &str){
    int n = str.length();

    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    
    int maxEnd = 0,res = 0;
    vector<int> prev(256,-1);
    int i = 0;
    for(int j=0;j<n;j++){
        i = max(i,prev[str[j]]+1);
        maxEnd = j-i+1;
        res = max(res,maxEnd);
        
        prev[str[j]] = j;
    }
    return res;
}
int main(){
    string str = "abcadba";
    cout<<"Length of Longest Substring with Distinct Characters : "<<lsdcNaive1(str)<<endl;
    cout<<"Length of Longest Substring with Distinct Characters : "<<lsdcNaive2(str)<<endl;
    cout<<"Length of Longest Substring with Distinct Characters : "<<lsdc(str)<<endl;
    return 0;
}