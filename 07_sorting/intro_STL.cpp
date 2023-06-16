#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int main(){
    int arr[] = {10,50,30,1,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    //Sort() -->It is a Standered library of c++ which use IntroSort hybrid sort (Quick sort,Heap sort,Insertion sort)
    //sort(arr,arr+n) -->[arr-starting address location and [arr+n - ending address location on memory.
    sort(arr,arr+n);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    //sort(arr,arr+n,greater<int>()) -->[arr-starting address location and [arr+n - ending address location on memory and greater<int>() is a compression library function of c++ which sort array in decreasing order.
    sort(arr,arr+n,greater<int>());
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    
    vector<int> v = {10,30,5,40};
    //v.begin() - iterator of begining element of vector v
    //v.end() - iterator of end element of vector v
    sort(v.begin(),v.end());
    for(int x : v)
        cout<<x<<" ";
    cout<<endl;

    sort(v.begin(),v.end(),greater<int>());
    for(int x : v)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}