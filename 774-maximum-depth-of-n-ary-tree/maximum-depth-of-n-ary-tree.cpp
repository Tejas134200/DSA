/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int func(Node* root){
        if(!root) return 0;

        int maxi =0;
        for(auto i:root->children){
            maxi = max(maxi , func(i));
        }
        return 1+maxi;
    }
    int maxDepth(Node* root) {
        return func(root);
    }
};