/*C/C++ :
Six bitwise operator :
1.AND (&)
2.OR (|)
3.XOR (^)
4.LEFT-SHIFT(<<)
5.RIGHT-SHIFT(>>)
6.BITWISE-NOT (~)
*/


/*Java :
Seven bitwise operator :
1.AND (&)
2.OR (|)
3.XOR (^)
4.BITWISE-NOT (~)
5.LEFT-SHIFT(<<)
6.Signed RIGHT-SHIFT(>>)
7.Unsigned RIGHT-SHIFT(>>>)
*/
#include<stdio.h>
 
int main()
{
    int a=5,b=3;
    int x = 5;
    /*Bitwise AND(&) 
    a = 5 --> 000...0101
    b = 3 --> 000...0011
    a & b = 1 000...0001  */
    printf("AND -> %d\n",a&b);
    /*Bitwise OR(|)
    a = 5 --> 000...0101
    b = 3 --> 000...0011
    a | b = 7 000...0111  */
    printf("OR -> %d\n",a|b);
    /*Bitwise XOR(^)
    a = 5 --> 000...0101
    b = 3 --> 000...0011
    a ^ b = 6 000...0110   */
    printf("XOR -> %d\n",a^b);
    /*Left-Shift(<<)
    a = 5 --> 0000...0101
    a<<b = 40  0...0101000  */
    printf("LeftShift -> %d\n",a<<b);
    /*Right-Shift(>>)
    a = 5 --> 000...0101
    a>>b = 0  000...0000   
    */
   printf("RightShift -> %d\n",a>>b);
   /*Bitwise-NOT(~)
   x = 5   --> 000...0100
   ~x = -6   --> 111...1011  */
   printf("Bitwise_NOT -> %d\n",~x);
    return 0;
}
/*  For signed number c/c++ standered does not have any set of fix value it depended on compiler to compiler 
    but mostly compilers use 2's complement  */
    
