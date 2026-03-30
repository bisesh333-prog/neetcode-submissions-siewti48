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
    int ans = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return ans;
    }
    void dfs(TreeNode* root, int maxm){
        if(root->val>=maxm){
            ans++;
            maxm = root->val;
        }
        if(root->left){
            dfs(root->left, maxm);
        }
        if(root->right) dfs(root->right, maxm);
        return;
    }
};
