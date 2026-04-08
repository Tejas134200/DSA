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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;

        q.push({root , 0});

        long long maxi = 0;
        while(!q.empty()){
            long long s=q.size();
            long long l = q.front().second;
            long long r = q.back().second;
            maxi = max(maxi , r-l+1);
            for(int i =0;i<s;i++){
                auto it = q.front();
                q.pop();
                long long idx = it.second-l;

                if(it.first->left!=nullptr){
                    q.push({it.first->left , 2*idx+1});
                }
                if(it.first->right!=nullptr){
                    q.push({it.first->right , 2*idx+2});
                }

            }
        }

        return maxi;
    }
};