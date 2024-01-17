/*🙂
Problem : Given the weights and values of N items, put these items in a 
knapsack of capacity W to get the maximum total value in the knapsack. 
In Fractional Knapsack, we can break items for maximizing the total value 
of the knapsack.
*/
#include<iostream>
using namespace std;

bool myCmp(pair<int,int> a,pair<int,int> b){
    double ratioA = (double)a.first / a.second;
    double ratioB = (double)b.first / b.second;

    return ratioA > ratioB; 
}
//Time complexity :O(n.㏒n) and Auxiliary space :O(1)
double fractionalKnapsack(vector< pair<int,int> > arr,int capacity){
    double profit = 0;
    sort(arr.begin(),arr.end(),myCmp);

    for(int i=0;i<arr.size();i++){
        if(arr[i].second <= capacity){
            capacity -= arr[i].second;
            profit += arr[i].first;
        }
        else{
            double p = (double)(capacity*arr[i].first)/arr[i].second;
            profit += p;
            return profit;
        }
    }
    return profit;
}
int main(){
//  Items as (value, weight) pairs 
//  arr[] = {{60, 10}, {100, 20}, {120, 30}} 
//  Knapsack Capacity, W = 50
    vector< pair<int,int> > arr;
    int W = 10;

    arr.push_back(make_pair(60,10));
    arr.push_back(make_pair(100,20));
    arr.push_back(make_pair(120,30));

    cout<<"Profit : "<<fractionalKnapsack(arr,W)<<endl;

    return 0;
}