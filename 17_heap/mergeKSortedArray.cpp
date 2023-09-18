#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Super-Naive Method :- Time complexity :O(n*k.log(n*k))
void mergeKArrays1(vector< vector<int> > v,int K){
    vector<int> res;
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++)
            res.push_back(v[i][j]);
    }

    sort(res.begin(),res.end());

    cout<<"Merged Array : ";
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}
//Naive Method :- Time complexity :O()
vector<int> mergeArray(vector<int> a,vector<int> b){
    vector<int> arr;
    int i = 0,j = 0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[i]){
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
    
    cout<<"Merged Array : ";
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}

//Efficent Method :- Time complexity :O()
void mergeKArray3(vector< vector<int> > arr,int K){
    vector<int> res;
    //Min Heap that store element,row_number,index
    priority_queue< pair<int, pair<int,int> > > pq;

    //insert first element of every row
    for(int i=0;i<arr.size();i++)
        pq.push(make_pair(arr[i][0],make_pair(i,0)));
    
    //store sorted element in res vector
    while(!pq.empty()){
        res.push_back(pq.top().first);
        int row_num = pq.top().second.first;
        int index = pq.top().second.second + 1;

        pq.pop();
        if(row_num<K && index<arr[row_num].size())
            pq.push(make_pair(arr[row_num][index],make_pair(row_num,index)));
    }

    cout<<"Merged Array : ";
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}
int main(){
    
    return 0;
}