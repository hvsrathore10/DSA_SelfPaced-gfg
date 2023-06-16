#include<stdio.h>
//Naive Method :- Time complexity :ϴ(n^2)
void printOddOccurring1(int *arr,int n){
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                cnt++;
            }
        }
        if(cnt%2!=0){
            //third for-loop is required if we have oddOccurring of a number greater than 1.
            int tempcnt=0;
            for(int k=i;k>=0;k--){
                if(arr[i]==arr[k]){
                    tempcnt++;
                }
            }
            if(tempcnt==1){         
                printf("%d\t",arr[i]);
            }
        }
    }
}
//Efficient Method :- Time complexity :O(n)
void printOddOccurring2(int *arr,int n){
    int x=0;
    for(int i=0;i<n;i++){
        x = x^arr[i];
    }
    int k = x&(~(x-1));  //-->important expression  
    int xor1,xor2;
    xor1 = xor2 = 0;
    for(int i=0;i<n;i++){
        if((k&arr[i]) != 0){
            xor1 = xor1^arr[i];
        }
        else{
            xor2 = xor2^arr[i];
        }
    }
    printf("\nTow Odd Occurring number are : %d and %d\n",xor1,xor2);
}

int main()
{
    int arr[] = {2,2,6,3,6,5,4,4,5,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printOddOccurring1(arr,n);
    printOddOccurring2(arr,n);
    return 0;
}
