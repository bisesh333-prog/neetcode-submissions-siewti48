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
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    int dfs(TreeNode* root, int h){
        if(!root) return 0;
        int lh = dfs(root->left,h+1);
        int rh = dfs(root->right, h+1);
        if(abs(lh-rh)>1){
            ans = false;
        }
        return 1+max(lh,rh);
    }
};
