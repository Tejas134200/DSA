class Solution {
public:
    struct BuildingPoint {
        int x;
        bool isStart;
        int height;
    };

    static bool cmp(BuildingPoint &a, BuildingPoint &b) {
        if (a.x != b.x)
            return a.x < b.x;

        int val1 = a.isStart ? -a.height : a.height;
        int val2 = b.isStart ? -b.height : b.height;

        return val1 < val2;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<BuildingPoint> points;

        for (auto &b : buildings) {
            points.push_back({b[0], true, b[2]});   
            points.push_back({b[1], false, b[2]});  
        }

        sort(points.begin(), points.end(), cmp);

        // height -> frequency
        map<int, int> heights;
        heights[0] = 1;

        int prevMaxHeight = 0;
        vector<vector<int>> ans;

        for (auto &p : points) {

            if (p.isStart) {
                heights[p.height]++;
            } else {
                heights[p.height]--;

                if (heights[p.height] == 0)
                    heights.erase(p.height);
            }

            int currentMaxHeight = heights.rbegin()->first;

            if (currentMaxHeight != prevMaxHeight) {
                ans.push_back({p.x, currentMaxHeight});
                prevMaxHeight = currentMaxHeight;
            }
        }

        return ans;
    }
};