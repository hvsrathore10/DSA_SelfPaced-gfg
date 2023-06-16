//Imp. -->STOCK BUY ANS SELL PROBLEM
#include<iostream>
using namespace std;

//Naive Approach : -->Time complexity :ϴ(n^2) -->Auixliary space: ϴ(n^2) *{function call stack}
int maxProfitNaive(int *stock,int start,int end){
    //Base condition :  
    if(end<=start)
        return 0;
    int profit = 0;
    for(int i=start;i<end;i++){
        for(int j=i+1;j<=end;j++){
            if(stock[j]>stock[i]){
                int curr_profit = (stock[j] - stock[i]) + maxProfitNaive(stock,start,i-1) + maxProfitNaive(stock,j+1,end);
                profit = max(profit,curr_profit);
            }
        }
    }
    return profit;
}
//Efficient Approach : -->Time complexity :ϴ(n)   -->Auxiliary space :ϴ(1)
int maxProfit(int *stock,int n){
    int profit = 0;
    for(int i=1;i<n;i++){
        if(stock[i]>stock[i-1]){
            profit = profit + (stock[i] - stock[i-1]);
        }
    }
    return profit;
}
int main(){
    int stock[] = {1,5,3,8,12};
    int n = sizeof(stock)/sizeof(stock[0]);
    cout<<"Maximum Profit from THIS.stock : "<<maxProfitNaive(stock,0,n-1)<<endl;
    cout<<"Maximum Profit from THIS.stock : "<<maxProfit(stock,n)<<endl;
    return 0;
}