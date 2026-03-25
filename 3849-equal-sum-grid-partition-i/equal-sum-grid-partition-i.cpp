class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> h(m,0),v(n,0);
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                v[i]+=grid[i][j];
                h[j]+=grid[i][j];
            }
        }
        long long sum=0;
        for(long long i:h) sum+=i;
        long long x =0;
        for(long long i:h){
            x+=i;
            sum-=i;
            if(x==sum) return true;
        }
        sum =0;
        for(long long i:v) sum+=i;
        x =0;
        for(long long i:v){
            x+=i;
            sum-=i;
            if(sum==x){
                return true;
            }
        }
        return false;
    }
};