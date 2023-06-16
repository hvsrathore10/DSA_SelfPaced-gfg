#include<iostream>
#include<unordered_map>
using namespace std;
//Naive Mathod :- Time complexity :O(n.㏒n) Auxiliary Space :O(1)
//But required modification of array
void countOccurenceNaive(int arr[],int n,int k){
    sort(arr,arr+n);
    int i=1,count=1;
    while(i<n){
        while(i<n && arr[i]==arr[i-1]){
            count++;
            i++;
        }
        if(count>n/k)
            cout<<arr[i-1]<<"\t";

        count = 1;
        i++;
    }
}
//Efficient Method :- Time complexity :ϴ(n) Auxiliary_Space :O(n)
void countOccurence(int arr[],int n,int k){
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
        map[arr[i]]++;
    for(auto x : map){
        if(x.second > n/k)
            cout<<x.first<<"\t";
    }
}
//Optimization in Efficient Method :- Time complexity :O(n.k) Auxiliary_Space :O(k-1)
//It is based on Moore Voting Algorithm approach
void countOcc(int arr[],int n,int k){
    unordered_map<int,int> map;
    //Time :-O(n.k)
    for(int i=0;i<n;i++){            //<----- O(n)
        if(map.find(arr[i]) != map.end())
            map[arr[i]]++;
        else if(map.size()<k)
            map[arr[i]]++;
        else{
            for(auto x : map){      //<--- O(k)
                x.second--;
                if(x.second==0)
                    map.erase(x.first);
            }
        }
    }
    //Check weather selected element have (count > n/k)
    //Worst case :O(k*n)
    for(auto x : map){          
        int count = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==x.first)
                count++;
        }
        if(count>n/k)
            cout<<x.first<<"\t";
    }
}
int main(){
    int arr[] = {30,10,20,20,10,20,30,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    cout<<"Element with more than n/k Occurences : \n";
    // countOccurenceNaive(arr,n,k);
    // countOccurence(arr,n,k);
    countOcc(arr,n,k);
    return 0;
}