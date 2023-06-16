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
        int index = h;
        int i = 1;
        while(table[index]!=-1){
            if(table[index]==key)
                return true;
            
            index = (h + i*i)%cap;
            ++i;
            if(index==h)
                return false;
        }
        return false;
    }
    bool insert(int key){
        if(size==cap)
            return false;
        int h = hash(key);
        int index = h;
        int i = 1;
        while(table[index]!=-1 && table[index]!=2 && table[index]!=key){
            index = (h + i*i)%cap;
            ++i;
        }
        if(table[index] == key)
            return false;
        else{
            table[index] = key;
            size++;
            return true;
        }
    }
    bool erase(int key){
        int h = hash(key);
        int index = h;
        int i = 1;
        while(table[index]!=-1){
            if(table[index]==key){
                table[index] = -2;
                return true;
            }
        
            index = (h + i*i)%cap;
            ++i;
            if(index==h)
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
    mh.insert(50);
    mh.insert(700);
    mh.insert(76);
    mh.insert(85);
    mh.insert(92);
    mh.insert(73);
    mh.insert(101);
    mh.print();
    cout<<"Key(50) is present : "<<mh.search(50)<<endl;;
    mh.erase(700);
    cout<<"Key(700) is present : "<<mh.search(700)<<endl;
    mh.print();
    return 0;
}