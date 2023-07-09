// Description : Create a data structure kStacks that represents k stacks. Implementation of 
// kStacks should use only one array, i.e., k stacks should use the same array for storing elements. 
#include<iostream>
using namespace std;

struct kStack{
    int *arr;
     //array's top and next are alway of integer types weather 'arr' is of employees, students,etc type 
    int *top,*next;
    //cap = size of array ,k = no. of stack we want to implement
    int cap,k,free_top;  

    //constructor
    kStack(int n,int nStack){
        free_top = 0;
        cap = n; 
        k = nStack;
        arr = new int[cap];
        top = new int[k];
        fill(top,top+k,-1);
        
        next = new int[cap];
        for(int i=0;i<cap-1;i++)
            next[i] = i+1;
        next[cap-1] = -1;
    }

    void push(int sn,int x){ 
        if(free_top == -1){
            cout<<"\nStack Overflow\n";
            return;
        }
        
        int index = free_top; // Store index of first free slot
        // Update index of free slot to index of next slot in free list
        free_top = next[index];
        // Update next of top and then top for stack number 'sn'
        next[index] = top[sn];
        top[sn] = index;
        // Put the item in array
        arr[index] = x;
    }
    int pop(int sn){
        // Underflow check
	    if (isEmpty(sn)){
		    cout << "\nStack Underflow\n";
		    return INT_MAX;
	    }

        // Find index of top item in stack number 'sn'
        int index = top[sn];

        top[sn] = next[index]; // Change top to store next of previous top
        // Attach the previous top to the beginning of free list
        next[index] = free_top;
        free_top = index;
        // Return the previous top item
        return arr[index];
    }
    bool isEmpty(int sn){
        return (top[sn] == -1);
    }
};
int main(){
    // Let us create 3 stacks in an array of size 10
	int k = 3, n = 10;
	kStack ks(n, k);

	// Let us put some items in stack number 2
	ks.push(2, 15);
	ks.push(2, 45);

	// Let us put some items in stack number 1
	ks.push(1, 17);
	ks.push(1, 49);
	ks.push(1, 39);

	// Let us put some items in stack number 0
	ks.push(0, 11);
	ks.push(0, 9);
	ks.push(0, 7);

	cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
	cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
	cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    return 0;
}

