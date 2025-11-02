class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26,0);
        for(char c:s) cnt[c-'a']++;
        int odd=0;
        char middle=0;
        for(int i =0;i<26;i++){
            if(cnt[i]%2!=0){
                odd++;
                middle = i+'a';
            }

        }
        if(odd>1) return "";
        string half="";
        for(int i =0;i<26;i++){
            half.append(cnt[i]/2,'a'+i);
        }
        string res ="";
        bool found=false;

        function<bool(string&,vector<int>&,bool)> dfs=[&](string &cur,vector<int> &rem,bool isG){
            int len=half.size();
            if(cur.size()==len){
                string full=cur;
                if(odd==1) full+=middle;
                string rev=cur;
                reverse(rev.begin(),rev.end());
                full+=rev;
                if(full>target){
                    res=full;
                    return true;
                }
                return false;
            }
            int pos=cur.size();
            char limit = isG?'a':target[pos];
            for (char ch = limit; ch <= 'z'; ch++) {
                int i = ch - 'a';
                if (rem[i] == 0) continue;

                bool nextGreater = isG || ch > target[pos];

                rem[i]--;
                cur.push_back(ch);

                if (dfs(cur, rem, nextGreater)) return true;

                cur.pop_back();
                rem[i]++;
            }
            return false;


        };
        vector<int> rem(26);
        for(int i =0;i<26;i++) rem[i]=cnt[i]/2;
        string cur="";
        if(dfs(cur,rem,false)) return res;
        return "";
        
    }
};