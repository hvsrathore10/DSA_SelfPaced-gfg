#include<iostream>
using namespace std;

const int R=3,C=3;

//Function to print Snake Pattern :
void snakePattern(int mat[][C]){
    for(int i=0;i<R;i++){
        if(i%2==0){
            for(int j=0;j<C;j++)
                cout<<mat[i][j]<<" ";
        }
        else{
            for(int j=C-1;j>=0;j--)
                cout<<mat[i][j]<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int matrix[R][C];
    //initialization of matrix :
    cout<<"Enter element of matrix : "<<endl;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cin>>matrix[i][j];
    snakePattern(matrix);
    return 0;
}