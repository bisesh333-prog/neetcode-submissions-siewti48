class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int i=0;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        backtrack(nums, i, tmp, target);
        return ans;
    }
    void backtrack(vector<int>& nums, int i, vector<int> &tmp, int target){
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        if(i==nums.size()||target<0) return;

        tmp.push_back(nums[i]);
        backtrack(nums,i+1,tmp, target-nums[i]);
        tmp.pop_back();
        while(i+1<nums.size()&&nums[i+1]==nums[i]) i++;
        backtrack(nums, i+1, tmp, target);
    }
};
