#include<iostream>
using namespace std;

//Naive Approach ::Time complexity :O(N!*N) & Auxiliary space :O(1)
void permuta(string str,int l,int r){
    if(l == r){
        if(str.find("AB") == string::npos)
            cout<<str<<" ";
        return;
    }
    else{
        for(int i=l;i<=r;i++){
            swap(str[l],str[i]);
            permuta(str,l+1,r);
            swap(str[i],str[l]);
        }
    }
}
//Backtracking Approach ::Time complexity :O(N!*N) 
//-->but it will cutdown some recursion call ∴ practical time complexity will be
//less then that of naive solution.
bool isSafe(string str,int l,int i,int r){
    if(l!=0 && str[l-1]=='A' && str[i]=='B')
        return false;
    
    if(r==l+1 && str[i]=='A' && str[l]=='B')
        return false;
    
    return true;
}
void permutation(string str,int l,int r){
    if(l == r){
        cout<<str<<" ";
        return;
    }
    else{
        for(int i=l;i<=r;i++){
            if(isSafe(str,l,i,r)){
                swap(str[i],str[l]);
                permutation(str,l+1,r);
                swap(str[i],str[l]);
            }
        }
    }
}
int main(){
    string str = "ABC";
    int l = 0,r = str.length()-1;

    // permuta(str,l,r);
    permutation(str,l,r);

    return 0;
}