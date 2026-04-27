class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int> &tmp, int i){
        if(i>=nums.size()){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[i]);
        backtrack(nums, tmp, i+1);
        tmp.pop_back();
        backtrack(nums, tmp, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;

        backtrack(nums,tmp, 0);
        return ans;
    }
};
