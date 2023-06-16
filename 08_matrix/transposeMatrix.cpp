#include<iostream>
using namespace std;

const int n = 3;
//Naive method : Required Extra space : O(n*n)
void transpose(int mat[][n]){
    int temp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            temp[i][j] = mat[j][i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            mat[i][j] = temp[i][j];
    }   
}
//Efficent Method : Inplace and One traversal
void Transpose(int mat[][n]){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            swap(mat[i][j],mat[j][i]);
    }
}
int main(){
    int matrix[n][n];
    //initialize matrix : 
    cout<<"Enter elements for 3X3 matrix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    }
    cout<<"The original matrix : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<"The Transpose of matrix : "<<endl;
    // transpose(matrix);
    Transpose(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}