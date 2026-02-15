class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> a(101,0);
        for(int i:bulbs) a[i]++;
        vector<int> ans;
        for(int i=0;i<101;i++) if(a[i]&1) ans.push_back(i);
        return ans;
    }
};