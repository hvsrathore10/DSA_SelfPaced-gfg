#include<stdio.h>
#include<math.h>
//Time Complexity = O(n.2^n)
void powerSet(char *set,int n){
    int powerSizeSet = pow(2,n);   //powerSizeSet = (1<<n);

    //'i' is use to print subset of powerSet generated from Set
    for(int i=0;i<powerSizeSet;i++){      //-->2^n
        //'j' is use to traverce the elements from Set 
        for(int j=0;j<n;j++){      //-->n
            if(i&(1<<j)){
                printf("%c",set[j]);
            }
        }
        printf("\n");
    }
} 
int main()
{
    char set[] = {'a','b','c','d'};
    int n = sizeof(set)/sizeof(set[0]);

    powerSet(set,n);
    return 0;
}