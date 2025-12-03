class Solution {
public:

    int m,n,count;

    bool isdis(vector<vector<int>>& grid,int req){
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<int> x= {-1,0,0,1};
        vector<int> y = {0,1,-1,0};
        int c =0;
        queue<pair<int,int>> q;
       bool f=true;
        for(int i =0;i<m;i++){
            if(f){
                for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    f =false;

                    break;
                }
            }
            }
        }

        while(!q.empty()){
            int ii = q.front().first;
            int jj = q.front().second;
            q.pop();
            
            c++;
            for(int pp = 0;pp<4;pp++){
                int xx = ii+x[pp];
                int yy = jj+y[pp];
                if(xx>=0&&yy>=0&&xx<m&&yy<n&&grid[xx][yy]==1&&vis[xx][yy]==0){
                    vis[xx][yy]=1;
                    q.push({xx,yy});
                }

            }
        }
        return c!=req;
    }
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        count=0;
        for(int i =0;i<m;i++) for(int j =0;j<n;j++) if(grid[i][j]==1) count++;
        if(count==1||count==0) return count;
        if(isdis(grid,count)) return 0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(isdis(grid,count-1)) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;

    }
};