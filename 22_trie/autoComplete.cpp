#include<iostream>
using namespace std; 

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 

// trie node 
struct TrieNode { 
    TrieNode *children[ALPHABET_SIZE]; 
    bool isEnd; 
    TrieNode(){
        isEnd = false;
        for(int i=0;i<ALPHABET_SIZE;i++)
            children[i] = NULL;
    }
}; 

// If not present, inserts key into trie. If the 
// key is prefix of trie node, just marks leaf node 
void insert(TrieNode *root, const string key) { 
    TrieNode *pCrawl = root; 

    for (int level = 0; level < key.length(); level++){ 
        int index = key[level] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = new TrieNode(); 

        pCrawl = pCrawl->children[index]; 
    } 

    // mark last node as leaf 
    pCrawl->isEnd = true; 
} 

// Returns true if key presents in trie, else false 
bool search(TrieNode *root, const string key) { 
    int length = key.length(); 
    TrieNode *pCrawl = root; 
    for (int level = 0; level < length; level++) { 
        int index = key[level] - 'a';

        if (pCrawl->children[index] == NULL) 
            return false; 

        pCrawl = pCrawl->children[index]; 
    } 

    return (pCrawl != NULL && pCrawl->isEnd); 
} 

// Returns 0 if current node has a child 
// If all children are NULL, return 1. 
bool isEmpty(struct TrieNode* root) { 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return false; 
    return true; 
} 

// Recursive function to print auto-suggestions for given node. 
void suggestionsRec(struct TrieNode* root, string currPrefix) { 
    // found a string in Trie with the given prefix 
    if (root->isEnd) { 
        cout << currPrefix; 
        cout << endl; 
    } 

    // All children struct node pointers are NULL 
    if (isEmpty(root)) 
        return; 

    for (int i = 0; i < ALPHABET_SIZE; i++){ 
        if (root->children[i]){ 
            // append current character to currPrefix string 
            currPrefix.push_back(97 + i); 

            // recur over the rest 
            suggestionsRec(root->children[i], currPrefix); 
        } 
    } 
} 

// print suggestions for given query prefix. 
int printAutoSuggestions(TrieNode* root, const string query) { 
    TrieNode* pCrawl = root; 

    // Check if prefix is present and find the 
    // the node (of last level) with last character 
    // of given string. 
    int level; 
    int n = query.length();
    for (level = 0; level < n; level++){ 
        int index = query[level] - 'a'; 

        // no string in the Trie has this prefix 
        if (pCrawl->children[index] == NULL) 
            return 0;

        pCrawl = pCrawl->children[index]; 
    } 

    // If prefix is present as a word. 
    bool isWord = (pCrawl->isEnd == true); 

    // If prefix is last node of tree (has no children) 
    bool isLast = isEmpty(pCrawl); 

    // If prefix is present as a word, but 
    // there is no subtree below the last 
    // matching node. 
    if (isWord && isLast){ 
        cout << query << endl; 
        return -1; 
    } 

    // If there are are nodes below last 
    // matching character. 
    if (!isLast){ 
        string prefix = query; 
        suggestionsRec(pCrawl, prefix); 
        return 1; 
    } 
    return -1;
} 

int main() { 
    TrieNode* root = new TrieNode(); 
    insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell"); 
    insert(root, "cat");
    insert(root, "a");
    insert(root, "hel"); 
    insert(root, "help");
    insert(root, "helps"); 
    insert(root, "helping"); 
    int comp = printAutoSuggestions(root, "hel"); 

    if (comp == -1) 
        cout << "No other strings found with this prefix\n"; 

    else if (comp == 0) 
        cout << "No string found with this prefix\n"; 

    return 0; 
} 
// Time Complexity: O(N*L) where N is the number of words in the trie and 
// L is the length of the longest word in the trie.
// Auxiliary Space: O(N*L+N * ALPHABET_SIZE)

