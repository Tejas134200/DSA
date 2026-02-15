class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string s:words){
            int sum = 0;
            for(char c:s){
                sum+=weights[c-'a'];
            }
            sum = sum%26;
            sum = 26-sum;
            ans+=char('a'+sum-1);
        }
        return ans;
    }
};