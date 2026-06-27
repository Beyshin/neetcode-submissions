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

    int dfs(TreeNode* node, int curr_depth){
        int left_depth = curr_depth;
        int right_depth = curr_depth;
        while(node){
            if(node->left) left_depth = dfs(node->left, curr_depth+1);
            if(node->right) right_depth = dfs(node->right, curr_depth+1);

            return max(left_depth, right_depth);
        }

        return 0;
    }

    int maxDepth(TreeNode* root) {
        return dfs(root, 1);
    }
};
