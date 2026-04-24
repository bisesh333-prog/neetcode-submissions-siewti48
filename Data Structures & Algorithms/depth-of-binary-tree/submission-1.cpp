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
    int ans=0;
    int maxDepth(TreeNode* root) {
        depth(root,0);
        return ans;
    }
    void depth(TreeNode* root, int h){
        if(!root){
            ans=max(ans,h);
            return;
        }
        depth(root->left,h+1);
        depth(root->right,h+1);
        return;
    }
};
