#include <iostream>
#include "Trie.hpp"
using namespace std;

int main() {
    Trie t;
    t.insertWord("and");
    t.insertWord("and");
    t.insertWord("and");
    
    cout << t.search("and") << endl;

    t.removeWord("and");
    cout << t.search("and") << endl;
}

/*
The main reason of using Trie over hashmap is better Space Complexity and faster searching

Trie is actually a string algorithm

There are two types of tries:
1. Compressed Trie --> better space optimization
2. Suffix Tries (add all possible suffix of the word) --> faster string pattern matching
*/