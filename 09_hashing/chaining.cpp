#include<iostream>
#include<list>
using namespace std;
 
struct MyHash{
    /* data */
    int m;
    list<int> *hashTable;
    //Like Constructor : 
    MyHash(int bucketSize){
        m = bucketSize;
        hashTable = new list<int> [m];
    }

    void insert(int key){
        int i = key%m;
        hashTable[i].push_back(key);
    }
    bool search(int key){
        int i = key%m;
        for(auto x : hashTable[i]){
            if(x==key)
                return true;
        }
        return false;
    }
    void remove(int key){
        int i = key%m;
        hashTable[i].remove(key);
    }
};

int main(){
    MyHash obj(7);
    obj.insert(72);
    obj.insert(71);
    obj.insert(15);
    obj.insert(50);
    obj.insert(99);
    cout<<"50 is present (true/false) : "<<obj.search(50)<<endl;
    obj.remove(71);
    cout<<"71 is present (true/false) : "<<obj.search(71)<<endl;
    return 0;
}


