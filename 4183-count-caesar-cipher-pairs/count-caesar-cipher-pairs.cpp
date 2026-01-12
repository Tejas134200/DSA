class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,long long> mp;
        for(auto& w:words){
            int shift = w[0]-'a';
            string noem = w;
            for(char& c:noem){
                c = (c-shift-'a'+26)%26+'a';
            }
            mp[noem]++;
        }
        long long ans =0;
        for(auto it:mp){
            long long c = it.second;
            cout<<c<<endl;
            ans+= (c*(c-1)/2);
        }
        return ans;
    }
};