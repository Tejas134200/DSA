class Solution {
public:
    struct Trie{
            bool end = false;
            Trie* child[26]={};
    };
    Trie* root;
    unordered_map<int,vector<string>> dp;
    string ss;

    void insert(string& w){
        Trie* cur = root;
        for(char c:w){
            if(!cur->child[c-'a']) cur->child[c-'a']=new Trie();
            cur=cur->child[c-'a'];
        }
        cur->end = true;
    }

vector<string> dfs(int idx) {
        if(dp.count(idx)) return dp[idx];
        vector<string> res;

        Trie* cur = root;
        for(int i = idx; i < ss.size(); i++) {
            int k = ss[i] - 'a';
            if(!cur->child[k]) break;
            cur = cur->child[k];

            if(cur->end) {
                string word = ss.substr(idx, i - idx + 1);
                if(i + 1 == ss.size()) {
                    res.push_back(word);
                } else {
                    for(string tail : dfs(i + 1)) {
                        res.push_back(word + " " + tail);
                    }
                }
            }
        }
        return dp[idx] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ss=s;
        root=new Trie();
        for(string& w:wordDict) insert(w);
        return dfs(0);
    }
};