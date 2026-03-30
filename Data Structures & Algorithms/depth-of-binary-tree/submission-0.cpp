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
    int hmax = INT_MIN;
    int maxDepth(TreeNode* root) {
        height(root, 0);
        return hmax;
    }
    void height(TreeNode* root, int h){
        if(!root){
            hmax = max(hmax,h);
            return;
        }
        height(root->left, h+1);
        height(root->right, h+1);
        return;
    }
};
