#include<stdio.h>
// Time complexity : O(d)
int isPalindrome(int n){
    int rem,rev=0,temp;
    temp = n;
    while(n!=0){
        rem = n%10;
        rev = rev*10 + rem;
        n = n/10;
    }
    return ((temp==rev)? 1 : 0);
}
 
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    if(isPalindrome(n)){
        printf("%d is a Palindrome number\n",n);
    }
    else{
        printf("%d is Not a Palindrome number\n",n);
    }
    return 0;
}