class Solution {
public:
    set<vector<int>> ans;
    vector<int> num;

    void find(int ind, int prev, vector<int> &ta){
        if(ind == num.size()){
            if(ta.size() >= 2) ans.insert(ta);
            return;
        }

        // not take
        find(ind + 1, prev, ta);

        // take
        if(num[ind] >= prev){
            ta.push_back(num[ind]);
            find(ind + 1, num[ind], ta);
            ta.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        num = nums;
        vector<int> ta;
        find(0, INT_MIN, ta);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};