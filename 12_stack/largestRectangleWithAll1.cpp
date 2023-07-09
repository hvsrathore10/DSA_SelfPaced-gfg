#include<iostream>
using namespace std;

//Nive Approach :- Time complexity :O(R³ * C³)
/*Algorithm : 1.Consider every cell as starting point
            2.Consider all size of rectangle with current cell as a starting
            3.For current rectangle check if it as all 1's.If yes update res if current size is greater 
*/

int largestHisto(int arr[],int n){
    int res = 0;
    for(int i=0;i<n;i++){
        int count = arr[i];
        //find left greater or equal bar
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i]) count += arr[i];
            else break;
        }
        //find right greater or equal bar
        for(int j=i+1;j<n;j++){
            if(arr[j]>=arr[i]) count += arr[i];
            else break;
        }
        res = max(res,count);
    }
    return res;
}
//Efficient Solution :- Time complexity :O(R*C) and Auxiliary space :O(C)
int findRect(int arr[][4],int n){
    int res = largestHisto(arr[0],n);
    for(int r=1;r<n;r++){
        for(int c=0;c<n;c++){
            if(arr[r][c] == 1)
                arr[r][c] += arr[r-1][c];
        }
        res = max(res,largestHisto(arr[r],n));
    }
    return res;
}
int main(){
    int arr[4][4] = {{0,1,1,0},
                    {1,1,1,1},
                    {1,1,1,1},
                    {1,1,0,0}};
    cout<<"Largest Rectangualar With All 1's : "<<findRect(arr,4)<<endl;
    
    return 0;
}