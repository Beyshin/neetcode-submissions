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
    void dfs(TreeNode* node, int& counter, int k, int& ans){
        if(node->left) dfs(node->left, counter, k, ans);
        if(++counter == k){
            ans = node->val;
            return;
        }
        if(node->right) dfs(node->right, counter, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int ans = 0;
        dfs(root, counter, k, ans);

        return ans;
    }
};
