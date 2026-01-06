struct Trie{
    bool end;
    Trie* links[26]={};
    Trie(){
        end=false;
    }

    void insert(string s,Trie* root){
        Trie* cur = root;
        for(char c:s){
            if(!cur->links[c-'a']) cur->links[c-'a']=new Trie();
            cur=cur->links[c-'a'];
        }
        cur->end = true;
    }
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root =new Trie();
    }
    bool search2(Trie* cur , int i , string word){
        if(i==word.size()) return cur->end;
        if(word[i]=='.'){
            bool ans = false;
            for(int ii =0;ii<26;ii++){
                if(cur->links[ii]){
                    ans=ans||search2(cur->links[ii],i+1,word);
                }
                if(ans) break;
            }
            return ans;
        }else{
            if(!cur->links[word[i]-'a']) return false;
            return search2(cur->links[word[i]-'a'],i+1,word);
        }
        return false;
    }
    void addWord(string word) {
        root->insert(word,root);
    }
    
    bool search(string word) {
        return search2(root , 0 , word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */