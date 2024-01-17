//🙂
#include<iostream>
using namespace std;

//Time complexity :O(n.㏒n) and Auxiliary space :O(1)
vector< pair<int,int> > coinExchange(int coins[],int n,int amount){
    vector< pair<int,int> > res;
    //Step1 :Sort the coins in decreasing form 
    sort(coins,coins+n,greater<int>());

    //Step2 :check for fisible coin which can  be taken
    for(int i=0;i<n;i++){
        if(coins[i]<=amount){
            int c = floor(amount/coins[i]);
            amount -= c*coins[i];
            res.push_back(make_pair(coins[i],c));
        }
        if(amount == 0)
            return res;
    } 

    return res;
}
int main(){
    int coins[] = {5,10,2,1};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 57;

    int nCoins = 0;
    vector< pair<int,int> > output = coinExchange(coins,n,amount);
    
    for(int i=0;i<output.size();i++){
        int coin = output[i].first;
        int count = output[i].second;
        nCoins += count;
        cout<<"Coin : "<<coin<<"\tNumber of coins : "<<count<<endl;
    }
    cout<<"Total Number of coins required : "<<nCoins<<endl;
    return 0;
}