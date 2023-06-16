// We are given a row-wise sorted matrix of size r*c, we need to find the median of the matrix given. 
// It is assumed that r*c is always odd.

#include<iostream>
using namespace std;

const int r = 3,c = 5;

//Naive Approach :-Time complexity :O(r*c.log(r*c)) Auxilary space :O(r*c)
//If we use quickselection for small optimization of this method ...Time :O(r*c) 
int findMedianNaive(int mat[][c]){
    //array to store all elements of matrix :
    int arr[r*c];
    int index = 0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            arr[index++] = mat[i][j];
    }
    //sort array 
    sort(arr,arr+(r*c));
    int medPos = (r*c)/2;

    return arr[medPos];
}
/*An efficient approach for this problem is to use a binary search algorithm. The idea is that for a number 
to be median there should be exactly (n/2) numbers that are less than this number. So, we try to find the 
count of numbers less than all the numbers. Below is the step by step algorithm for this approach: 
Algorithm:  

1.First, we find the minimum and maximum elements in the matrix. The minimum element can be easily found 
by comparing the first element of each row, and similarly, the maximum element can be found by comparing 
the last element of each row.
2.Then we use binary search on our range of numbers from minimum to maximum, we find the mid of 
the min and max and get a count of numbers less than or equal to our mid. And accordingly change the 
min or max.
3.For a number to be median, there should be (r*c)/2 numbers smaller than that number. So for every 
number, we get the count of numbers less than that by using upper_bound() in each row of the matrix, 
if it is less than the required count, the median must be greater than the selected number, else the 
median must be less than or equal to the selected number.
*/

//Effiecent Methof :-Time complexity :O(r.㏒(max-min).㏒(c)) Auxilary space :O(1)
int findMedian(int mat[][c]){
    int min = INT_MAX,max = INT_MIN;
    //finding min and max from matrix
    for(int i=0;i<r;i++){
        if(mat[i][0]<min)
            min = mat[i][0];
        if(mat[i][c-1]>max)
            max = mat[i][c-1];
    }
    int medPos = (r*c + 1)/2;
    //binary search approach : 
    while(min<max){
        int mid = min + (max-min)/2;
        int midPos = 0;
        // The upper bound function will take log(c) time and is performed for each row ∴ O(r*㏒c)
        for(int i=0;i<r;i++){
            midPos += upper_bound(mat[i],mat[i]+c,mid) - mat[i]; 
        }
        
        if(midPos<medPos)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
int main(){
    int matrix[r][c] = {{5,10,20,30,40},
                        {1,2,3,4,6},
                        {11,13,15,17,19}};
    cout<<"Matrix : "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<"\nMedian of matrix : "<<findMedianNaive(matrix)<<endl;
    cout<<"\nMedian of matrix : "<<findMedian(matrix)<<endl;
    return 0;
}



