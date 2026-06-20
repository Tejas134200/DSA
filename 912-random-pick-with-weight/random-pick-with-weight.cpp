class Solution {
public:
    vector<int> pref;
    int total;

    Solution(vector<int>& w) {

        int sum = 0;

        for(int x : w) {
            sum += x;
            pref.push_back(sum);
        }

        total = sum;
    }

    int pickIndex() {

        int r = rand() % total + 1;

        return lower_bound(pref.begin(),
                           pref.end(),
                           r) - pref.begin();
    }
};