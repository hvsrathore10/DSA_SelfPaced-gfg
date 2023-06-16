#include <iostream>
#include <vector>
using namespace std;

void print1(int arr[3][2]){
    cout << "print1" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void print2(int arr[][2], int m){
    cout << "print2" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < 2; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void print3(int **arr, int m, int n){
    cout << "print3" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void print4(int *arr[], int m){
    cout << "print4" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m + i; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void print5(vector<int> arr[], int m){
    cout << "print5" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void print6(vector<vector<int>> &arr){
    cout << "print6" << endl;
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
int main(){
    // Fixed 2D array :
    int arr1[3][2] = {{2, 4},
                      {6, 8},
                      {10, 12}
                    };
    print1(arr1);
    // Variable 2D array :
    int m = 3, n = 2;
    int arr2[m][2];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            arr2[i][j] = i + j;
    print2(arr2, m);
    // Double Pointer Array :
    int **arr3;
    arr3 = new int *[m];
    for (int i = 0; i < m; i++){
        arr3[i] = new int[i + 1];
        for (int j = 0; j < i + 1; j++)
            arr3[i][j] = i;
    }
    print3(arr3, m, n);
    // Array of Pointer :
    int *arr4[m];
    for (int i = 0; i < m; i++){
        arr4[i] = new int[m + i];
        for (int j = 0; j < m + i; j++)
            arr4[i][j] = i + 1;
    }
    print4(arr4, m);
    // Array of Vector
    vector<int> arr5[m];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m + i; j++)
            arr5[i].push_back(m + i);
    }
    print5(arr5, m);
    // Vector of Vector
    vector<vector<int>> arr6;
    for (int i = 0; i < m; i++){
        vector<int> v;
        for (int j = 0; j < n; j++)
            v.push_back(10);

        arr6.push_back(v);
    }
    print6(arr6);

    return 0;
}

/*Different types of 2D Array representation :
1.Fixed Array
2.Veriable Array
3.Double pointer array
4.Array of Pointer
5.Array of vector
6.Vector of vector
*/