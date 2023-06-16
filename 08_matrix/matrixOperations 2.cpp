#include<iostream>
using namespace std;

const int m = 3,n = 2;

void Addition(int A[][n],int B[][n]){
    int C[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }
}
void Subtraction(int A[][n],int B[][n]){
    int C[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            C[i][j] = B[i][j] - A[i][j];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }
}
void Multiplication(int A[][n],int B[][m]){
    int C[m][m];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            C[i][j] = 0;
            for(int k=0;k<n;k++)
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }
}
void trace(int A[][n]){
    int tr = 0;
    //Finding Trace of matrix :   tr(matrix) = a11 + a22 + a33;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            if(i==j)
                tr += A[i][j];
    }
    cout<<"Trace of matrix : "<<tr<<endl;
}
int main(){
    int A[m][n],B[m][n];
    // initialize Matrix A and B : 
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            A[i][j] = 1 + i + j;
            B[i][j] = 6 + i + j;
        }
    }
    cout<<"Matrix Addition : C = A + B "<<endl;
    Addition(A,B);
    cout<<"Matrix Subtraction : C = B - A "<<endl;
    Subtraction(A,B);

    int X[m][n] = {{1,2},{3,4},{5,6}};
    int Y[n][m] = {{1,1,1},{1,1,1}};
    cout<<"Matrix Multiplication : Z = X.Y "<<endl;
    Multiplication(X,Y);
    return 0;
}