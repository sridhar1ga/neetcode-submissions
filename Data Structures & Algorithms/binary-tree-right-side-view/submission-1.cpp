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
        queue<TreeNode*> q;
        if(root!=NULL)q.push(root);
        vector<int> ans;
        while(!q.empty())
        {
            int l = q.size();
            for(int i=0; i<l; i++)
            {
                TreeNode* node = q.front(); q.pop();

                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);

                if(i==l-1) ans.push_back(node->val);
            }
        }

    return ans;
    }
};
