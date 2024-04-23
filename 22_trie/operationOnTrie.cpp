#include<iostream>
using namespace std;

struct TrieNode {
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i=0;i<26;i++)
            child[i] = NULL;
    }
};
// M -> key.lenght()
// Time complexity :O(M) and memory requirements of Trie is 
// O(ALPHABET_SIZE * key_length * N) where N is the number of keys in Trie.
bool search(TrieNode *root,string key){
    TrieNode *curr = root;
    for(int i=0;i<key.length();i++){
        int index = key[i] - 'a';
        if(curr->child[index]==NULL)
            return false;
        curr = curr->child[index];
    }
    return curr->isEnd;
}
//Time complexity :O(M)
void insert(TrieNode *root,string &key){
    TrieNode *curr = root;
    for(int i=0;i<key.size();i++){
        int index = key[i] - 'a';
        if(curr->child[index] == NULL)
            curr->child[index] = new TrieNode();
        curr = curr->child[index];
    }
    curr->isEnd = true;
}
//Time complexity :O(M)
bool isEmpty(TrieNode *root){
    for(int i=0;i<26;i++)
        if(root->child[i] != NULL)
            return false;
        
    return true;
}
TrieNode *delKey(TrieNode *root,string key,int i){
    if(root == NULL)
        return NULL;
    
    if(i == key.length()){
        // This node is no more end of word after removal of given key
        root->isEnd = false;
        // If given is not prefix of any other word
        if(isEmpty(root)){
            delete(root);
            root = NULL;
        }
        return root;
    }
    // If not last character, recur for the child
    // obtained using ASCII value
    int index = key[i] - 'a';
    root->child[index] = delKey(root->child[index], key, i+ 1);

    // If root does not have any child (its only child got 
    // deleted), and it is not end of another word.
    if (isEmpty(root) && root->isEnd == false) {
        delete (root);
        root = NULL;
    }

    return root;
}


int main(){
    // Input keys (use only 'a' through 'z' and lower case)
    string keys[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };
    int n = sizeof(keys)/sizeof(keys[0]);

    TrieNode* root = new TrieNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";

    root = delKey(root,"heroplane",0);
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}