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
    int maxLevelSum(TreeNode* root) {
        long long sum = root->val;
        int ans = 1;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            long long tsum =0;
            int k = q.size();
            level++;
            while(k--){
                TreeNode* thisN = q.front();
                q.pop();
                tsum+=thisN->val;
                if(thisN->left!=nullptr) q.push(thisN->left);
                if(thisN->right!=nullptr) q.push(thisN->right);

            }
            if(tsum>sum){
                sum=tsum;
                ans=level;
            }
        }
        return ans;
        
    }
};