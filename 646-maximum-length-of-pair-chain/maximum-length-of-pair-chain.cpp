class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end() , [&](const vector<int> &a , const vector<int> &b){return a[1]<b[1];});

        int n = pairs.size();
        int ans =1;
        int back = pairs[0][1];
        for(int i =1;i<n;i++){
            if(pairs[i][0]>back){
                back=pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};