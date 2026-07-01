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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;

        if(root == nullptr) return ans;
        
        q.push(root);

        while(!q.empty()){
            int level_size = q.size();
            vector<int> current_level;

            for(size_t i{}; i<level_size; i++){
                 TreeNode* node = q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                current_level.push_back(node->val);
            }

            ans.push_back(current_level.back());
        }

        return ans;
    }
};
