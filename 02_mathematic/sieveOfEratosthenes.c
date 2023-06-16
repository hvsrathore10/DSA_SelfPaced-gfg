#include<stdio.h>
#include<math.h>

void allPrimeNumber(int n){
    int prime[n+1];
    //set all as true in array prime[]
    for(int i=2;i<=n;i++){
        prime[i]=1;
    }
    for(int i=2;i<=sqrt(n);i++){
            for(int j=i*i;j<=n;j+=i){
                prime[j] = 0;
            }
    }    
    for(int i=2;i<=n;i++){
        if(prime[i]){
            printf("%d\t",i);
        }
    }
}

int main() {
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    allPrimeNumber(n);
    return 0;
}