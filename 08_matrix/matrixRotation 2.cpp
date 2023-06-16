// Given a Square Matrix of dimension N * N. The task is to rotate the matrix in 
// anti-clock wise direction by 90 degrees.

#include<iostream>
using namespace std;

const int  N = 4;
//Using Extra space : *Time :O(N²) *Space :O(N²) (∵ temp[N][N])
void rotateMatrixNaive(int mat[][N]){
    int temp[N][N];
    //copy original matrix into temp matrix :
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            temp[i][j] = mat[i][j];

    //Update original matrix into required matrix :
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            mat[i][j] = temp[j][N-1-i];
    }
}
//In-place rotation : *Time :O(N²) *Space :O(1)
void rotateMatrix(int mat[][N]){
    //cosider all square groups : 
    for(int i=0;i<N/2;i++){
        //position of current element
        for(int j=i;j<N-i-1;j++){
            //store current cell in temp variable
            int temp = mat[i][j];
            //move value from right to top
            mat[i][j] = mat[j][N-1-i];
            //move value from bottom to right
            mat[j][N-1-i] = mat[N-1-i][N-1-j];
            //move value from left to bottom
            mat[N-1-i][N-1-j] = mat[N-1-j][i];
            //assign temp to left
            mat[N-1-j][i] = temp;
        }
    }
}
int main(){
    int matrix[N][N] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};
    cout<<"The Original Matrix : "<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<"After 90degree Anti-clockwise rotation : "<<endl;
    // rotateMatrixNaive(matrix);
    rotateMatrix(matrix);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}