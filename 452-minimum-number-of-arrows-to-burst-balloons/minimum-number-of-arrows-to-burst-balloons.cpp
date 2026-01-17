class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0) return 0;

        sort(points.begin(), points.end(),
             [&](const vector<int>& a, const vector<int>& b){
                 return a[0] < b[0];
             });

        int ans = 1;
        int lase = points[0][1];

        for(int i = 1; i < n; i++){
            if(points[i][0] <= lase){
                lase = min(lase, points[i][1]);
            } else {
                ans++;
                lase = points[i][1];
            }
        }
        return ans;
    }
};
