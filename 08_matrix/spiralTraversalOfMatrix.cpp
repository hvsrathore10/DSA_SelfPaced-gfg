#include<iostream>
using namespace std;
const int R = 4,C = 4;

void spiralTraversal(int mat[][C]){
    int top=0,left=0,bottom=R-1,right=C-1;
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++)
            cout<<mat[top][i]<<" ";
        top++;
        for(int i=top;i<=bottom;i++)
            cout<<mat[i][right]<<" ";
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--)
                cout<<mat[bottom][i]<<" ";
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--)
                cout<<mat[i][left]<<" ";
            left++;
        }
    }
}
int main(){
    int matrix[R][C] = {{1,2 ,3 ,4 },
                        {5,6 ,7 ,8 },
                        {9,10,11,12},
                        {12,13,14,15}};

    cout<<"The original Matrix : "<<endl;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Output : "<<endl;
    spiralTraversal(matrix);
    return 0;
}