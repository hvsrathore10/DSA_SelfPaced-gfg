#include<stdio.h>
#include"userlib.h"
//Naive method :  Time complesity : O(min(a,b))
int GCD1(int a,int b){
    int i = min(a,b);
    while(i>0){
        if(a%i==0 && b%i==0){
            break;
        }
        i--;
    }
    return i;
}
//Euclidean Algorithm : Time complesity : O(min(a,b))
int GCD2(int a,int b){
    while(a!=b){
        if(a>b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}
//optimisation of Euclidean Algorithm : Time complesity : O(log(min(a,b)))
int GCD3(int a,int b){
    if(b==0){
        return a;
    }
    return GCD3(b,a%b);
}

int main()
{
    int a,b;
    printf("Enter two number : ");
    scanf("%d %d",&a,&b);
    printf("GCD of %d and %d : %d\n",a,b,GCD1(a,b));
    printf("GCD of %d and %d : %d\n",a,b,GCD2(a,b));
    printf("GCD of %d and %d : %d\n",a,b,GCD3(a,b));
    return 0;
}