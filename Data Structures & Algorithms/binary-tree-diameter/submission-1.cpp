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
    int maxi=0;
    int traverse(TreeNode* root)
    {
        if(root==NULL) return 0;

        int l = traverse(root->left);
        int r = traverse(root->right);
        maxi = max(maxi, l+r+1);

        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return maxi-1;
    }
};
