class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        auto &v = mp[value];

        auto lb = lower_bound(v.begin(), v.end(), left);
        auto ub = upper_bound(v.begin(), v.end(), right);

        return ub - lb;
    }
};