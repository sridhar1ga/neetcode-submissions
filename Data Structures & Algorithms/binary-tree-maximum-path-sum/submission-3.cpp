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
    int ans = INT_MIN;
    int maxPathSum1(TreeNode* root) {
        if(root==NULL) return 0;

        int lsum = maxPathSum1(root->left);
        int rsum = maxPathSum1(root->right);
        ans = max(ans, lsum+rsum+root->val);

        return max(0, max(lsum,rsum)+root->val);
    }

    int maxPathSum(TreeNode* root) {
        maxPathSum1(root);

        return ans;
    }

};
