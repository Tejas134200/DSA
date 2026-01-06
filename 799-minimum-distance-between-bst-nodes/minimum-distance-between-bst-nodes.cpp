class Solution {
public:
    int prev = -1;
    int ans = INT_MAX;

    void find(TreeNode* cur) {
        if(!cur) return;

        find(cur->left);

        if(prev != -1)
            ans = min(ans, cur->val - prev);

        prev = cur->val;

        find(cur->right);
    }

    int minDiffInBST(TreeNode* root) {
        find(root);
        return ans;
    }
};
