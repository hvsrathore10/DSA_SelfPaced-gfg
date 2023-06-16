#include<iostream>
using namespace std;

void perm(string str,int i){
    if(i == str.length()-1){
        cout<<str<<endl;
    }
    for(int j=i;j<str.length();j++){
        swap(str[i],str[j]);
        perm(str,i+1);
        swap(str[i],str[j]);
    }
}
int main(){
    string str = "ABC";
    cout<<"Printing All posible Permutation for string : "+str<<endl;
    perm(str,0);
    return 0;
}