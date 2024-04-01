/*Problem :Given a number of pages in N different books and M students. The books
are arranged in ascending order of the number of pages. Every student is assigned
to read some consecutive books. The task is to assign books in such a way that 
the maximum number of pages assigned to a student is minimum. */

#include<iostream>
using namespace std;
//Utility Function for finding SUM for element  
int sum(int arr[],int b, int e){
    int s=0;
    for(int i=b;i<=e;i++)
        s+=arr[i];
    return s;
}
//Naive Approach :-Time complexit :O(N².K) and Auxiliary Space :O(1)
int minPages(int arr[],int n, int k){
    if(k==1)
        return sum(arr,0,n-1);
    if(n==1)
        return arr[0];
    int res=INT_MAX;
    for(int i=1;i<n;i++){
        res=min(res,max(minPages(arr,i,k-1),sum(arr,i,n-1)));
    }
    return res;
}
//Dynamic Programming Base Approach :-
// Time compelxity :
int minPages_DP(int arr[],int n,int k){
    int dp[k+1][n+1];

    for(int i=1;i<=n;i++)
        dp[1][i] = sum(arr,0,i-1);
    for(int i=1;i<=k;i++)
        dp[i][1] = arr[0];
    
    for(int i=2;i<=k;i++) {
        for(int j=2;j<=n;j++) {
            int res = INT_MAX;
            for(int p=1;p<j;p++)
                res = min(res,max(dp[i-1][p],sum(arr,p,j-1)));
            
            dp[i][j] = res;
        }
    }
    return dp[k][n];
} 
//Efficient Approach :-Binary Search Based :Time complexity :O(N.logN)
bool isPossible(int arr[], int n, int m, int curr_min){
	int studentsRequired = 1;
	int curr_sum = 0;

	// iterate over all books
	for (int i = 0; i < n; i++) {
		// check if current number of pages are greater
		// than curr_min that means we will get the result
		// after mid no. of pages
		if (arr[i] > curr_min)
			return false;

		// count how many students are required
		// to distribute curr_min pages
		if (curr_sum + arr[i] > curr_min) {
			// increment student count
			studentsRequired++;

			// update curr_sum
			curr_sum = arr[i];

			// if students required becomes greater
			// than given no. of students,return false
			if (studentsRequired > m)
				return false;
		}
		// else update curr_sum
		else
			curr_sum += arr[i];
	}
	return true;
}

// function to find minimum pages
int minPages_BST(int arr[], int n, int m){
	long long sum = 0;

	// return -1 if no. of books is less than
	// no. of students
	if (n < m)
		return -1;

	// Count total number of pages
	for (int i = 0; i < n; i++)
		sum += arr[i];

	// initialize start as 0 pages and end as
	// total pages
	int start = 0, end = sum;
	int result = INT_MAX;

	// traverse until start <= end
	while (start <= end) {
		// check if it is possible to distribute
		// books by using mid as current minimum
		int mid = (start + end) / 2;
		if (isPossible(arr, n, m, mid)) {
			// update result to current distribution
			// as it's the best we have found till now.
			result = mid;

			// as we are finding minimum and books
			// are sorted so reduce end = mid -1
			// that means
			end = mid - 1;
		}

		else
			// if not possible means pages should be
			// increased so update start = mid + 1
			start = mid + 1;
	}
	// at-last return minimum no. of pages
	return result;
}
int main(){
    int pages[] = {12, 34, 67, 90};
    int n = sizeof(pages)/sizeof(pages[0]);
    int k = 2; // k -> no. of student

    cout<<minPages(pages,n,k)<<endl;
    cout<<minPages_DP(pages,n,k)<<endl;
    cout<<minPages_BST(pages,n,k)<<endl;
    return 0;
}