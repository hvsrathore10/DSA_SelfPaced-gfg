//Question Find the Maxmum Appearing element for give ranges? *condition : 0<=left[i]<right[i]<100 & 0<=i<10
#include<iostream>
using namespace std;
// Naive Method :- *Time complexity :O(n*max)
int countFreqNaive(int *left,int *right,int n){
    int freq[100] = {0};
    for(int i=0;i<n;i++){
        for(int j=left[i];j<=right[i];j++){
            freq[j]++;
        }
    }
    int index=0;
    for(int i=1;i<100;i++){
        if(freq[i]>freq[i-1]){
            index = i;
        }
    }
    return index;
}
//Efficient Method :- *Time complexity :ϴ(n+max)
int countFreq(int *left,int *right,int n){
    int freq[101] = {0};
    for(int i=0;i<n;i++){
        freq[left[i]] = 1;
        freq[right[i]+1] = -1;
    }
    int index=0;
    for(int i=1;i<100;i++){
        freq[i] = freq[i-1] + freq[i];
        if(freq[i]>freq[index]){
            index = i;
        }
    }
    return index;
}
int main(){
    int left[] = {1,2,4};
    int right[] = {4,5,7};
    int n = sizeof(left)/sizeof(left[0]);
    cout<<"Maximum Apperaing Element in Range : "<<countFreqNaive(left,right,n)<<endl;
    cout<<"Maximum Apperaing Element in Range : "<<countFreq(left,right,n)<<endl;
    return 0;
}