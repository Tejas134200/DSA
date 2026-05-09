class Solution {
public:
    int n, m;

    vector<vector<int>> arr;
    vector<int> x, y;

    bool dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        if (i == n - 1 && j == m - 1)
            return true;

        vis[i][j] = 1;

        int num = grid[i][j];

        for (int d = 0; d < 4; d++) {

            if (arr[num][d] == 1) {

                int ni = i + x[d];
                int nj = j + y[d];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    !vis[ni][nj]) {

                    int nxt = grid[ni][nj];

                    int opp = (d + 2) % 4;

                    if (arr[nxt][opp] == 1) {

                        if (dfs(ni, nj, grid, vis))
                            return true;
                    }
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        y = {-1, 0, 1, 0};
        x = {0, -1, 0, 1};

       
        arr = {
            {0, 0, 0, 0}, 
            {1, 0, 1, 0}, // 1
            {0, 1, 0, 1}, // 2
            {1, 0, 0, 1}, // 3
            {0, 0, 1, 1}, // 4
            {1, 1, 0, 0}, // 5
            {0, 1, 1, 0}  // 6
        };

        vector<vector<int>> vis(n, vector<int>(m, 0));

        return dfs(0, 0, grid, vis);
    }
};