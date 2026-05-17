class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
    map<int,int> mp;
        for(auto v:logs){
            mp[v[0]]++;
            mp[v[1]]--;
        }
        int maxi =0 , ans =0,count=0;
        for(auto it:mp)
        {
           int year=it.first;
           int value=it.second;

           count+=value;

           if(count>maxi){
            maxi=count;
            ans=year;
           }
        }

        return ans;

    }
};