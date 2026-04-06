class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int> a;
        for(int i =1;i<min(1001,n);i++){
            a.push_back(i*i*i);
        }
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i =0;i<a.size();i++){
            for(int j=i;j<a.size();j++){
                if(a[i]+a[j]>n) break;
                mp[a[i]+a[j]]++;
                
            }
        }
        for(auto &it:mp) if(it.second>1) ans.push_back(it.first);
        sort(ans.begin(),ans.end());
        return ans;

    }

};