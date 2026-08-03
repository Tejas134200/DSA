class Solution {
public:
    int ans = 0;

    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {-1, -1};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int goLeft = left.second + 1;
        int goRight = right.first + 1;

        ans = max({ans, goLeft, goRight});

        return {goLeft, goRight};
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};