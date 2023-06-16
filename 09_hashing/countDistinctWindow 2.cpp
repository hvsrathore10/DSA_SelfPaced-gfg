#include<iostream>
#include<unordered_map>
using namespace std;
//NAive Method :- Time complexity :O((n-k)*k*k) Auxiliary Space :O(1)
void countDistinctNaive(int arr[],int n,int k){
    for(int i=0;i<=n-k;i++){
        int count=0;
        for(int j=0;j<k;j++){
            bool flag = false;
            for(int p=0;p<j;p++){
                if(arr[i+j] == arr[i+p]){
                    flag = true;
                    break;
                }
            }
            if(!flag)
                count++;
        }
        cout<<count<<"\t";
    }
}
//Efficient Method :- Time compelxity :O(n) Auxiliary space :O(k)
void countDistinct(int arr[],int n,int k){
    unordered_map<int,int> freq_map;
    //Insert element of first window and there frequency
    for(int i=0;i<k;i++)
        freq_map[arr[i]]++;
    cout<<freq_map.size()<<"\t";
    //preparing frequency map of other windows
    for(int i=k;i<n;i++){
        freq_map[arr[i-k]]--;
        if(freq_map[arr[i-k]] == 0)
            freq_map.erase(arr[i-k]);
        freq_map[arr[i]]++;
        cout<<freq_map.size()<<"\t";
    }
}
int main(){
    int arr[] = {10,20,20,10,30,40,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    cout<<"Distinct Element in Every Window of Size k(k="<<k<<") : \n";
    countDistinctNaive(arr,n,k);
    cout<<endl;
    countDistinct(arr,n,k);
    return 0;
}