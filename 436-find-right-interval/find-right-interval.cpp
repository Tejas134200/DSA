class Solution {
public:
    vector<vector<int>> inte;

    int bs(int tar){
        int l = 0;
        int r = inte.size() - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(inte[m][0] < tar) l = m + 1;
            else r = m - 1;
        }
        if(l >= inte.size()) return -1;
        return inte[l][1];
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        inte.resize(n);

        for(int i = 0; i < n; i++){
            inte[i].push_back(intervals[i][0]);
            inte[i].push_back(i);
        }

        sort(inte.begin(), inte.end(), [&](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        int maxs = inte[n - 1][0];
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(intervals[i][1] > maxs) ans.push_back(-1);
            else ans.push_back(bs(intervals[i][1]));
        }

        return ans;
    }
};
