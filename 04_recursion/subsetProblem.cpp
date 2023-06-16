#include<iostream>
using namespace std;
 
int countSubset(int *set,int n,int sum){
    if(n==0){
        return (sum==0)? 1: 0;
    }
    return (countSubset(set,n-1,sum) + countSubset(set,n-1,sum-set[n-1]));
}
int main(){
    int set[] = {10,20,15};
    int sum = 25;
    int n = sizeof(set)/sizeof(set[0]);
    cout<<countSubset(set,n,sum)<<" number of subset present which have sum of element is equal to 'sum'"<<endl;
    return 0;
}