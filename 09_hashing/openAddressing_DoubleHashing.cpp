#include<iostream>
using namespace std;

struct MyHash{
    int cap;
    int size;
    int *table;
    MyHash(int capacity){
        cap = capacity;
        size = 0;
        table = new int[cap];
        for(int i=0;i<cap;i++)
            table[i] = -1;
    }
    //hash function
    int h1(int key){
        return key%cap;
    }
    int h2(int key){
        return ((cap-1) - (key%(cap-1)));
    }

    bool search(int key){
        int h = h1(key);
        int index = h;
        int i = 1;
        while(table[index]!=-1){
            if(table[index]==key)
                return true;
            
            index = (h + i*h2(key))%cap;
            ++i;
            if(index==h)
                return false;
        }
        return false;
    }
    bool insert(int key){
        if(size==cap)
            return false;
        int h = h1(key);
        int index = h;
        int i = 1;
        while(table[index]!=-1 && table[index]!=2 && table[index]!=key){
            index = (h + i*h2(key))%cap;
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
        int h = h1(key);
        int index = h;
        int i = 1;
        while(table[index]!=-1){
            if(table[index]==key){
                table[index] = -2;
                return true;
            }
        
            index = (h +i *h2(key))%cap;
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
    mh.insert(49);
    mh.insert(63);
    mh.insert(56);
    mh.insert(52);
    mh.insert(54);
    mh.insert(48);
    mh.print();
    cout<<"Key(56) is present : "<<mh.search(56)<<endl;;
    mh.erase(56);
    cout<<"Key(56) is present : "<<mh.search(56)<<endl;
    mh.print();
    return 0;
}