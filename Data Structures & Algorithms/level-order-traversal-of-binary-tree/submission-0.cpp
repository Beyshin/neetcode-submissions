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

    void traverse(TreeNode* node, int level, vector<vector<int>>& ans){
        if(!node) return;

        if (ans.size() == level) {
            ans.push_back(vector<int>());
        }

        ans[level].push_back(node->val);

        traverse(node->left, level+1, ans);
        traverse(node->right, level+1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root, 0, ans);
        

        return ans;
    }
};
