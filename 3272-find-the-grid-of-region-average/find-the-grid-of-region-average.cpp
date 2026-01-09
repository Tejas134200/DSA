class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& img, int threshold) {
    int n = img.size(), m = img[0].size(), reg[501][501][2] = {};
    for (int i = 0; i < n - 2; ++i)
        for (int j = 0; j < m - 2; ++j) {
            int sum = 0, is_region = true;
            for (int k = i; k < i + 3; ++k)
                for (int l = j; l < j + 3; ++l) {
                    sum += img[k][l];
                    is_region &= k == i || abs(img[k][l] - img[k - 1][l]) <= threshold;
                    is_region &= l == j || abs(img[k][l] - img[k][l - 1]) <= threshold;
                }
            if (is_region)
                for (int k = i; k < i + 3; ++k)
                    for (int l = j; l < j + 3; ++l) {
                        reg[k][l][0] += sum / 9;
                        reg[k][l][1] += 1;
                    }
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (reg[i][j][1])
                img[i][j] = reg[i][j][0] / reg[i][j][1];
    return img;
}
};