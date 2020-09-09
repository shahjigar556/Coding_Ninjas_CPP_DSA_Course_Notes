class TrieNode {
    public:
    char data;
    TrieNode **children; // pointer pointing to the array in heap which stores TrieNode pointers
    bool isTerminal; // to check whether any word ends here or not

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode*[26]; // as there are no more than 26 characters (only lower case), so, there can be max of 26 elements
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};