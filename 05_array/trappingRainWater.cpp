//Important : INTERVIEW QUESTION 
#include<iostream>
using namespace std;
//Naive Method :-  *Time complexity :ϴ(n^2)  *Auxiliary space :ϴ(1)
int trappedWaterNaive(int *arr,int n){
    int water = 0;
    for(int i=1;i<n-1;i++){
        int lmax = arr[i];
        for(int j=0;j<i;j++){
            lmax = max(lmax,arr[j]);
        }
        int rmax = arr[i];
        for(int j=i+1;j<n;j++){
            rmax = max(rmax,arr[j]);
        }
        water = water + (min(lmax,rmax) - arr[i]);
    }
    return water;
}
//Efficient Meyhod :-  *Time complexity :ϴ(n)  *Auxiliary space :ϴ(n)
int trappedWater(int *arr,int n){
    int water=0;
    int lmax[n],rmax[n];

    lmax[0] = arr[0];
    for(int i=1;i<n;i++){
        lmax[i] = max(arr[i],lmax[i-1]);
    }
    rmax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i] = max(arr[i],rmax[i+1]);
    }
    for(int i=1;i<n-1;i++){
        water = water + (min(lmax[i],rmax[i]) - arr[i]);
    }
    return water;
}
int main(){
    int arr[] = {10,5,2,7,1,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Amount of water trapped : "<<trappedWaterNaive(arr,n)<<"Unit"<<endl;
    cout<<"Amount of water trapped : "<<trappedWater(arr,n)<<"Unit"<<endl;
    return 0;
}


/*Note :
For a programmer Time complexity and Space complexity both are important factor which
need to be taken case while writing any programmer/Algorithm,but Time complexity 
is give more importances for better user experience Therefor Method 2 is better 
for TRAPPING RAIN WATER PROBLEM which take Time_complexity :ϴ(n).
*/ 
