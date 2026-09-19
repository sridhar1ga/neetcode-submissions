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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root!=NULL) q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> level = {};
            for(int i=0; i<n; i++)
            {
                TreeNode* top = q.front(); q.pop();
                level.push_back(top->val);

                if(top->left!=NULL) q.push(top->left);
                if(top->right!=NULL) q.push(top->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
