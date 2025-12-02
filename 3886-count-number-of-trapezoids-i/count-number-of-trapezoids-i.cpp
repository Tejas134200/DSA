class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int mod = 1e9+7;
        long long ans = 0;

        sort(points.begin(), points.end(),
             [&](const vector<int>& a, const vector<int>& b){
                 return a[1] < b[1];
             });

        int n = points.size();
        long long count = 0;
        int i = 0;

        while (i < n) {
            int prev = points[i][1];
            long long co = 0;

            while (i < n && points[i][1] == prev) {
                co++;
                i++;
            }

            long long lines = (co * (co - 1)) / 2;
            ans = (ans + (lines % mod) * (count % mod)) % mod;
            count = (count + lines) % mod;
        }

        return ans;
    }
};
