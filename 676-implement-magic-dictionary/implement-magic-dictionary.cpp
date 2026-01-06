class MagicDictionary {
public:
    struct Trie {
        bool end = false;
        Trie* child[26] = {};
    };

    Trie* root;

    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string& w : dictionary) {
            Trie* cur = root;
            for(char c : w) {
                int i = c - 'a';
                if(!cur->child[i]) cur->child[i] = new Trie();
                cur = cur->child[i];
            }
            cur->end = true;
        }
    }

    bool dfs(Trie* node, string& s, int idx, bool used) {
        if(idx == s.size())
            return used && node->end;

        int k = s[idx] - 'a';
        if(node->child[k]) {
            if(dfs(node->child[k], s, idx + 1, used))
                return true;
        }
        if(!used) {
            for(int i = 0; i < 26; i++) {
                if(i != k && node->child[i]) {
                    if(dfs(node->child[i], s, idx + 1, true))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool search(string searchWord) {
        return dfs(root, searchWord, 0, false);
    }
};
