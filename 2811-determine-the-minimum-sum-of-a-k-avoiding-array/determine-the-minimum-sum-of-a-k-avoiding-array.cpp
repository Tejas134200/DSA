class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        ans.push_back(1);
        mp[1]=1;
        mp[0]=0;
        int cur = 2;
        int c = 1;
        
        while(c<n){
            if(mp[k-cur]>0) cur++;
            else{
                ans.push_back(cur);
                mp[cur]=1;
                cur++;
                c++;
            }
        }
        int s =0;
        for(int i:ans) s+=i;
        return s;
    }
};