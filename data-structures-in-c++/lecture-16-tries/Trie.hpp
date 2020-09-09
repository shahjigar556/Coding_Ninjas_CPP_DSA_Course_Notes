#include <string>
#include "TrieNode.hpp"
using namespace std;

class Trie {
    TrieNode *root;

    public:
    Trie() {
        root = new TrieNode('\0');
    }

    private:
    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    public:
    // for user
    void insertWord(string word) {
        insertWord(root, word);
    }

    private:
    bool search(TrieNode *root, string word) {
        if(word.size() == 0) {
            return root->isTerminal;
        }
        
        int index = word[0] - 'a';
        if(root->children[index] != nullptr) {
            return search(root->children[index], word.substr(1));
        } else {
            return false;
        }
    }

    public:
    // for user
    bool search(string word) {
        // Write your code here
        return search(root, word);
    }

    private:
    void removeWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root->isTerminal = false;
            return;
        }

        // Small Calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if(root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            // word not found
            return;
        }
        removeWord(child, word.substr(1));

        // Remove child NOde if it is useless
        if(child->isTerminal == false) {
            for(int i = 0; i < 26; i++) {
                if(child->children[i] != nullptr) {
                    return;
                }
            }
            delete child;
            root->children[index] = nullptr; 
            // if we do not put null after deallocating child, then it will become a dangling pointer
        }
    }

    public:
    // for user
    void removeWord(string word) {
        removeWord(root, word);
    }
};