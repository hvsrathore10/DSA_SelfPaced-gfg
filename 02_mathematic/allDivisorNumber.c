#include<stdio.h>
#include<math.h>
//Naive method : Time compelexity = O(n)
void divisor1(int n){
    if(n<1){
        return;
    }
    for(int i=1;i<=n;i++){
        if(n%i==0){
            printf("%d\t",i);
        }
    }
} 
//Efficienct method :  Time complexity = O(sqrt(n))
//With this method we will not able to maintain the order of divisor of a number eg: 51 --->1,51,3,17
void divisor2(int n){
    if(n<1){
        return;
    }
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            printf("%d\t",i);
            if(i!=n/i){
                printf("%d\t",n/i);
            }
        }
    }
}
// Time complexity = O(sqrt(n))
// Printing all the divisors in sorted order
void divisor3(int n){
    int i;
    if(n<1){
        return;
    }
    for(i=1;i<=sqrt(n);i++){
        if(n%i==0){
            printf("%d\t",i);
        }
    }
    for( ;i>=1;i--){
        if(n%i==0){
            printf("%d\t",n/i);
        }
    }
}
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    divisor1(n);
    divisor2(n);
    divisor3(n);
    return 0;
}