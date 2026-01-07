//optimal
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
private:
    TreeNode* Helper(vector<int>& preorder, int bound, int& idx){
  
        if(idx == preorder.size() || preorder[idx] > bound)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[idx++]);
        node->left = Helper(preorder, node->val, idx);
        node->right = Helper(preorder, bound, idx);

        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return Helper(preorder, INT_MAX, idx);
    }
};