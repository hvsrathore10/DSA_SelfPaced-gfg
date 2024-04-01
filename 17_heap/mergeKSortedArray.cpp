/*Promble Statement :Given k sorted arrays of possibly different sizes, merge 
them and print the sorted output.
Examples: 
Input: k = 3 
      arr[][] = { {1, 3},
                  {2, 4, 6},
                  {0, 9, 10, 11}} ;
Output: 0 1 2 3 4 6 9 10 11 
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// A pair of pairs, first element is going to
// store value arr[i][j], second element index of array(row)
// and third element index in the array(column).
typedef pair<int, pair<int, int> > ppi;


//Super-Naive Method :- Time complexity :O(n*k.log(n*k)) & Auxiliary space :O(1)
void mergeKArrays1(vector< vector<int> > v,int K){
    vector<int> res;
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
            res.push_back(v[i][j]);
    }

    sort(res.begin(),res.end());

    cout<<"Merged Array 1: ";
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
}

//Naive Method :- Time complexity :O(n*k) & Auxiliary space :O(n)
vector<int> mergeArray(vector<int> a,vector<int> b){
    vector<int> arr;

    int i = 0,j = 0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            arr.push_back(a[i]);
            i++;
        }
        else{
            arr.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()){
        arr.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        arr.push_back(b[j]);
        j++;
    }

    return arr;
}
void mergeKArrays2(vector< vector<int> > v,int K){
    vector<int> res = v[0];

    for(int i=1;i<v.size();i++)
        res = mergeArray(res,v[i]);
    
    cout<<"Merged Array 2: ";
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
}

//Efficent Method :- Time complexity :O(n.㏒k)
void mergeKArray3(vector< vector<int> > arr,int K){
    vector<int> output;
    //Min Heap that store element,row_number,column_index
    priority_queue< ppi,vector<ppi>,greater<ppi> > pq;

    //insert first element of every row -> O(K.㏒K)
    for(int i=0;i<K;i++)
        pq.push({arr[i][0],{i,0}});
    
    //store sorted element in output vector
    while(!pq.empty()){
        ppi curr = pq.top();
        pq.pop();

        // i ==> Array Number
        // j ==> Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);
        if(j+1 < arr[i].size())
            pq.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
    }

    cout<<"Merged Array 3: ";
    for(int i=0;i<output.size();i++)
        cout<<output[i]<<" ";
    cout<<endl;
}

int main(){
    int k = 3;
    vector<int> v1 = {1,3};
    vector<int> v2 = {2,4,6};
    vector<int> v3 = {0,9,10,11};

    vector< vector<int> > arr;
    arr.push_back(v1);
    arr.push_back(v2);
    arr.push_back(v3);

    mergeKArrays1(arr,k);
    mergeKArrays2(arr,k);
    mergeKArray3(arr,k);
    return 0;
}