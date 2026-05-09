class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rem = grid[0][0]%x;
        int n = grid.size();
        int m = grid[0].size();

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]%x!=rem) return -1;
            }
        }
        vector<int> arr;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(),arr.end());
        
        int med = (n*m)%2==1?arr[(n*m-1)/2]:arr[n*m/2];

        int ans =0;
        for(int i:arr){
            int rem = abs(i-med);
            ans+=(rem/x);
        }
        return ans;




    }
};