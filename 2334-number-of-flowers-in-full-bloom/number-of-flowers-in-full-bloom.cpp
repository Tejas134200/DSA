class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> mp;
        for(auto it:flowers){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        vector<int> peo= people;
        sort(people.begin(),people.end());

        int cur = 0;
        unordered_map<int,int> m;
        auto it = mp.begin();
        for(int i:people){
            while(it!=mp.end()&&it->first<=i){
                cur+=it->second;
                it++;
            }
            m[i]=cur;
        }
        vector<int> ans;
        for(int i:peo) ans.push_back(m[i]);
        return ans;
    }
};