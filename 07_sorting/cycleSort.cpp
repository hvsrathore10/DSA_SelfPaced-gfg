/*Note : 
1.A worst case O(n²) sorting algorithm
2.It does minimum memeory writes and can be useful for case where memory write is costly (EEP-ROM)
3.In-place and not stable 
*4.Usful to solve question like find minimum swap required to sort an array
*/
#include<iostream>
using namespace std;
//Time complxity : O(n²)
void cycleSort(int arr[],int n){
    for(int cs=0;cs<n-1;cs++){        //cs - cycle_start
        int item = arr[cs];
        int pos = cs;
        for(int i=cs+1;i<n;i++){
            if(arr[i]<item)
                pos++;
        }
        swap(item,arr[pos]);
        while(pos!=cs){
            pos = cs;
            for(int i=cs+1;i<n;i++){
                if(arr[i]<item)
                    pos++;
            }
            swap(item,arr[pos]);
        }
    }
}
int main(){
    int arr[] = {50,60,70,10,20,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before CycleSort : "<<endl;
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    cout<<"Array After CycleSort : "<<endl;
    cycleSort(arr,n);
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
