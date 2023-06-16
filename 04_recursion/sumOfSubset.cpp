#include<iostream>
using namespace std;

static int sum = 0;
void getsum(int *set,int n,int index,int curr){
    if(index==n){
        sum = sum + curr;
        return ;
    }
    getsum(set,n,index+1,curr);
    getsum(set,n,index+1,curr+set[index]);

}
int main(){
    int set[] = {1,2,3};
    int n = sizeof(set)/sizeof(set[0]);
    getsum(set,n,0,0);
    cout<<sum<<endl;
    return 0;
}