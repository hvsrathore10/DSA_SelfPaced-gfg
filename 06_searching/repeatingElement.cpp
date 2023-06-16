/*Repeating Element :----
Rules : 
>Only one number is going to repeat in array.
>All number 0 to max(ele) must be present in array.
>Zero must be present in array.
    ∴ 0<=max(ele)<=n-2
Condition need to take care :
Time : O(n)
Space : O(1)
No modification with array
*/
#include<iostream>
using namespace std;
//Super Naive Method :  *Time : O(N²)  *Space :O(1)
int isRepeat1(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])
                return arr[i];
        }
    }
    return -1;
}
//Naive method : *Time : O(N*㏒N)  *Space : O(1)
int isRepeat2(int *arr,int n){
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1])
            return arr[i];
    }
    return -1;
}
//Efficient Method : *Time : O(N) *Space : O(N)
int isRepeat3(int *arr,int n){
    bool temp_arr[n-1];
    for(int i=0;i<n-2;i++){
        temp_arr[i] = false;
    }
    for(int i=0;i<n;i++){
        if(temp_arr[arr[i]]==true)
            return arr[i];
        temp_arr[arr[i]] = true;
    }
    return -1;
}
//Efficient Method : *Time : O(N)  *Space : O(1) -->With NO Modification in array
// -->1<=max(ele)<=n-1
/*int isRepeat(int *arr,int n){ 
    int slow = arr[0],fast = arr[0];
    //Phase 1 : fast = 2*slow (i.e,fast is moving 2time faster and slow and also cover 2's distance)
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow!=fast);

    //Phase 2 : Both fast and slow are moving with same speed.....
    slow = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}*/

//0<=max(ele)<=n-2
int isRepeat(int *arr,int n){
    int slow = arr[0]+1,fast = arr[0]+1;
    //Phase 1 : fast = 2*slow (i.e,fast is moving 2time faster and slow and also cover 2's distance)
    do{
        slow = arr[slow]+1;
        fast = arr[arr[fast]]+1;
    }while(slow!=fast);

    //Phase 2 : Both fast and slow are moving with same speed.....
    slow = arr[0];
    while(slow!=fast){
        slow = arr[slow]+1;
        fast = arr[fast]+1;
    }
    return slow-1;
}
int main(){
    int arr[] = {0,2,1,5,3,6,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Repeated Element is : "<<isRepeat1(arr,n)<<endl;
    cout<<"Repeated Element is : "<<isRepeat2(arr,n)<<endl;
    cout<<"Repeated Element is : "<<isRepeat3(arr,n)<<endl;
    cout<<"Repeated Element is : "<<isRepeat(arr,n)<<endl;
    return 0;
}