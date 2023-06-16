#include<stdio.h>
//Time complexity :O(n)
//Auxiliary space :O(n)
int isPalindrome(char *str,int start,int end){
    if(start>=end){
        return 1;
    }
    return ((str[start]==str[end]) && isPalindrome(str,start+1,end-1));
}

int main()
{
    char str[] = {'g','e','e','g'};
    int n = sizeof(str)/sizeof(str[0]);

    printf("%s\n",(isPalindrome(str,0,n-1)? "True" : "False"));
    return 0;
}
