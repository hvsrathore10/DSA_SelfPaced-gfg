//Problem description : Give an unsorted array and sum.We have to find a pair which give same sum as give sum.
//If sum is present return true else return false.
#include<iostream>
#include<unordered_set>
using namespace std;

//Naive Approach : Time complexity :O(n²)  -->Maximum no. of pairs = n*(n-1)/2
bool pairSumNaive(int arr[],int n,int sum){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i]+arr[j])==sum)
                return true;
        }
    }
    return false;
}
//Efficient Mathod : [Two pointer approach :O(n.logn)] *Better using Hashing O(n)
bool pairSum(int arr[],int n,int sum){
    unordered_set<int> h;
    for(int i=0;i<n;i++){
        if(h.find(sum-arr[i]) != h.end())
            return true;
        else
            h.insert(arr[i]);
    }
    return false;
}
int main(){
    int arr[] = {5,8,-3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 3;

    // printf("%s \n",pairSumNaive(arr,n,sum)? "True" : "False");
    printf("%s \n",pairSum(arr,n,sum)? "True" : "False");
    return 0;
}

/*One approach : put all element in hashTable and then search for 
   required pair. example : arr[] = {8,3,4,2,5} and sum = 6
   hashtable = [8,3,4,2,5]
   Know when we find such pair return True else return false.
   This approach does not work every time such for above case 
   it will return true for (3+3)but no such pair present in array. */