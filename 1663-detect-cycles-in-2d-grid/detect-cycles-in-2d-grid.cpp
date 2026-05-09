class Solution {
public:
    int n , m;
    vector<vector<int>> vis;
    vector<int> x , y;
    bool dfs(int i , int j , vector<vector<char>>& grid , char c , int px , int py){
        if(vis[i][j]==1) return true;
        vis[i][j]=1;
        bool aa=false;
        for(int it=0;it<4;it++){
            int xx = i+x[it];
            int yy = j+y[it];

            if(xx<n&&xx>=0&&yy<m&&yy>=0){
                if((xx!=px||yy!=py)&&grid[xx][yy]==c){
                    aa = aa||dfs(xx , yy , grid , c , i , j);
                }
            }
        }
        return aa;
    }
    bool containsCycle(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();
         x = {0 , 0 , 1 , -1};
         y = {-1 , 1 , 0 , 0};

        vis.resize(n,vector<int>(m,0));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i , j , grid , grid[i][j] , -1 ,-1)) return true;
                }
            }
        }

        return false;
    }
};