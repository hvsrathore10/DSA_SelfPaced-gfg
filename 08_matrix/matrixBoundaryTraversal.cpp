#include<iostream>
using namespace std;

const int R=4,C=4;

void bTraversal(int mat[][C]){
    cout<<"Output : ";
    //Base case if matrix have only singal ROW
    if(R==1){
        for(int i=0;i<C;i++)
            cout<<mat[0][i]<<" ";
    }
    //Base case if matrix have only singal COLUMN
    else if(C==1){
        for(int i=0;i<R;i++)
            cout<<mat[i][0]<<" ";
    }
    else{
        //First row of matrix : 
        for(int i=0;i<C;i++)
            cout<<mat[0][i]<<" ";
        //Last column of matrix :
        for(int i=1;i<R;i++)
            cout<<mat[i][C-1]<<" ";
        //Last row of matrix :
        for(int i=C-2;i>=0;i--)
            cout<<mat[R-1][i]<<" ";
        //First column of matrix : 
        for(int i=R-2;i>=1;i--)
            cout<<mat[i][0]<<" ";
    }
}
int main(){
    int matrix[R][C];
    //initialization of matrix :
    cout<<"Enter element of matrix : "<<endl;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cin>>matrix[i][j];
    
    bTraversal(matrix);
    return 0;
}