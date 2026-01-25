class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int,int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                int cost = (grid[x][y] == d + 1) ? 0 : 1;

                if (dist[nx][ny] > dist[x][y] + cost) {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
