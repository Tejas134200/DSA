struct Trie {
    bool end = false;
    Trie* child[26] = {};

    void insert(string& s) {
        Trie* cur = this;
        for(char c : s) {
            int i = c - 'a';
            if(!cur->child[i]) cur->child[i] = new Trie();
            cur = cur->child[i];
        }
        cur->end = true;
    }
};

class Encrypter {
public:
    vector<string> m;                       
    unordered_map<string, vector<char>> mp; 
    Trie* root;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        m.resize(26, "");
        root = new Trie();

        for(int i = 0; i < keys.size(); i++) {
            m[keys[i] - 'a'] = values[i];
            mp[values[i]].push_back(keys[i]);
        }

        for(string& s : dictionary) {
            root->insert(s);
        }
    }

    string encrypt(string word1) {
        string ans;
        for(char c : word1) {
            if(m[c - 'a'] == "") return "";
            ans += m[c - 'a'];
        }
        return ans;
    }

    int dfs(string& w, int idx, Trie* node) {
        if(idx == w.size()) return node->end;

        string sub = w.substr(idx, 2);
        if(!mp.count(sub)) return 0;

        int cnt = 0;
        for(char c : mp[sub]) {
            int i = c - 'a';
            if(node->child[i]) {
                cnt += dfs(w, idx + 2, node->child[i]);
            }
        }
        return cnt;
    }

    int decrypt(string word2) {
        return dfs(word2, 0, root);
    }
};
