#include<stdio.h>
//Naive Method : 
//Time complexity : O(y)
//Auxiliary space : O(1)
int power(int x,unsigned int y){
    int pow=1;
    if(y==0){
        return 1;
    }
    for(int i=1;i<=y;i++){
        pow = pow*x;
    }
    return pow;
}
//Efficient Method : 
// Time complexity : O(log(y))
//Auxiliary space : O(log(y))
int powerRec(int x,unsigned int y){
    int temp;
    if(y==0){
        return 1;
    }
    /*if(y%2==0){
        return powerRec(x,y/2)*powerRec(x,y/2);
    }
    else{
        return x*powerRec(x,y/2)*powerRec(x,y/2);
    }*/
    temp = powerRec(x,y/2);
    if(y%2==0){
        return temp*temp;
    }
    else{
        return x*temp*temp;
    }
}
// Time complexity : O(log(y))
//Auxiliary space : O(1)
int powerIte(int x,unsigned int y){
    int res=1;
    while(y!=0){
        if((y&1)!=0){
            res = res*x;
        }
        y = y>>1;
        x = x*x;
    }
    return res;
}
int main()
{
    int x;
    unsigned int y;
    printf("Enter value for x and y respectively :\n");
    scanf("%d %d",&x,&y);
    printf("%d power %u is : %d\n",x,y,power(x,y));
    printf("%d power %u is : %d\n",x,y,powerRec(x,y));
    printf("%d power %u is : %d\n",x,y,powerIte(x,y));
    return 0;
}