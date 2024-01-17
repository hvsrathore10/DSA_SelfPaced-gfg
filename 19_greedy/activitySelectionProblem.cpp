/*🙂
Problem : You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single 
person, assuming that a person can only work on a single activity at a time. 
*/
#include<iostream>
using namespace std;

bool myCmp(pair<int,int> a,pair<int,int> b){
    int finishA = a.second;
    int finishB = b.second;

    return finishA < finishB;
}
//Time complexity :O(n.㏒n) and Auxiliary space :O(1)
void activitySelection(vector< pair<int,int> > act){
    sort(act.begin(),act.end(),myCmp);

    cout<<"Following activities are selected "<<endl;

    int prev = act[0].second;
    cout<<act[0].first<<"\t"<<act[0].second<<endl;
    for(int curr = 1;curr<act.size();curr++){
        if(prev <= act[curr].first){
            cout<<act[curr].first<<"\t"<<act[curr].second<<endl;
            prev = act[curr].second;
        }
    }
}
int main(){
    vector< pair<int,int> > activity;
    // {{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}}
    activity.push_back(make_pair(5,9));
    activity.push_back(make_pair(1,2));
    activity.push_back(make_pair(3,4));
    activity.push_back(make_pair(0,6));
    activity.push_back(make_pair(5,7));
    activity.push_back(make_pair(8,9));

    activitySelection(activity);

    return 0;
}