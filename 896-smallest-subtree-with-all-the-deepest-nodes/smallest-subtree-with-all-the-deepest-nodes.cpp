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
    int getdepth(TreeNode* node){
        if(!node) return 0;
        return 1+max(getdepth(node->left),getdepth(node->right));
    }
    TreeNode* findc(TreeNode* node){
        int l = getdepth(node->left);
        int r = getdepth(node->right);
        if(l==r){
            return node;
        }else if(l>r){
            return findc(node->left);
        }else return findc(node->right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans = root;
        return findc(ans);
        return ans;

    }
};