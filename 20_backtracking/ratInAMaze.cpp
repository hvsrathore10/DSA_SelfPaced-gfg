/*
Problem :: A Maze is given as N*N binary matrix of blocks where source block 
is the upper left most block i.e., maze[0][0] and destination block is lower 
rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to 
reach the destination. The rat can move only in two directions: forward and down.
*/ 

#include<iostream>
using namespace std;

// Time Complexity: O(2^(n²)) =>The recursion can run upper-bound 2^(n^2) times.
// Space Complexity: O(n^2). 
// Output matrix is required so an extra space of size n*n is needed.
class Solution{
    int N;
    int **maze,**sol;

    void printMaze();
    bool isSafe(int row,int col);
    bool solveRec(int row,int col);

    public:
        Solution(int size,vector< vector<int> > &tempMaze){
            N = size;
            maze = new int*[N];
            sol = new int*[N];
            for(int i=0;i<N;i++){
                maze[i] = new int[N];
                sol[i] = new int[N];
            }
            
            //fill maze and sol array 
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    maze[i][j] = tempMaze[i][j];
                    sol[i][j] = 0;
                }
            }
        }
        bool solve(){
            if(solveRec(0,0) == false)
                return false;
            else{
                printMaze();
                return true;
            }
        }
};

void Solution::printMaze(){
    cout<<"Path taken by Rat to reach destination :: "<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<sol[i][j]<<" ";
        
        cout<<endl;
    }
}
bool Solution::isSafe(int row,int col){
    return (row<N && col<N && maze[row][col]==1);
}
bool Solution::solveRec(int row,int col){
    if(row==N-1 && col==N-1){
        sol[row][col] = 1;
        return true;
    }
    if(isSafe(row,col)){
        sol[row][col] = 1;

        if(solveRec(row+1,col))
            return true;
        else if(solveRec(row,col+1))
            return true;
        
        sol[row][col] = 0;
    }
    return false;
}
int main(){
    vector< vector<int> > maze{ {1,0,0,0},
                            {1,1,0,1},
                            {0,1,0,0},
                            {1,1,1,1} };
    int N = maze.size();

    Solution obj(N,maze);
    cout<<"Rat can reach destination :: "<<(obj.solve()? "Yes" : "No")<<endl;
    return 0;
}