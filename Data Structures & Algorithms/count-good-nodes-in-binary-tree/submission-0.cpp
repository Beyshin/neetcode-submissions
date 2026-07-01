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
    void dfs(TreeNode* node, int max_num, int& counter){
        if(node == nullptr) return;

        if(node->val >= max_num) counter++;

        int new_max = max(max_num, node->val);

        if(node->left) dfs(node->left, new_max, counter);
        if(node->right) dfs(node->right, new_max, counter);

    }

    int goodNodes(TreeNode* root) {
        int counter = 0;
        dfs(root, -101, counter);

        return counter;
    }
};
