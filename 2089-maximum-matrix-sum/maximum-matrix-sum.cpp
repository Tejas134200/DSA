class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int n = matrix.size();
        long long mini = INT_MAX;
        int c =0;
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    c++;
                }
                mini=min(mini,(long long)abs(matrix[i][j]));
            }
        }
        if(c%2==0) return sum;
        return sum-2*mini;

    }
};