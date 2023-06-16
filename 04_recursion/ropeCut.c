//Discription : Given a rope of length N meters, and the rope can be cut in only 3 sizes A, B and C. The task is to maximizes the number of cuts in rope. If it is impossible to make cut then print -1.
#include<stdio.h>
int max(int x,int y){
    if(x>=y)
        return x;
    else
        return y;
}
//Time complexity : O(3^n) Space Complexity : O(n), due to recursive call stack.
int ropeCut(int n,int a,int b,int c){
    if(n==0)
        return 0;
    if(n<0)
        return -1;
    //check all possible cuts on rope and select maximum value.
    int res = max(ropeCut(n-a,a,b,c),max(ropeCut(n-b,a,b,c),ropeCut(n-c,a,b,c)));

    if(res==-1)
        return -1;
    return res + 1;
}
 
int main()
{
    int n,a,b,c;
    printf("Enter a length of ROPE : n--> ");
    scanf("%d",&n);
    printf("Enter value for a ,b and c respectively : ");
    scanf("%d %d %d",&a,&b,&c);

    printf("Rope can cut into %d number of pices\n",ropeCut(n,a,b,c));
    return 0;
}

/*Important NOTE :
1.Time complexity of this problem depend on all perameter ie, n ,a ,b ,c. -->UPPER BOUND = O(3^n)
2.It can be solved by Dynamic Programming as well.
*/