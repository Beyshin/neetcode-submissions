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
    int d = 0;
public:
    
    int dfs(TreeNode* node){
        if(!node) return 0;

        int left_h = dfs(node->left);
        int right_h = dfs(node->right);

        d = max(d, left_h + right_h);

        return 1 + max(left_h, right_h);

    }


    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return d;
    }
};
