#include<iostream>
using namespace std;
 
// Time complexity ::O(N!) and Auxiliary space :O(N²)
class NQueen{
    int N;
    int **board;
    void printMatrix();
    bool isSafe(int row,int col);
    bool solveRec(int col);

    public:
        NQueen(int numberOfQueens){
            N = numberOfQueens;
            board = new int*[N];

            for(int i=0;i<N;i++)
                board[i] = new int[N];

            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++)
                    board[i][j] = 0;
            }
        }
        bool solve(){
            if(solveRec(0) == false)
                return false;
            else{
                printMatrix();
                return true;
            }
        }
};

void NQueen::printMatrix(){
    cout<<"Board after placing Queens :: "<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
//Check weather perversly placed queen attack this queue
bool NQueen::isSafe(int row,int col){
    //check weather row is safe to place queen 
    for(int i=0;i<col;i++){
        if(board[row][i])
            return false;
    }
    //check weather diagonal wise is safe to place the queen
    //Upper Diagonal ::
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j])
            return false;
    }
    
    //Lower Diagonal ::
    for(int i=row,j=col;i<N && j>=0;i++,j--){
        if(board[i][j])
            return false;
    }
        
    return true;
}
//Time complexity ::O(N!) and Auxiliary space :O(N²)
bool NQueen::solveRec(int col){
    if(col == N)
        return true;
    for(int i=0;i<N;i++){
        if(isSafe(i,col) == true){
            board[i][col] = 1;

            if(solveRec(col+1))
                return true;
            //if solveRec() return false then backtrack ::
            board[i][col] = 0;
        }
    }
    return false;
}
int main(){
    NQueen obj(5);

    if(obj.solve())
        cout<<"Queen can place safely :: Yes"<<endl;
    else
        cout<<"Queen can place safely :: No"<<endl;
    return 0;
}