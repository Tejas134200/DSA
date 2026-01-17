class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        for (int i = 0; i < houses.size(); i++) {
            int l = 0, r = heaters.size() - 1;

            while (l < r) {
                int m = l + (r - l) / 2;
                if (heaters[m] < houses[i]) l = m + 1;
                else r = m;
            }

            int dist = abs(heaters[l] - houses[i]);
            if (l > 0)
                dist = min(dist, abs(heaters[l - 1] - houses[i]));

            ans = max(ans, dist);
        }
        return ans;
    }
};
