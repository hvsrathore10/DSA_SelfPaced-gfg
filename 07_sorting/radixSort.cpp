/*Note : 
1.Stable
2.Time : O(d*(n+b)) 
3.Extra space : O(n+b)
4.Interesting facts : Time and ExtraSpace of radixSort are inversely proportional to each other,i.e. if base(b) increase space increase count[b] and time decrease 
5.RadixSort is better than countSort for higher oder of k (k - range of number in array)
*/
#include<iostream>
using namespace std;

void countSort(int arr[],int n,int exp){
    int count[10] = { 0 };
    int output[n];
    //Counting occurring of element in array
    for(int i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++){
        count[i] = count[i] + count[i-1];
    }
    //Completing output[]
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    //coyp output[] <--> arr[]
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}
//Time complexity : O(d*(n+b))   ===> d=no. of digits, n=sizeof arr, b=base (10 in this case)
void radixSort(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max)
            max = arr[i];
    }
    for(int exp=1;max/exp>0;exp*=10)
        countSort(arr,n,exp);
}
int main(){
    int arr[] = {319,6,50,8,100,221};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before Sorting : "<<endl;
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    cout<<"Array after Sorting : "<<endl;
    radixSort(arr,n);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}


