#include<stdio.h>
//Print Binary equavelent of a decimal number N :
// Time complexity :ϴ(logN)
void fun(int n){
    if(n==0){
        return;
    }
    fun(n/2);
    printf("%d",n%2);
}
// Print N to 1 (Tail recursion)
// Time Complexity :O(n)
// Auxiliary Space :O(n)
void printNumber(int n){
    if(n==0){
        return;
    }
    printf("%d\t",n);
    printNumber(n-1);
}
// Print 1 to N
// Time Complexity :O(n)
// Auxiliary Space :O(n)
void printReverseNumber(int n){
    if(n==0){
        printf("\n");
        return;
    }
    printReverseNumber(n-1);
    printf("%d\t",n);
}
//Tail Recursion :  ==>Tail call elimination
// NOT A TAIL RECURSION because to terminate foo(n) we required foo(n-1) function
int foo(int n){
    if(n==0 || n==1){
        printf("\n");
        return 1;
    }
    return (n*foo(n-1));     
}
// This one is TAIL RECURSION function
/*int foo(int n,int k){
    if(n==0 || n==1){
        return k;
    }
    return foo(n-1,k*n);
}*/
/*Advantage of TAIL RECURSION
  1.mordern compiler perform optimization to TailRecursion function
  2.Take Auxiliary space equal to O(1)
*/

//Time complxity : O(n)
// Auxiliary Space :O(n)   --->With the help of iterative approach auxiliary space will be O(1)
int sunOfNaturalNumber(int n){
    if(n==0){
        return 0;
    }
    return (n+sunOfNaturalNumber(n-1));
}
//Time complexity : O(log(n)) or ϴ(d)   d-->number of digits
//Auxiliary Space : O(log(n)) or ϴ(d)
int sumOfDigits(int n){
    if(n==0){
        return 0;
    }
    return ((n%10) + sumOfDigits(n/10));
}
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    fun(n);
    printf("\n");
    printNumber(n);
    printReverseNumber(n);
    printf("Factorial of %d is : %d\n",n,foo(n));
    printf("Sum : %d\n",sunOfNaturalNumber(n));
    printf("%d\n",sumOfDigits(253));
    return 0;
}