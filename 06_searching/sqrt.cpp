#include<iostream>
using namespace std;
//Naive method :- Time :O(√N) 
int findSqrtNaive(int n){
    int i=1;
    while(i*i<=n){
        i++;
    }
    return i-1;
}
// Efficient Method :- Time complexity : O(logN)
//Based on BinarySearch approach
int findSqrt(int n){
    if(n==0 || n==1){
        return n;
    }
    int low=1,high=n;
    int ans = 0;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(mid*mid == n){
            return mid;
        }
        else if(mid*mid>n){
            high = mid - 1;
        }
        else{
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Square root of "<<n<<" is : "<<findSqrt(n)<<endl;
    return 0;
}