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

class Codec {
public:
    void dfs(TreeNode* root, vector<string> &ans){
        if(!root){
            ans.push_back("*");
            return;
        }
        ans.push_back(to_string(root->val));
        dfs(root->left, ans);
        dfs(root->right, ans);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> ans;
        dfs(root,ans);
        return join(ans,",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data,',');
        int i=0;
        return dfsDeserialize(vals,i);
    }

    TreeNode* dfsDeserialize(vector<string> &vals, int &i){
        if(vals[i]=="*"){
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeserialize(vals,i);
        node->right = dfsDeserialize(vals,i);
        return node;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join(const vector<string> &v, const string &delim) {
        ostringstream s;
        for (const auto &i : v) {
            if (&i != &v[0])
                s << delim;
            s << i;
        }
        return s.str();
    }
};
