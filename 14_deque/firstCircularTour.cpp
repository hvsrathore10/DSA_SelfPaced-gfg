// Consider an arrangement where n petrol pumps are arranged in a circular manner. 
// We need to find the first petrol pump from where we can visit all petrol pumps 
// and come back to the petrol pump without ever going out of the petrol.
#include<iostream>
#include<deque>
using namespace std;

//Naive Approach :- Time complexity :O(n²) and Auxiliary space :O(1)
int firstLoop1(int *petrol,int *dist,int n){
    for(int start=0;start<n;start++){
        int curr_petrol = 0;
        int end = start;
        while(true){
            curr_petrol += (petrol[end] - dist[end]); 
            if(curr_petrol<0)
                break;
            
            end = (end+1)%n; //to maintain circular loop
            if(end == start)
                return start+1; 
        }
    }
    return -1;
}
//Better Approach :- Time complexity :O(n) and Auxiliary space :O(n)
int firstLoop2(int *petrol,int *dist,int n){
    deque<int> dq;
    int curr_petrol = 0;
    int index = 0;
    while(dq.size() != n && index!=n){
        curr_petrol += (petrol[index]-dist[index]);

        dq.push_back(index);
        while(curr_petrol<0){
            curr_petrol -= (petrol[dq.front()] - dist[dq.front()]);
            dq.pop_front();
        }
            
        index = (index+1)%n;
    }
    return (dq.empty()? -1 : (dq.front()+1));
}
// Instead of building a separate deque, we can use the array itself as a deque with 
// the help of start and end pointers by this Auxiliary space become O(1)



//Efficient Approach :- Time complexity :O(n) and Auxiliary space :O(1)
int firstLoop(int *petrol,int *dist,int n){
    int curr_petrol = 0;
    int prev_petrol = 0;
    int start = 0;
    for(int i=0;i<n;i++){
        curr_petrol += (petrol[i]-dist[i]);

        if(curr_petrol<0){
            start = i+1;
            prev_petrol += curr_petrol;
            curr_petrol = 0;
        } 
    }
    return ((curr_petrol+prev_petrol)>=0 ? start+1 : -1 );
}
int main(){
    int petrol[] = {50,10,60,100};
    int dist[] = {30,20,100,10};
    int n = sizeof(dist)/sizeof(dist[0]);

    cout<<"First circular loop : "<<firstLoop1(petrol,dist,n)<<endl;
    cout<<"First circular loop : "<<firstLoop2(petrol,dist,n)<<endl;
    cout<<"First circular loop : "<<firstLoop(petrol,dist,n)<<endl;
    return 0;
}