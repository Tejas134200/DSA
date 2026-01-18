class Solution {
public:
    int n;
    vector<vector<pair<int,int>>> dum;
    int maxi;

    void bfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int& ui) {

        vector<int> xd = {-1, 1, 0, 0};
        vector<int> yd = {0, 0, 1, -1};

        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        int c = 0;
        vector<pair<int,int>> vp;

        while(!q.empty()){
            int qs = q.size();
            
            while(qs--){
                c++;
                int tx = q.front().first;
                int ty = q.front().second;
                q.pop();

                vp.push_back({tx, ty});

                for(int k = 0; k < 4; k++){
                    int x = tx + xd[k];
                    int y = ty + yd[k];
                    if(x >= 0 && x < n && y >= 0 && y < n &&
                       grid[x][y] == 1 && vis[x][y] == 0){
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }
        maxi = max(maxi , c);

        for(auto& it : vp){
            dum[it.first][it.second] = {c, ui};
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        dum.resize(n, vector<pair<int,int>>(n));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        maxi = 0;

        int ui = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    bfs(i, j, grid, vis, ui);
                    ui++;
                }
            }
        }

        vector<int> xd = {-1, 1, 0, 0};
        vector<int> yd = {0, 0, 1, -1};

        

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    vector<int> track;
                    vector<int> bbbbb;

                    for(int ii = 0; ii < 4; ii++){
                        int x = i + xd[ii];
                        int y = j + yd[ii];

                        if(x >= 0 && x < n && y >= 0 && y < n &&grid[x][y]==1){
                            int hg = dum[x][y].second;
                            if(find(track.begin(), track.end(), hg) == track.end()){
                                track.push_back(hg);
                                bbbbb.push_back(dum[x][y].first);
                            }
                        }
                    }

                    int sum = 1;
                    for(int val : bbbbb) sum += val;


                    maxi = max(maxi, sum);
                }
            }
        }
        return maxi;
    }
};
