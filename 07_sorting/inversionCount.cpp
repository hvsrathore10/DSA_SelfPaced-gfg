//Inversion Count for an array indicates :– How far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is the maximum. 
#include<iostream>
using namespace std;
//Naive Method : Time Complexity : O(n²)
void inversionCountNaive(int arr[],int n){
    int inv_count = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<" ";
                inv_count++;
            }
        }
    }
    cout<<"\nInversion Count : "<<inv_count<<endl;
}
//Inversion Count using MERGESORT : 

// This function merges two sorted arrays and returns inversion count in the arrays.
int merge(int arr[], int temp[], int left, int mid,int right){
	int i, j, k;
	int inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) 
			temp[k++] = arr[i++];
		
		else {
			temp[k++] = arr[j++];
			// this is tricky -- see above
			// explanation/diagram for merge()
			inv_count = inv_count + (mid - i);
		}
	}
	// Copy the remaining elements of left subarray(if there are any) to temp
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	// Copy the remaining elements of right subarray(if there are any) to temp
	while (j <= right)
		temp[k++] = arr[j++];

	// Copy back the merged elements to original array
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}
// An auxiliary recursive function that sorts the input array and returns the number of inversions in the array.
int mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		// Divide the array into two parts and
		// call mergeSort And CountInv()
		// for each of the parts
		mid = (right + left) / 2;

		// Inversion count will be sum of
		// inversions in left-part, right-part
		// and number of inversions in merging
		inv_count += mergeSort(arr, temp, left, mid);
		inv_count += mergeSort(arr, temp, mid + 1, right);

		// Merge the two parts
		inv_count += merge(arr, temp, left, mid + 1 , right);
	}
	return inv_count;
}
// This function sorts the input array and returns the number of inversions in the array.
//Time complexity : O(n.㏒n) *Auxiliary Space : O(n) [for Temporary array]
int inversionCount(int arr[], int array_size){
	int temp[array_size];
	return mergeSort(arr, temp, 0, array_size - 1);
}

int main(){
    int arr[] = {1,20,6,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    inversionCountNaive(arr,n);
    cout<<"Inversion Count : "<<inversionCount(arr,n)<<endl;
    return 0;
}

// Note: The above code modifies (or sorts) the input array. If we want to count only inversions, we need to create a copy of the original array and call mergeSort() on the copy to preserve the original array’s order.


