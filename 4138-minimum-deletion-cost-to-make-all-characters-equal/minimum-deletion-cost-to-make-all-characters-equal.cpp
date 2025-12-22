class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long tsum =0;
        vector<long long> hm(26,0);
        int n = s.size();
        for(int i =0;i<n;i++){
            hm[s[i]-'a']+=cost[i];
            tsum +=cost[i];
        }
        long long mini =tsum;
        for(int i =0;i<26;i++){
            mini = min(mini,tsum-hm[i]);
        }
        return mini;


        
    }
};