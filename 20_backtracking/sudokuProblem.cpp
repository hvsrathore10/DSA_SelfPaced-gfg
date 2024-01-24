#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define N 9

void printGrid(int grid[N][N]){
    cout<<"Output Grid :: \n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
           cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}
bool isSafe(int grid[N][N],int row,int col,int value){
    for(int i=0;i<N;i++){
        if(grid[row][i]==value || grid[i][col]==value)
            return false;
    }
    int s = (int)sqrt(N);
    int rs = row - row%s;
    int cs = col - col%s; 
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++)
            if(grid[i+rs][j+cs] == value)
                return false;
    }
    return true;
}
bool solve(int grid[N][N]){
    int row = -1,col = -1;
    bool isEmpty = false;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if(isEmpty == true)
            break;
    }
    if(isEmpty == false)
        return true;
    
    for(int X=1;X<=N;X++){
        if(isSafe(grid,row,col,X) == true){
            grid[row][col] = X;
            if(solve(grid))
                return true;
            
            grid[row][col] = 0;
        }
    }
    return false;

}
int main(){
    int grid[N][N]={{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                    {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                    {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                    {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                    {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                    {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                    {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                    {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                    {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    
    if(solve(grid) == true)
        printGrid(grid);
    else
		cout << "No solution exists"; 
    return 0;
}