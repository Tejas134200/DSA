class Solution {
public:
    void sort_Function(int row, int col, vector<vector<int>>& mat) {
        int i = row;
        int j = col;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> hold;
        while (i < n && j < m) {
            hold.push_back(mat[i][j]);
            i++;
            j++;
        }

        sort(hold.begin(), hold.end());

        i = row, j = col;
        for (int k = 0; k < hold.size(); k++) {
            mat[i][j] = hold[k];
            i++;
            j++;
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for (int row = 0; row < n; row++) {
            sort_Function(row, 0, mat);
        }

        for (int col = 1; col < m; col++) {
            sort_Function(0, col, mat);
        }

        return mat;
    }
};