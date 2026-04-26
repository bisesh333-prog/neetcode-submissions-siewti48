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
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){
        if(!root)return 0;
        int lmax=dfs(root->left);
        if (lmax<0) lmax=0;
        int rmax=dfs(root->right);
        if (rmax<0) rmax=0;
        ans=max(ans,root->val+lmax+rmax);
        return root->val+max(lmax,rmax);
    }
};
