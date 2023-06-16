#include<iostream>
using namespace std;
//Time Complexity : ϴ(2^n - 1)
//Auxiliary Space : ϴ(2^n - 1)
//Number of Moment required = ((2^n) - 1)   --->pow(2,n) - 1
void towerOfHanoi(int ndisk,char sour,char temp,char dest){
    if(ndisk==1){
        cout<<ndisk<<" disk is moved "<<sour<<"-->"<<dest<<endl;
        return;
    }
    towerOfHanoi(ndisk-1,sour,dest,temp);
    cout<<ndisk<<" disk is moved "<<sour<<"-->"<<dest<<endl;
    towerOfHanoi(ndisk-1,temp,sour,dest);
}
int main(){
    int n;
    char sour='A',temp='B',dest='C';
    cout<<"Enter number of disks : ";
    cin>>n;

    towerOfHanoi(n,sour,temp,dest);
    return 0;
}

/*Rules :
1.Only one disk can move at a time.
2.No larger disk can be placed on smaller disk.
3.Only top disk can be move from a tower.
*/