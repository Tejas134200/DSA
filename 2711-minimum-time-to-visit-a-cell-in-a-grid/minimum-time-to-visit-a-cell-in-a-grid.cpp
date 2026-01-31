class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // 🚨 Early impossible check
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0}); // time, row, col

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int t = cur[0], r = cur[1], c = cur[2];

            if (r == m-1 && c == n-1) return t;
            if (t > dist[r][c]) continue;

            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                int nt = t + 1;
                if (nt < grid[nr][nc]) {
                    int diff = grid[nr][nc] - nt;
                    if (diff % 2 == 0)
                        nt = grid[nr][nc];
                    else
                        nt = grid[nr][nc] + 1;
                }

                if (nt < dist[nr][nc]) {
                    dist[nr][nc] = nt;
                    pq.push({nt, nr, nc});
                }
            }
        }

        return -1;
    }
};
