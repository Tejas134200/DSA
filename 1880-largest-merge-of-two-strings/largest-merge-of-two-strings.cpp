class Solution {
public:
    bool gre(string w , string s , int i , int j){
        while(i<w.size()&&j<s.size()){
            if(w[i]>s[j]) return true;
            else if(w[i]==s[j]) {i++;j++;}
            else return false;
        }
        return i<w.size();

    }
    string largestMerge(string word1, string word2) {
        int i = 0;
        int j =0 ;
        string ans = "";
        while(i<word1.size()&&j<word2.size()){
            if(word1[i]>word2[j]){
                ans+=word1[i++];
            }
            else if(word1[i]==word2[j]){
                ans+=word1[i];
                if(gre(word1 , word2 , i , j)) i++;
                else j++;
            }
            else ans+=word2[j++];
        }
        while(i<word1.size()) ans+=word1[i++];
        while(j<word2.size()) ans+=word2[j++];
        return ans;
    }
};