/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;

    int ps(TreeNode* node){
        if(!node) return INT_MIN;

        int le = ps(node->left);
        int ri = ps(node->right);

        if(le<0) le=0;
        if(ri<0) ri=0;
        ans = max(le+ri+node->val , ans);
        return node->val+max(le,ri);
    }
    int maxPathSum(TreeNode* root) {
        ans =INT_MIN;
        ps(root);
        return ans;

    }
};