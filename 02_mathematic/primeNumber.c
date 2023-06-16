#include<stdio.h>
#include<math.h>

//Naive method :
int isPrime1(int n){
    int flage=1;
    if(n==1){
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            flage=0;
            return flage;
        }
    }
    return flage;
}
//Efficient method :
int isPrime2(int n){
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
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    if(isPrime2(n)){
        printf("%d is a prime number\n",n);
    }
    else{
        printf("%d is not a prime number\n",n);
    }
    return 0;
}
