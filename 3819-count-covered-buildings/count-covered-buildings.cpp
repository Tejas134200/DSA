class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
     unordered_map<int, vector<int>> rows, cols;

    for (auto& b : buildings) {
        rows[b[0]].push_back(b[1]);
        cols[b[1]].push_back(b[0]);
    }

    // Sort all rows and cols
    for (auto& r : rows) {
        sort(r.second.begin(), r.second.end());
    }
    for (auto& c : cols) {
        sort(c.second.begin(), c.second.end());
    }

    int count = 0;
    for (auto& b : buildings) {
        int x = b[0], y = b[1];

        auto& row = rows[x];
        auto& col = cols[y];

        // Check left: any column < y
        bool hasLeft = lower_bound(row.begin(), row.end(), y) != row.begin();

        // Check right: any column > y
        bool hasRight = upper_bound(row.begin(), row.end(), y) != row.end();

        // Check above: any row < x
        bool hasAbove = lower_bound(col.begin(), col.end(), x) != col.begin();

        // Check below: any row > x
        bool hasBelow = upper_bound(col.begin(), col.end(), x) != col.end();

        if (hasLeft && hasRight && hasAbove && hasBelow) {
            count++;
        }
    }

    return count;
    }
};