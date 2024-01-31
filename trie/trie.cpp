class Trie {
public:
    struct trieNode {
        bool isEndOfWord;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }

    void insert(string word) {
        trieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == NULL) {
                curr->children[idx] = getNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        trieNode* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == NULL) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isEndOfWord == true;
    }

    bool startsWith(string prefix) {
        trieNode* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            int idx = ch - 'a';
            if (curr->children[idx] == NULL) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true; // Move this line outside the for loop
    }
};

