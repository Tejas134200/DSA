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
    long long mod;
long long maxi;
    long long ss;
    long long inorder(TreeNode* root){
        if(!root) return 0;
        return inorder(root->left)+root->val+inorder(root->right);
    }
    long long dfs(TreeNode* cur){
        if(!cur) return 0;
        long long lsum = dfs(cur->left);
        long long rsum = dfs(cur->right);
        long long kk = lsum+rsum+cur->val;
        maxi = max(maxi , ((ss-kk)*kk));
        return kk;
        
    }
    int maxProduct(TreeNode* root) {
        mod=1e9+7;
        maxi=0;
        long long sum =  inorder(root);
        ss=sum;
        dfs(root);
        return maxi%mod;


    }
};