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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int &res){
        if(!root) return 0;
        int lv = helper(root->left, res);
        int rv = helper(root->right, res);
        if(lv<0&&rv<0){
            res = max(res, root->val);
        }
        else if(lv<0){
            res = max(res, root->val+rv);
        }
        else if(rv<0){
            res = max(res, root->val+lv);
        }
        else{
            res = max(res, root->val+lv+rv);
        }
        
        return root->val + max(0, max(lv,rv));
    }
};
