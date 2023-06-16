// Description - Given an n x n matrix and a number x, find the position of x in the matrix. 
// In the given matrix, every row and column is sorted in increasing order. 
/*Approach : Idea is to solve problem with row and column elimination reducing the search space. Before jumping at the solution, lets try to understand the concept that is actually allowing us to solve the problem in linear time.
Let’s start our search from the top-right corner of the array. There are three possible cases.

The number we are searching for is greater than the current number. This will ensure, that all the elements in the current row is smaller than the number we are searching for as we are already at the right-most element and the row is sorted. Thus, the entire row gets eliminated and we continue our search on the next row. Here elimination means we won’t search on that row again.
The number we are searching for is smaller than the current number. This will ensure, that all the elements in the current column is greater than the number we are searching for. Thus, the entire column gets eliminated and we continue our search on the previous column i.e. the column at the immediate left.
The number we are searching for is equal to the current number. This will end our search.
k - starting row index
m - ending row index
l - starting column index
n - ending column index
i - iterator*/
#include<iostream>
using namespace std;
 
const int R=4,C=4;
//Naive mathod :- Time complexity :O(R*C)
void search(int matrix[][C],int key){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(matrix[i][j]==key){
                cout<<"Key Found : "<<i<<"*"<<j<<endl;
                return;
            }
        }
    }
    cout<<"Not found!!"<<endl;
}
//Efficient Method :- Time complexity :O(R+C)
void searchInRCS(int matrix[][C],int key){
    //Why we choosen top-right corner?
    //arrow to top-right corner
    int arrowleft = C-1,arrowdown=0;
    while((arrowleft >= 0) && (arrowdown < R)){
        if(matrix[arrowdown][arrowleft]==key){
            cout<<"Key Found : "<<arrowdown<<"*"<<arrowleft<<endl;
            return;
        }
        //move towards left
        else if(matrix[arrowdown][arrowleft]>key)
            arrowleft--;
        //move downward 
        else
            arrowdown++;
    } 
    cout<<"Not Found!!"<<endl;
}

int main(){
    int matrix[R][C] = {{10,20,30,40},
                        {15,25,35,45},
                        {27,29,37,49},
                        {32,33,39,50}};
    int x;
    cout<<"Enter element to search : ";
    cin>>x;
    search(matrix,x);
    // RCS - Row-wise and Column-wise sorted matrix
    searchInRCS(matrix,x);
    return 0;
}