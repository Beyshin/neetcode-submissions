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

    void invert(TreeNode* node){
        while(node){
            if(node->left == nullptr && node->right == nullptr) break;

            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            if(node->left != nullptr) invert(node->left);
            if(node->right != nullptr) invert(node->right);
            return;
        }
    }


    TreeNode* invertTree(TreeNode* root) {
        TreeNode* node = root;
        invert(node);

        return root;
    }
};
