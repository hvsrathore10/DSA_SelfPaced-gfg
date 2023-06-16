#include<stdio.h>
#include"userlib.h"

// Time complesity : O(log(min(a,b)))
int GCD(int a,int b){
    if(b==0){
        return a;
    }
    return GCD(b,a%b);
}
// Naive Mathod :
int LCM1(int a,int b){
    int res = max(a,b);
    while(1){
        if(res%a==0 && res%b==0){
            return res;
        }
        res++;
    }
}
//Efficient Method : Time complesity : O(1)
int LCM2(int a,int b){
    return ((a*b)/GCD(a,b));
}
int main()
{
    int a,b;
    printf("Enter two number : ");
    scanf("%d %d",&a,&b);
    printf("GCD of %d and %d : %d\n",a,b,LCM1(a,b));
    printf("GCD of %d and %d : %d\n",a,b,LCM2(a,b));
    return 0;
}