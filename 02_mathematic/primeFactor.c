#include<stdio.h>
#include<math.h>

int isPrime(int n){
    if(n==1){
        return 0;
    }
    if(n==2 || n==3){
        return 1;
    }
    if(n%2==0 || n%3==0){
        return 0;
    }
    for(int i=5;i<=sqrt(n);i+=6){
        if(n%i==0 || n%(i+2)==0){
            return 0;
        }
    }
    return 1;
}
//Naive method :
void primefactor1(int n){
    //Corner case i.e.,n=0, n=1
    if(n<=1){
        return;
    }
    for(int i=2;i<n;i++){
        if(isPrime(i)){
            int x = i;
            while(n%x==0){
                printf("%d\t",i);
                x = x*i;
            }
        }
    }
} 
//Efficient method :
void primefactor2(int n){
    //Corner case i.e.,n=0, n=1
    if(n<=1){
        return;
    }
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            printf("%d\t",i);
            n = n/i;
        }
    }
    if(n>1){
        printf("%d\t",n);
    }
} 
//MORE Efficient method :
void primefactor3(int n){
    if(n<=1){
        return;
    }
    while(n%2==0){
        printf("%d\t",2);
        n = n/2;
    }
    while(n%3==0){
        printf("%d\t",3);
        n = n/3;
    }
    for(int i=5;i<=sqrt(n);i+=6){
        while(n%i==0){
            printf("%d\t",i);
            n = n/i;
        }
        while(n%(i+2)==0){
            printf("%d\t",i+2);
            n = n/(i+2);
        }
    }
    if(n>3){
        printf("%d\t",n);
    }
} 
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    primefactor1(n);
    primefactor2(n);
    primefactor3(n);
    return 0;
}