#include<iostream>
using namespace std;
 
struct MyHash{
    int cap;
    int size;
    int *table;
    //constructor : it will allocate memory for hashTable and set all position as -1
    MyHash(int capacity){
        cap = capacity;
        size = 0;
        table = new int[cap];
        for(int i=0;i<cap;i++)
            table[i] = -1;
    }
    //hash function
    int hash(int key){
        return key%cap;
    }

    bool search(int key){
        int h = hash(key);
        int i = h;
        while(table[i]!=-1){
            if(table[i]==key)
                return true;
            
            i = (i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }
    bool insert(int key){
        if(size==cap)
            return false;
        int i = hash(key);
        while(table[i]!=-1 && table[i]!=2 && table[i]!=key)
            i = (i+1)%cap;

        if(table[i] == key)
            return false;
        else{
            table[i] = key;
            size++;
            return true;
        }
    }
    bool erase(int key){
        int h = hash(key);
        int i = h;
        while(table[i]!=-1){
            if(table[i]==key){
                table[i] = -2;
                return true;
            }
        
            i = (i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }

    void print(){
        for(int i=0;i<cap;i++)
            cout<<table[i]<<" ";
        cout<<endl;
    }
};

int main(){
    MyHash mh(7);
    mh.insert(49);
    mh.insert(63);
    mh.insert(56);
    mh.insert(52);
    mh.insert(54);
    mh.insert(48);
    mh.insert(28);
    cout<<"key is present : "<<mh.search(56)<<endl;
    cout<<"delete 56 : "<<mh.erase(56)<<endl;
    cout<<"key is present : "<<mh.search(56)<<endl;
    mh.print();
    return 0;
}