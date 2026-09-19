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
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL) return 1;

        int l = height(root->left);
        int r = height(root->right);

        cout << root->val << " " << l << " " << r << endl;

        if(l<0 or r<0 or abs(l-r)>1) return -1;

        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root)>=0 ? true : false;
    }
};
