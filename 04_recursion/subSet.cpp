#include<iostream>
#include<string>
using namespace std;

void subsets(string set,string curr,int index){
    if(index == set.length()){
        cout<< curr <<endl;
        return;
    }
    subsets(set,curr,index+1);
    subsets(set,curr+set[index],index+1);
}

int main(){
    string set = "ABC";
    cout<<"Power Set : " <<endl;
    subsets(set,"",0);
    return 0;
}