#include<stdio.h>
#include<math.h>
// Naive Method :
// Method 1: Time complexity : O(k)
void isSet1(int n,int k){
    int x=1;
    for(int i=0;i<k-1;i++){
        x = x*2;
    }
    if((n&x) != 0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}
//Method 2: Time complexity : O(k)
void isSet2(int n,int k){
    for(int i=0;i<k-1;i++){
        n = n/2;
    }
    if((n&1) != 0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}
//Efficiect Method :
// Method 1 : With  LEFT-SHIFT approach === n*pow(2,k-1)
void isSetBitwise1(int n,int k){
    if(n&(1<<(k-1))){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}
// Method 2 : With  RIGHT-SHIFT approach  === ⌊n/pow(2,k-1)⌋
void isSetBitwise2(int n,int k){
    if((n>>(k-1))&1){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}
int main()
{
    int n,k;
    printf("Enter value of n : n--> ");
    scanf("%d",&n);
    printf("Enter the order to be check : k--> ");
    scanf("%d",&k);

    isSet1(n,k);
    isSet2(n,k);
    isSetBitwise1(n,k);
    isSetBitwise2(n,k);
    return 0;
}

// Time complesity of pow(n,k-1) is : O(k)