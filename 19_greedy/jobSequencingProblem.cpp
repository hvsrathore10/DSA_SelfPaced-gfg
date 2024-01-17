/*🙂
Problem: Given an array of jobs where every job has a deadline and associated 
profit if the job is finished before the deadline. It is also given that every 
job takes a single unit of time, so the minimum possible deadline for any job 
is 1. How to maximize total profit if only one job can be scheduled at a time.
*/
#include<iostream>
using namespace std;

class Jobs{
    public:
        char jobId;
        int deadline,profit;
};

bool myCmp(Jobs a,Jobs b){
    return a.profit > b.profit;
}
//Time complexity :O(n²) and Auxiliary space :O(n)
int jobSequence(Jobs arr[],int n){
    //Sort Jobs in decreasing order of profit ::
    sort(arr,arr+n,myCmp);

    int maxProfil = 0;
    vector<Jobs> res;
    vector<bool> slot(n,false);

    // Iterate through all given jobs :
    for(int i=0;i<n;i++){
        // Find a free slot for this job (Note that we start
        // from the last possible slot) :
        for(int j=min(n,arr[i].deadline);j>0;j--){
            //slot found : 
            if(slot[j]==false){
                res.push_back(arr[i]);
                maxProfil += arr[i].profit;
                slot[j] = true;
                break;
            }
        }
    }

    cout<<"Following are selected Jobs :: \n";
    for(int i=0;i<res.size();i++){
        cout<<"JobId : "<<res[i].jobId<<"\tDeadline : "
        <<res[i].deadline<<"\tProfit :"<<res[i].profit<<endl;
    }
    return maxProfil;
}
int main(){
    Jobs arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                    {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);

    int profit = jobSequence(arr,n);
    cout<<"Maximum Profit : "<<profit<<endl;
    return 0;
}