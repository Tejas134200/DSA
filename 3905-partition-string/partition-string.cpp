class Solution {
public:
    struct Trie {
        bool end = false;
        Trie* child[26] = {};
    };

    Trie* root;

    bool exists(string& s) {
        Trie* cur = root;
        for(char c : s) {
            int i = c - 'a';
            if(!cur->child[i]) return false;
            cur = cur->child[i];
        }
        return cur->end;
    }

    void insert(string& s) {
        Trie* cur = root;
        for(char c : s) {
            int i = c - 'a';
            if(!cur->child[i]) cur->child[i] = new Trie();
            cur = cur->child[i];
        }
        cur->end = true;
    }

    vector<string> partitionString(string s) {
        root = new Trie();
        vector<string> ans;
        string cur = "";

        for(char c : s) {
            cur.push_back(c);
            if(!exists(cur)) {
                ans.push_back(cur);
                insert(cur);
                cur.clear();
            }
        }
        return ans;
    }
};
