class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vis(nums.size());
        vector<int> perm;
        backtrack(perm,vis,nums);
        return res;
    }
    void backtrack(vector<int> &perm, vector<int> &vis, vector<int>& nums){
        if(perm.size()==nums.size()){
            res.push_back(perm);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                perm.push_back(nums[i]);
                backtrack(perm, vis, nums);
                perm.pop_back();
                vis[i]=0;
            }
        }
    }
};
