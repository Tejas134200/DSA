class Solution {
public:
    vector<vector<int>> g;
    bool check(int i,int j){
        int sum = g[i][j]+g[i][j+1]+g[i][j+2];
        if(g[i+1][j]+g[i+1][j+1]+g[i+1][j+2]!=sum) return false;
        if(g[i+2][j]+g[i+2][j+1]+g[i+2][j+2]!=sum) return false;
        if(g[i][j]+g[i+1][j]+g[i+2][j]!=sum) return false;
        if(g[i][j+1]+g[i+1][j+1]+g[i+2][j+1]!=sum) return false;
        if(g[i][j+2]+g[i+1][j+2]+g[i+2][j+2]!=sum) return false;
        if(g[i][j]+g[i+1][j+1]+g[i+2][j+2]!=sum) return false;
        if(g[i][j+2]+g[i+1][j+1]+g[i+2][j]!=sum) return false;
        bool a[9]={false};
        for(int ii=i;ii<i+3;ii++){
            for(int jj=j;jj<j+3;jj++){
                if(g[ii][jj]>9||g[ii][jj]<1) return false;
                if(a[g[ii][jj]-1]==true) return false;
                a[g[ii][jj]-1]=true;

            }
        }
        return true;


    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        g = grid;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;//Final Answer
        for(int i =0;i<n-2;i++){
            for(int j =0;j<m-2;j++){
                if(check(i,j)) ans++;
            }
        }
        return ans;
    }
};