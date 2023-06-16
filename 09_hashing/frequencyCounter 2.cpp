#include<iostream>
#include<unordered_map>
using namespace std;

//Naive Approach :-Timecomplexity : ϴ(n²) Auxiliary space :O(1)
void countFreqNaive(int arr[],int n){
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        int count = 1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])
                count++;
        }
        cout<<arr[i]<<" "<<count<<endl;
    }   
}
//Efficient Approach :-Timecomplexity : ϴ(n) Auxiliary space :O(n)
void countFreq(int arr[],int n){
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++)
        freq[arr[i]]++;

    for(auto e : freq)
        cout<<e.first<<" "<<e.second<<endl;
}
int main(){
    int arr[] = {10,12,15,20,10,10,12,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    countFreqNaive(arr,n);
    countFreq(arr,n);
    return 0;
}

